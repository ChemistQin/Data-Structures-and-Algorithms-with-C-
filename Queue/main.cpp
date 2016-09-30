//
//  main.cpp
//  Queue
//
//  Created by 覃思平 on 2016/9/29.
//  Copyright © 2016年 覃思平. All rights reserved.
//

#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
    int tmp=0;
    Queue<int> *queue = new Queue<int>();
    
    queue->add(2);
    queue->add(4);
    queue->add(8); //入队
    
    
    tmp = queue->pop(); //出队
    cout<<"出队元素："<<tmp<<endl;
    
    
    tmp = queue->front();
    cout<<"队列头前元素为："<<tmp<<endl; //显示当前队头
    
    queue->add(16);
    
    cout<<"队列是为空？"<<queue->isEmpty()<<endl;
    cout<<"当前元素个数："<<queue->size()<<endl;
    
    queue->show();
    
    return 0;
}
