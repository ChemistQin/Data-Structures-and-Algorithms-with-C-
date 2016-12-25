//
//  main.cpp
//  Template
//
//  Created by 覃思平 on 2016/12/25.
//  Copyright © 2016年 覃思平. All rights reserved.
//

#include <iostream>
#include "Template.h"
#include <vector>
#include <string>

int main(int argc, const char * argv[]) {
    vector<int> v1 = {1,2,3};
    vector<int> v2 = {1,2,4};
    
    string s1 = "excited";
    string s2 = "angry";
    
    cout << compare(v1, v2) <<endl;
    cout << compare(s1, s2) <<endl;
    
    return 0;
}
