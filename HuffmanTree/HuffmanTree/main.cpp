//
//  main.cpp
//  HuffmanTree
//
//  Created by 覃思平 on 2016/10/24.
//  Copyright © 2016年 覃思平. All rights reserved.
//

#include <iostream>
#include <vector>
#include "HuffmanTree.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    vector<int> vec = {2,4,64,32,516,1024,512};
    
    int ilen = vec.size();
    Huffman<int>* tree=new Huffman<int>();
    
    cout << "== 添加序列: ";
    for(auto v : vec)
    cout << v <<" ";
    
    tree->create(vec, ilen);
    
    cout << "\n== 前序遍历: ";
    tree->preOrder();
    
    cout << "\n== 中序遍历: ";
    tree->inOrder();
    
    cout << "\n== 后序遍历: ";
    tree->postOrder();
    cout << endl;
    
    cout << "== 树的详细信息: " << endl;
    tree->print();
    
    // 销毁二叉树
    tree->destroy();

    return 0;
}
