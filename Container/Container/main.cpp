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
    auto t1 = a.begin();
    return 0;
}
