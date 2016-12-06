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
#include "Complex.h"


int main(int argc, const char * argv[]) {
    
    Complex c1(3,4) , c2(3,8);
    
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
    
    if(c1 != c2){
        cout << "c1 != c2 \n";
    }
    else cout << "c1 == c2 \n";
    Complex c3;
    c3 = c1.conjugate();
    cout << c1.absval() <<endl;
    c3.display();
    (c1*c3).display();
    
    c1 /= c2;
    c1.display();

    return 0;
}
