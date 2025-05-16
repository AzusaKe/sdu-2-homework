//
// Created by Azusa_Ke on 25-5-13.
//

#include "console_adaption.h"

#include "notebasic.h"
#include "passwordmanager.h"
#include "financenote.h"
#include "formatcheck.h"
#include <iostream>
#include <cmath>


#define AES_BLOCK_SIZE 128
//逻辑部分--------------------------------------------------------------------------------------------------------------------
//文件加载函数-复用自记账本
void passwordmanager::load_from_file(const string &filepath) {
    entries.clear();
    ifstream file(filepath);
    if (!file.is_open()) {
        cerr << "无法打开目标文件：" << filepath << "，即将自动创建新文件" << endl;
        ofstream createFile(filepath);
        if (!createFile.is_open()) {
            cerr << "无法创建文件：" << filepath << "，请检查数据文件夹是否损坏" << endl;
            system_pause();
            return;
        }
        createFile.close();
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        record temp;
        ss >> temp.site_name >> temp.username >> temp.password;
        if (!temp.site_name.empty()) {
            entries.push_back(temp);
        }
    }
    file.close();
}
//文件写入函数
void passwordmanager::save_to_file(const string &filepath) {
    ofstream file(filepath);
    if (!file.is_open()) {
        cerr << "无法修改目标文件：" << filepath << "，即将自动创建新文件" << endl;
        ofstream createFile(filepath);
        if (!createFile.is_open()) {
            cerr << "无法创建文件：" << filepath << "，请检查数据文件夹是否损坏" << endl;
            system_pause();
            return;
        }
        createFile.close();
    }

    for (const auto& temp : entries) {
        file << temp.site_name << " " << temp.username << " " << temp.password << endl;
    }
    file.close();
}

//搜索函数
void passwordmanager::search(const string &site_name) {
    //内建相似度计算函数，用于辅助搜索
    auto calculate_similarity = [](const string &a, const string &b) -> double {
        int len_a = a.size(), len_b = b.size();
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
}

//加密函数


string passwordmanager::encoder(const string &this_password) {
    string encrypted_password = this_password;
    for (size_t i = 0; i < encrypted_password.size(); ++i) {
        encrypted_password[i] ^= key[i % key.size()];
    }
    return encrypted_password;
}


//记录添加函数
void passwordmanager::add_entry(const string &site_name, const string &username, const string &password) {
    entries.push_back({site_name, username, password});
    passwordmanager::save_to_file("./data/password.txt");
}

//关闭函数，避免错误保存
void passwordmanager::close() {
    passwordmanager::save_to_file("./data/password.txt");
}

//排序函数
void passwordmanager::sort() {
    std::sort(search_result.begin(), search_result.end(), [](const search_record &a, const search_record &b) {
        return a.similarity > b.similarity;
    });
}