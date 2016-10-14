//
//  main.cpp
//  MSTree
//
//  Created by 覃思平 on 2016/10/15.
//  Copyright © 2016年 覃思平. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <limits>
#include <queue>
#include "MinSpannigTree.h"

using namespace std;




int main()
{
    /* 创建以下的图
        2    3
     (0)--(1)--(2)
     |   / \   |
    6|  /   \5 |7
     | /     \ |
     (3)-------(4)
          9          */
    int const V = 5;
 int graph[V][V] =
       {{0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0},
    };
    
    // Print the solution
    PrimMST(graph);
    
    return 0;
}
