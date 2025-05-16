//
// Created by Azusa_Ke on 25-5-13.
//

#ifndef NOTEBASIC_H
#define NOTEBASIC_H

#include<string>

using namespace std;

class notebasic {
public:
    virtual void load_from_file(const string& filepath) = 0;
    virtual void save_to_file(const string& filepath) = 0;
    virtual void display(const string &) = 0;
    virtual void search(const string &) = 0;
    virtual void sort() = 0;
    //virtual string get_type() const = 0;
    virtual void init() = 0;
    virtual void close() = 0;
    virtual ~notebasic() = default;
};
//考虑进一步将相似逻辑抽象出来，在基类直接写出来

#endif //NOTEBASIC_H
