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

int main(int argc, const char * argv[]) {
    vector<int> v1 = {1,2,3};
    vector<int> v2 = {1,2,4};
    
    cout << compare(v1, v2) <<endl;
    
    return 0;
}
