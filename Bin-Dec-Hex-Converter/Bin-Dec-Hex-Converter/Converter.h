//
//  Converter.h
//  Bin-Dec-Hex-Converter
//
//  Created by 覃思平 on 2016/11/24.
//  Copyright © 2016年 覃思平. All rights reserved.
//

#ifndef Converter_h
#define Converter_h
#include <vector>
#include <string>

using namespace std;

void DecConverter(int dec){
    vector<char> hexbit = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int i = 0;
    
    cout << "进制转换  : \n Dec = " << dec ;
    
    vector<int> hex1,hex3;
    hex1.push_back(dec);
    while (dec >> 4) {
        dec >>= 4;
        hex1.push_back(dec);
        i++;
    }
    
    for(int j = 0 ; j < i; j++){
        hex3.insert(hex3.begin(), hex1[j] - (hex1[j+1] << 4) );
    }
    hex3.insert(hex3.begin(),hex1[i]);

  
    cout <<"\n Hex = 0x";
    for(auto a : hex3){
        cout <<hexbit[a];
    }
    
    vector<string> binbit = {"0000","0001","0010","0011","0100","0101","0110","0111",
                             "1000","1001","1010","1011","1100","1101","1110","1111"};
    
    cout <<"\n Bin = (";
    for(auto a : hex3){
        cout <<binbit[a] <<" ";
    }
    cout <<")2" << endl;
    
}





#endif /* Converter_h */
