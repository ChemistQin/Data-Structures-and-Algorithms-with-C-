//
//  Complex.h
//  OperatorOverloading
//
//  Created by 覃思平 on 2016/11/26.
//  Copyright © 2016年 覃思平. All rights reserved.
//

#ifndef Overloading_h
#define Overloading_h
#include <math.h>


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
    Complex operator + (Complex &cpx);//重载复数加法
    Complex operator - (Complex &cpx);//重载复数减法
    Complex operator * (Complex &cpx);//重载复数乘法
    Complex operator / (Complex &cpx);//重载复数除法
    Complex operator += (Complex &cpx);
    Complex operator -= (Complex &cpx);
    Complex operator *= (Complex &cpx);
    Complex operator /= (Complex &cpx);
    bool operator == (Complex &cpx);//重载复数等于
    bool operator != (Complex &cpx);//重载复数不等
    
                                    //复数之间不存在大于或小于，故不对>=,<=,>,<进行重载
    
    Complex conjugate();//共轭复数
    double absval();//复数的模
    void display();//显示复数
private:
    double real;
    double imag;
};

Complex Complex::operator + (Complex &cpx)
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

Complex Complex::operator += (Complex &cpx){
    *this = *this + cpx;
    return *this;
}

Complex Complex::operator -= (Complex &cpx){
    *this = *this - cpx;
    return *this;
}

Complex Complex::operator *= (Complex &cpx){
    *this = *this * cpx;
    return *this;
}

Complex Complex::operator /= (Complex &cpx){
    *this = *this / cpx;
    return *this;
}



bool Complex::operator == (Complex &cpx){
    if((real == cpx.real) && (imag == cpx.imag))
        return true;
    return false;
}

bool Complex::operator != (Complex &cpx){
    return !(*this == cpx);
}


Complex Complex::conjugate(){
    Complex c;
    c.real = real;
    c.imag = -imag;
    return c;
}


double Complex::absval(){
    return sqrt((real * real + imag * imag));
}


void Complex::display( )
{
    cout<<"("<<real<<","<<imag<<"i)"<<endl;
}


#endif /* Overloading_h */
