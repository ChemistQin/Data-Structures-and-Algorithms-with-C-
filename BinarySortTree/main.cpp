//
//  main.cpp
//  BinarySortTree
//
//  Created by 覃思平 on 2016/10/8.
//  Copyright © 2016年 覃思平. All rights reserved.
//

#include <iostream>
#include "BSTree.h"

int main()
{
    int arrs[] = { 256,128,32,64,512,8,16,4,2,1 };
    int len = sizeof(arrs) / sizeof(arrs[0]);
    BinaryTree bTree(arrs,len);
    bTree.DeleteNode(32);
    bTree.VisitMiddle();
    std::cout<<std::endl;
    bTree.VisitPre();
    std::cout<<std::endl;
    bTree.VisitPost();
    std::cout<<std::endl;
    bTree.SearchKey(64);
    std::cout<<std::endl;
    
    return 0;

}
