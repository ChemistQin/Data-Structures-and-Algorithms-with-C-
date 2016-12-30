//
//  main.cpp
//  AdjacencyMatrix
//
//  Created by 覃思平 on 2016/12/29.
//  Copyright © 2016年 覃思平. All rights reserved.
//

#include <iostream>
#include "DirectedGraph.h"

int main(int argc, const char * argv[]) {
    vector<char> vexs = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char edges[][2] = {
        {'A', 'B'},
        {'B', 'C'},
        {'B', 'E'},
        {'B', 'F'},
        {'C', 'E'},
        {'D', 'C'},
        {'E', 'B'},
        {'E', 'D'},
        {'F', 'G'}};
    int vlen = vexs.size();
    int elen = sizeof(edges)/sizeof(edges[0]);
    MatrixDG* pG;
    
    // 自定义"图"(输入矩阵队列)
    //pG = new MatrixDG();
    // 采用已有的"图"
    pG = new MatrixDG(vexs, vlen, edges, elen);
    
    pG->print();   // 打印图
    return 0;
}
