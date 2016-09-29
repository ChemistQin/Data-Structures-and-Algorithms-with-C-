//
//  stack.h
//  Stack
//
//  Created by 覃思平 on 2016/9/28.
//  Copyright © 2016年 覃思平. All rights reserved.
//

#ifndef stack_h
#define stack_h
#define MaxSize 100 //the stack could contain 100 elements

class Stack {
    
private:
    int data[MaxSize];
    int size;
    
public:
    Stack() {       // 构造函数 Constructor
        size = 0;
    }
    
    ~Stack() { }    // 析构函数 Destructor
    
    int Top() {
        
        if (size == 0) {
            std::cout<<"Error: stack empty 空栈\n";
            return -1;
        }
        return data[size-1];
    }
    
    void Push(int d) { //push a element onto the stack
        
        if (size < MaxSize)
            data[size++] = d;
        else
            std::cout<<"Error: stack full 满栈\n";
    }
    
    void Pop() { //pop the element from the stack
        
        if (size == 0)
            std::cout<<"Error: stack empty 空栈\n";
        else
            size--;
    }
};


#endif
