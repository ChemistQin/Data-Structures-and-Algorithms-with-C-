//
//  main.cpp
//  Sort
//
//  Created by 覃思平 on 2016/10/9.
//  Copyright © 2016年 覃思平. All rights reserved.
//  编译时，应声明  -std = c++11 ，否则会报错

#include <iostream>
#include <vector>
#include "Sort.h"


using namespace std;

int main() {
    vector<int> vec = {0,8,4,64,32,256,128,1024,512,2,1};//此处vector为c++11用法，编译时须声明
    ShellSort(vec);                                     
    for(auto v : vec)
        cout << v << endl;
    return 0;
}
