//
//  main.cpp
//  Stack
//
//  Created by 覃思平 on 2016/9/28.
//  Copyright © 2016年 覃思平. All rights reserved.
//

#include<iostream>
#include"stack.h"
using namespace std;

int main()
{
    Stack <int> stack;
    for (int i = 0; i < 5; ++i)
    {
    	stack.Push(i);
    }
    
    cout << stack.Top() <<endl;
    stack.Pop();
    stack.PrintStack();
    return 0;
}
