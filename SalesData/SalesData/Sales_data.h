//
//  Sales_data.h
//  SalesData
//
//  Created by 覃思平 on 2016/12/6.
//  Copyright © 2016年 覃思平. All rights reserved.
//

#ifndef Sales_data_h
#define Sales_data_h
#include <string>

using namespace std;

class Sales_data{
    
    friend Sales_data add(const Sales_data& , const Sales_data&);
    friend istream &read(istream &is , Sales_data &item);
    friend ostream &print(ostream &os , Sales_data &item);
    friend bool operator == (const Sales_data &lhs , const Sales_data &rhs);
    friend bool operator != (const Sales_data &lhs , const Sales_data &rhs);
    
public:
    //Sales_data() = default;
    //Sales_data(const string &s): bookNo(s){}
    Sales_data(const string &s , unsigned n , double p):
                     bookNo(s) , unit_sold(n) , revenue(p * n){}
    //Sales_data(istream &is);
    
    //委托构造函数  delegating constructor
    Sales_data(): Sales_data("No ISBN" , 0 , 0){}
    Sales_data(const string &s): Sales_data(s , 0 , 0){}
    Sales_data(istream &is): Sales_data(){ read(is, *this);}
    
    ~Sales_data() = default;
    
    Sales_data& combine(const Sales_data&);
    string isbn() const { return bookNo; };
    double avg_price() const { return unit_sold ? revenue/unit_sold : 0;};
    Sales_data& operator = (const Sales_data &rhs);
    Sales_data& operator + (const Sales_data &rhs);
    
private:
    unsigned unit_sold = 0;
    double revenue = 0.0;
    string bookNo;
};

istream &read(istream &is , Sales_data &item){
    double price = 0;
    is >> item.bookNo >> item.unit_sold >> price;
    item.revenue = price * item.unit_sold;
    return is;
}
ostream &print(ostream &os , Sales_data &item){
    os << item.isbn() << " " << item.unit_sold <<" "<< item.revenue;
    return os;
}

Sales_data& Sales_data::combine(const Sales_data& rhs){
    unit_sold += rhs.unit_sold;
    revenue += rhs.revenue;
    return *this;
}

// overloading operator
bool operator == (const Sales_data &lhs , const Sales_data &rhs){
    return lhs.isbn() == rhs.isbn() &&
    lhs.unit_sold == rhs.unit_sold &&
    lhs.revenue == rhs.revenue;
}

bool operator != (const Sales_data &lhs , const Sales_data &rhs){
    return !(lhs == rhs);
}

Sales_data& Sales_data:: operator = (const Sales_data &rhs){
    bookNo = rhs.bookNo;
    unit_sold  = rhs.unit_sold;
    revenue = rhs.revenue;
    return *this;
}

Sales_data& Sales_data:: operator + ( const Sales_data &rhs){
    unit_sold  += rhs.unit_sold;
    revenue += rhs.revenue;
    return *this;
}
#endif /* Sales_data_h */
