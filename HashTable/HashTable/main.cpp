//
//  main.cpp
//  HashTable
//
//  Created by 覃思平 on 2016/10/17.
//  Copyright © 2016年 覃思平. All rights reserved.
//

#include <iostream>
#include "HashTable.h"

using namespace std;


int main(int argc, const char * argv[]) {
    
    HashMap hashmap;
    
    hashmap.put(1,2);
    hashmap.put(2,4);
    hashmap.put(3,256);
    
    cout<<hashmap.get(4)<<endl;
    cout<<hashmap.get(3)<<endl;

    return 0;
}
