//
//  main.cpp
//  LinkList
//
//  Created by 覃思平 on 2016/11/15.
//  Copyright © 2016年 覃思平. All rights reserved.
//

#include <iostream>
#include <vector>
#include "LinkList.h"

using namespace std;




int main()
{
    
    // 创建双向链表
    DoubleLink<int>* pdlink = new DoubleLink<int>();
    
    pdlink->Insert(0, 2);
    pdlink->AppendLast(128);
    pdlink->InsertFirst(256);
    pdlink->Insert(1, 1024);
    
    pdlink->Get(6);
    cout << "2nd:" << pdlink->Get(2) << endl;
    // 双向链表是否为空
    cout << "The linklist is empty? " << pdlink->IsEmpty() <<endl;
    // 双向链表的大小
    cout << "Size of linklist is " << pdlink->Size() <<endl;
    
    // 遍历链表
    pdlink->PrintList();
    return 0;

}
