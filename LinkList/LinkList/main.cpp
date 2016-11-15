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
    
    pdlink->Insert(0, 2);        // 将 20 插入到第一个位置
    pdlink->AppendLast(128);    // 将 10 追加到链表末尾
    pdlink->InsertFirst(256);    // 将 30 插入到第一个位置
    pdlink->Insert(1, 1024);
    
    // 双向链表是否为空
    cout << "is_empty()=" << pdlink->IsEmpty() <<endl;
    // 双向链表的大小
    cout << "size()=" << pdlink->Size() <<endl;
    
    // 打印双向链表中的全部数据
    pdlink->PrintList();
    return 0;

}
