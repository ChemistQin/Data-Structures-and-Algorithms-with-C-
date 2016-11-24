//
//  main.cpp
//  RandomNumbers
//
//  Created by 覃思平 on 2016/11/24.
//  Copyright © 2016年 覃思平. All rights reserved.
//

#include <iostream>
#include <random>
#include <iomanip>
#include <string>
#include <map>
#include <cmath>

#include "Random.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    random_device rd;
    mt19937 mt(rd());
    for(int n = 0; n < 10; n++)
        std::cout << mt() << std::endl;
    return 0;
    
}
