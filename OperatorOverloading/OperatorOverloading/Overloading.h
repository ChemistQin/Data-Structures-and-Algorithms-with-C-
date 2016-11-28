//
//  Overloading.h
//  OperatorOverloading
//
//  Created by 覃思平 on 2016/11/26.
//  Copyright © 2016年 覃思平. All rights reserved.
//

#ifndef Overloading_h
#define Overloading_h

using namespace std;

class Complex{
public:
    Complex(){
        real = 0;
        imag = 0;
    }
    Complex(double r,double i){
        real = r;
        imag = i;
    }
    Complex operator + (Complex &cpx);//声明重载运算符的函数
    Complex operator - (Complex &cpx);
    Complex operator * (Complex &cpx);
    Complex operator / (Complex &cpx);
    bool operator == (Complex &cpx);
    bool operator != (Complex &cpx);
    void display();
private:
    double real;
    double imag;
};

Complex Complex::operator + (Complex &cpx) //定义重载运算符的函数
{
    Complex c;
    c.real = real + cpx.real;
    c.imag = imag + cpx.imag;
    return c;
}

Complex Complex::operator - (Complex &cpx){
    Complex c;
    c.real = real - cpx.real;
    c.imag = imag - cpx.imag;
    return c;
}

Complex Complex::operator * (Complex &cpx){
    Complex c;
    c.real = real * cpx.real - imag * cpx.imag;
    c.imag = imag * cpx.real + real * cpx.imag;
    return c;
}

Complex Complex::operator / (Complex &cpx){
    Complex c;
    c.real = (real * cpx.real + imag * cpx.imag)/(cpx.real * cpx.real + cpx.imag * cpx.imag);
    c.imag = (imag * cpx.real - real * cpx.imag)/(cpx.real * cpx.real + cpx.imag * cpx.imag);
    return c;
}

bool Complex::operator == (Complex &cpx){
    if((real == cpx.real) && (imag == cpx.imag))
        return true;
    return false;
}

bool Complex::operator != (Complex &cpx){
    return !(*this == cpx);
}

void Complex::display( )
{
    cout<<"("<<real<<","<<imag<<"i)"<<endl;
}


#endif /* Overloading_h */
