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
      Queue <int> queue;
    for (int i = 0; i < 5; ++i)
    {
        queue.Push(i);
    }
    
    cout << queue.Top() <<endl;
    queue.Pop();
    queue.PrintQueue();
    return 0;
}
