//
//  main.cpp
//  OperatorOverloading
//
//  Created by 覃思平 on 2016/11/26.
//  Copyright © 2016年 覃思平. All rights reserved.
//
//  算符重载
//


#include <iostream>
#include "Overloading.h"


int main(int argc, const char * argv[]) {
    
    Complex c1(3,4) , c2(5,-10);
    
    cout<<"c1 = ";
    c1.display();
    
    cout<<"c2 = ";
    c2.display();
    
    cout<<"c1 + c2 = ";
    (c1+c2).display();
    
    cout<<"c1 - c2 = ";
    (c1-c2).display();
    
    cout<<"c1 * c2 = ";
    (c1*c2).display();
    
    cout<<"c1 / c2 = ";
    (c1/c2).display();

    return 0;
}
