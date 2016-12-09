//
//  main.cpp
//  SalesData
//
//  Created by 覃思平 on 2016/12/6.
//  Copyright © 2016年 覃思平. All rights reserved.
//

#include <iostream>
#include "Sales_data.h"


int main(int argc, const char * argv[]) {
    Sales_data item1;  //Sales_data() = default;
    print(cout, item1) << endl;
    
    Sales_data item2("0-201-78345-X");//Sales_data(const string &s): bookNo(s){}
    print(cout, item2) << endl;
    
    Sales_data item3("0-201-78345-X", 3, 20.00);//Sales_data(const string &s , unsigned n , double p):bookNo(s) , unit_sold(n) , revenue(p * n){}

    print(cout, item3) << endl;
    
    
    //cout << "Input ISBN,Sold units,price \n";
    //Sales_data item4(cin);//Sales_data(istream &is);
    //print(cout, item4) << endl;
    
    if(item1 == item2)
        cout << " item1 == item2 \n";
    else cout << " item1 != item2 \n";
    
    
    return 0;
}
