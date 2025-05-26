//
// Created by Azusa_Ke on 25-5-13.
//

#include "console_adaption.h"

#include "notebasic.h"
#include "passwordmanager.h"
#include "financenote.h"
#include "formatcheck.h"
#include "SHA_256.h"
#include <iostream>
#include <cmath>

passwordmanager::passwordmanager() {
    passwordmanager::load_from_file();
    if (is_graphic){
        cout << "密码管理器构造成功！" << endl;
    }
}

passwordmanager::~passwordmanager() {
    passwordmanager::close();
    if (is_graphic){
        cout << "密码管理器析构成功！" << endl;
    }
}

//逻辑部分--------------------------------------------------------------------------------------------------------------------

//is_new_user用于判断是否为新用户，如果是则需要创建密码凭据，否则需要验证密码凭据。
bool passwordmanager::is_new_user_flag() const {
    return is_new_user;
}
;

//文件加载函数-复用自记账本
void passwordmanager::load_from_file() {
    entries.clear();
    is_new_user = false;
    ifstream file(file_path);
    if (!file.is_open()) {
        cerr << "无法打开目标文件：" << file_path << "，即将自动创建新文件" << endl;
        ofstream createFile(file_path);
        if (!createFile.is_open()) {
            cerr << "无法创建文件：" << file_path << "，请检查数据文件夹是否损坏" << endl;
            system_pause();
            return;
        }
        createFile.close();
    }
    if (file.peek() == ifstream::traits_type::eof()) {
        is_new_user = true;//检测是否为新用户
        return;
    }

    string line;
    if (getline(file, line)) {
        if (line == "") {
            is_new_user = true;
        }else {
            correct_key_sha_256 = line;
        }
    }
    while (getline(file, line)) {
        stringstream ss(line);
        record temp;
        ss >> temp.site_name >> temp.username >> temp.password;
        if (!temp.site_name.empty()) {
            entries.push_back(temp);
        }
    }
    file.close();
    if (is_graphic){
        cout << "已读取文件：" << passwordmanager::file_path << endl;
    }
}
//文件写入函数-复用自记账本
void passwordmanager::save_to_file() {
    ofstream file(file_path);
    if (!file.is_open()) {
        cerr << "无法修改目标文件：" << file_path << "，即将自动创建新文件" << endl;
        ofstream createFile(file_path);
        if (!createFile.is_open()) {
            cerr << "无法创建文件：" << file_path << "，请检查数据文件夹是否损坏" << endl;
            system_pause();
            return;
        }
        createFile.close();
    }

    file << correct_key_sha_256 << endl;
    for (const auto& temp : entries) {
        file << temp.site_name << " " << temp.username << " " << temp.password << endl;
    }
    file.close();
    if (is_graphic){
        cout << "已写入文件：" << passwordmanager::file_path << endl;;
    }
}

//搜索函数
void passwordmanager::search(const string &site_name) {
    //内建相似度计算函数，用于辅助搜索，输入被比较字符串，输出双精度浮点数用于评判两字符串是否相似
    auto calculate_similarity = [](const string &a, const string &b) -> double {
        //检测是否有共有的字母，没有相似度直接判零
        bool has_common_char = false;
        for (char c : a) {
            if (b.find(c) != string::npos) {
                has_common_char = true;
                break;
            }
        }

        // 如果没有共有的字母，直接返回相似度为零
        if (!has_common_char) {
            return 0.0;
        }

        int len_a = a.size(), len_b = b.size();//获取字符串长度
        vector<vector<int> > dp(len_a + 1, vector<int>(len_b + 1, 0));
        for (int i = 0; i <= len_a; ++i) dp[i][0] = i;
        for (int j = 0; j <= len_b; ++j) dp[0][j] = j;
        for (int i = 1; i <= len_a; ++i) {
            for (int j = 1; j <= len_b; ++j) {
                dp[i][j] = min({
                    dp[i - 1][j] + 1, dp[i][j - 1] + 1,
                    dp[i - 1][j - 1] + (tolower(a[i - 1]) == tolower(b[j - 1]) ? 0 : 1)
                });
            }
        }
        return 1.0 / (1.0 + dp[len_a][len_b]);
    };
    search_result.clear();
    //对于每一个记录，计算相似度，将相似的记录加入搜索结果
    for (const auto &entry: entries) {
        double similarity = calculate_similarity(entry.site_name, site_name);
        if (similarity > 0.0) {
            //仅仅加入存在相似度的结果
            search_result.push_back({entry.site_name, entry.username, entry.password, similarity});
        }
    }

    //依照相似度对搜索表排序，并在相似度相同时按字典序排序，合并完全相同的条目
    std::sort(search_result.begin(), search_result.end(), [](const search_record &a, const search_record &b) {
        if (fabs(a.similarity - b.similarity) < 1e-9) {
            //如果相似度相差过小看作相同，进行字典排序
            if (a.site_name != b.site_name) return a.site_name < b.site_name;//根据 网站名
            if (a.username != b.username) return a.username < b.username;//        用户名
            if (a.password != b.password) return a.password < b.password;//        密码  依次排序
            // 对于完全相同的记录不做调整
            return false;
        }
        return a.similarity > b.similarity;
    });
    if (is_graphic){
        cout << "[ " << site_name << " ]搜索已完成！" << endl;
    }
}

//加密函数

string passwordmanager::encoder(const string &this_password) {
    string encrypted_password = this_password;
    for (size_t i = 0; i < encrypted_password.size(); ++i) {
        encrypted_password[i] ^= key[i % key.size()];
    }
    if (is_graphic){
        cout << "密码已加密为：" << encrypted_password;
    }
    return encrypted_password;
}

//解密函数
string passwordmanager::decoder(const string &this_password) {
    string decrypted_password = this_password;
    for (size_t i = 0; i < decrypted_password.size(); ++i) {
        decrypted_password[i] ^= key[i % key.size()];
    }
    if (is_graphic){
        cout << this_password << "已解密。" << endl;
    }
    return decrypted_password;
}
//检测密码是否已经存在
bool passwordmanager::is_already_exist(const string &site_name, const string &username, const string &password) {
    for (const auto &entry: entries) {
        if (entry.site_name == site_name && entry.username == username && entry.password == password) {
            if (is_graphic){
                cout << "记录已存在！" << endl;
            }
            return true;
        }
    }
    return false;
}


//记录添加函数
void passwordmanager::add_entry(const string &site_name, const string &username, const string &password) {
    entries.push_back({site_name, username, password});
    passwordmanager::save_to_file();
    if (is_graphic){
        cout << "记录已添加！" << endl;
    }
}

//关闭函数，避免错误保存
void passwordmanager::close() {
    passwordmanager::save_to_file();
    if (is_graphic){
        cout << "已关闭这个密码管理器实例！" << endl;
    }
}

//排序函数
void passwordmanager::sort() {
    std::sort(search_result.begin(), search_result.end(), [](const search_record &a, const search_record &b) {
        return a.similarity > b.similarity;
    });
    if (is_graphic){
        cout << "记录已排序" << endl;
    }
}

//运算符重载，用于将不同类型的值先呵护转化
vector<passwordmanager::search_record> passwordmanager::operator=(const vector<record> & entries) {
    vector<search_record> result;
    for (const auto &entry : entries) {
        result.push_back({entry.site_name, entry.username, entry.password, 1.0});
    }
    if (is_graphic){
        cout << "已将record向量组转化为search_record类型！" << endl;
    }
    return result;
}

bool passwordmanager::is_correct_key(const string &tested_key) {
    if (is_graphic) {
        cout <<"正在校验凭据..." << endl;
    }
    if (!is_new_user) {
        if (is_graphic){
            cout << "凭证已校验:" << (tested_key == correct_key_sha_256 ? "已通过！" : "未通过...") << endl;
        }
        return tested_key == correct_key_sha_256;
    }else {
        cerr << "当前为新用户，无法验证凭据！" << endl;
        return false;
    }

}

/*void passwordmanager::set_key(const string& k) {
    key = k;
}*/

//逻辑交互部分结束-----------------------------------------------------------------------------------------------------------
//命令行交互部分---------------------------------------------------------------------------------------------------------------
void passwordmanager::display(const string &site_name) {
    system_clear();
    if (site_name.empty()) {
        cout << "[全部密码记录]" << endl;
        search_result = *this = entries;
        passwordmanager::sort();
    } else {
        cout << "[" << site_name << "搜索结果]" << endl;
        passwordmanager::search(site_name);
    }
    cout << left << setw(31) << "网站名"
         << setw(25) << "| 用户名"
         << setw(15) << "| 密码" << endl;
    cout << string(55, '-') << endl;

    for (const auto &temp: search_result) {
        //添加中文字符支持，避免显示错位
        auto pad = [](const std::string& s, int width) {
            int w = 0;
            for (size_t i = 0; i < s.size(); ) {
                unsigned char c = s[i];
                if (c >= 0x80) { w += 2; i += (c >= 0xE0 ? 3 : 2); } // 粗略判断UTF-8中文宽度
                else { w += 1; ++i; }
            }
            std::cout << s;
            for (int i = w; i < width; ++i) std::cout << ' ';
        };
        pad(temp.site_name, 28);
        cout << "| ";
        pad(temp.username, 20);
        cout << "| ";
        pad(decoder(temp.password), 15);
        cout << endl;
    }
    if (search_result.empty()) {
        cout << "似乎当前没有满足条件的密码记录..." << endl;
    }
    if (!site_name.empty()) {
        cout << "回车以回到密码管理器主页：" << endl;
        system_pause();
    }
}

//初始化函数
void passwordmanager::init() {
    string temp_key;
    passwordmanager::load_from_file();
    do {
        if (is_new_user) {
            cout << "欢迎使用密码管理器！" << endl;
            cout << "请创建你用于登录密码管理系统的总密码，" << endl << "注意，此密码是你用于查看密码记录的唯一凭据，请勿丢失！" << endl << "一旦丢失不可恢复，需删除旧的密码记录！" << endl;
            cout << "输入密码凭据：" << endl;
            key = system_get_hidden_input();
            correct_key_sha_256 = SHA256::sha_256(key);
            passwordmanager::save_to_file();
            cout << endl << "你的密码凭据已创建并保存，请牢记！回车以进入密码管理器！" << endl;
            system_pause();
            is_new_user = false;
        }else {
            cout << "请输入你的加密密钥以访问密码管理器：" << endl;
            key = system_get_hidden_input();

        }
        system_clear();
        temp_key = SHA256::sha_256(key);
        if (!is_correct_key(temp_key)) {
            cerr << "密码错误！请重新输入！" << endl;
        }
    }while (!is_correct_key(temp_key));
    while (true) {
        passwordmanager::display("");
        cout << "请选择你希望的操作：" << endl << "1.添加密码" << endl << "2.按网站名筛选密码并输出" << endl << "选择数字并按下回车(为0则退出)：" << endl;
        int choice;
        cin >> choice;
        system_clear();
        if (choice == 1) {
            string site_name;
            string username;
            string password;
            cout << "请输入网站名（形如www.google.com）：" << endl;
            cin >> site_name;
            system_clear();
            cout << "请输入用户名（形如user123,请勿夹杂空格）：" << endl;
            cin >> username;
            system_clear();
            cout << "请输入密码（形如password123,请勿夹杂空格）：" << endl;
            cin >> password;
            password = encoder(password);
            if (passwordmanager::is_already_exist(site_name, username, password)) {
                cout << "该记录已经存在！" << endl;
                system_pause();
            } else {
                passwordmanager::add_entry(site_name, username, password);
            }
        }else if (choice == 2) {
            string search_site_name;
            cout << "请输入需要搜索的网站名（形如www.google.com）：" << endl;
            cin >> search_site_name;
            system_clear();
            passwordmanager::display(search_site_name);
        }else {
            break;
        }
    }passwordmanager::close();
}