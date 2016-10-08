//
//  main.cpp
//  Stack
//
//  Created by 覃思平 on 2016/9/28.
//  Copyright © 2016年 覃思平. All rights reserved.
//

#include<iostream>
#include"stack.h"


int main()
{
    Stack stack;
    
    stack.Push(8);
    stack.Push(16);
    stack.Push(32);
    std::cout<<"Top:"<<stack.Top()<<std::endl;
    
    stack.Pop();
    std::cout<<"Top:"<<stack.Top()<<std::endl;

    stack.Show();
    
    return 0;
}
