//
//  Sales_data.h
//  SalesData
//
//  Created by 覃思平 on 2016/12/6.
//  Copyright © 2016年 覃思平. All rights reserved.
//

#ifndef Sales_data_h
#define Sales_data_h
#include<string>

using namespace std;

class Sales_data{
public:
    Sales_data() = default;
    
    string bookNo;
    unsigned unit_sold = 0;
    double revenue = 0.0;
    
    Sales_data(const string &s): bookNo(s){}
    Sales_data(const string &s , unsigned n , double p):
                     bookNo(s) , unit_sold(n) , revenue(p * n){}
    Sales_data(istream &is);
    
    string isbn();
    double avg_price() const;
    Sales_data& combine(const Sales_data&);
    
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

Sales_data::Sales_data(istream &is){
    read(is , *this);
}

Sales_data& Sales_data::combine(const Sales_data& rhs){
    unit_sold += rhs.unit_sold;
    revenue += rhs.revenue;
    return *this;
}


#endif /* Sales_data_h */
