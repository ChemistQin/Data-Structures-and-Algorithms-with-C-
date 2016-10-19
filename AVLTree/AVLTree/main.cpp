//
//  main.cpp
//  AVLTree
//
//  Created by 覃思平 on 2016/10/19.
//  Copyright © 2016年 覃思平. All rights reserved.
//
//  Ref:http://www.cnblogs.com/skywang12345/p/3577360.html
//

#include <iostream>
#include <vector>
#include "AVLTree.h"



int main(int argc, const char * argv[]) {
    

    vector<int> vec = {2,4,8,16,256,64,128,32,1024,2048,512};
    
    AVLTree<int>* tree=new AVLTree<int>();
    
    cout << "== 依次添加: ";
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] <<" ";
        tree->insert(vec[i]);
    }
    
    cout << "\n== 前序遍历: ";
    tree->preOrder();
    
    cout << "\n== 中序遍历: ";
    tree->inOrder();
    
    cout << "\n== 后序遍历: ";
    tree->postOrder();
    cout << endl;
    
    cout << "== 高度: " << tree->height() << endl;
    cout << "== 最小值: " << tree->minimum() << endl;
    cout << "== 最大值: " << tree->maximum() << endl;
    cout << "== 树的详细信息: " << endl;
    tree->print();
    
    int i = 8;
    cout << "\n== 删除根节点: " << i;
    tree->remove(i);
    
    cout << "\n== 高度: " << tree->height() ;
    cout << "\n== 中序遍历: " ;
    tree->inOrder();
    cout << "\n== 树的详细信息: " << endl;
    tree->print();
    
    // 销毁二叉树
    tree->destroy();
    return 0;
    
}
