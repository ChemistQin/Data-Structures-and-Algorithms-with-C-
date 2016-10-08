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
    
    stack.Push(30);
    stack.Push(40);
    stack.Push(60);
    std::cout<<"Top:"<<stack.Top()<<std::endl;
    
    stack.Pop();
    std::cout<<"Top:"<<stack.Top()<<std::endl;

    stack.Pop();
    stack.Pop();
    std::cout<<"Top:"<<stack.Top()<<std::endl;
    
    return 0;
}
