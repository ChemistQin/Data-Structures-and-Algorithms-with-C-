//
//  StrBlob.h
//  DynamicMemory
//
//  Created by 覃思平 on 2016/12/14.
//  Copyright © 2016年 覃思平. All rights reserved.
//

#ifndef StrBlob_h
#define StrBlob_h
#include <vector>

using namespace std;

class StrBlob{
    
public:
    typedef vector<string>::size_type size_type;
    
    StrBlob();
    StrBlob(initializer_list<string> il);
    
    size_type size() const;
    bool empty() const;// add and remove elements
    void push_back(const string &t);
    void pop_back(); // element access
    string& front();
    string& back(); private:
    shared_ptr<vector<string>> data;// throws msg if data[i] isn't valid
    
    void check(size_type i, const string &msg) const;
};

StrBlob::size_type StrBlob::size() const{
    return data->size();
}

bool StrBlob::empty() const{
    return data->empty();
}

void StrBlob::push_back(const string &t){
    data->push_back(t);
}

void StrBlob::check(size_type i, const string &msg) const{
    if(i >= data->size())
        throw out_of_range(msg);
}

string& StrBlob::front(){
    check(0, "vector为空");
    return data->front();
}

string& StrBlob::back(){
    check(0, "vector为空");
    return data->back();
}

void StrBlob::pop_back(){
    check(0, "vector为空");
    data->pop_back();
}



#endif /* StrBlob_h */
