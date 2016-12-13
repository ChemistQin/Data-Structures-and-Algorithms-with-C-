//
//  main.cpp
//  Container
//
//  Created by 覃思平 on 2016/12/9.
//  Copyright © 2016年 覃思平. All rights reserved.
//
//vector 可变大小数组。支持快速随机访问。在尾部之外的位置插入或删除元素可能很慢
//deque 双端队列。支持快速随机访问。在头尾位置插入/删除速度很快
//list 双向链表
//forward_list 单向链表
//array 固定大小数组。支持快速随机访问。不能添加或删除元素
//string 与vector相似的容器。专门用于保存字符
//

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <array>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    
    list<string> a = {"Naive" , "Angry" , "Excited"};
 
    
    vector<int> v1 = { 1, 3, 5, 7, 9, 12 };
    vector<int> v2 = { 1, 3, 9 };
    vector<int> v3 = { 1, 3, 5, 7 };
    vector<int> v4 = { 1, 3, 5, 7, 9, 12 };
    
    bool b1 = (v1 == v2);
    bool b2 = (v1 == v4);
    bool b3 = (v4 > v3);
    cout << b1 << b2 << b3 <<endl;
/*
    string word;
    cout << "\n 输入字符串 ctrl + d 结束 \n";
    while(cin >> word)
        a.push_back(word);
    
    
    for(auto s : a)
        cout << s <<" " ;
*/
    list<int> lst = {0,1,2,3,4,5,6,7,8,9};
    auto it = lst.begin();
    while (it != lst.end())
        if (*it % 2) // if the element is odd
            it = lst.erase(it); // erase this element
        else
            ++it;
    for(auto i : lst)
        cout << i <<" ";
    
    
    return 0;
}
