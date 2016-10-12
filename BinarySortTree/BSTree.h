//
//  BSTree.h
//  BinarySortTree
//
//  Created by 覃思平 on 2016/10/8.
//  Copyright © 2016年 覃思平. All rights reserved.
//

#ifndef BSTree_h
#define BSTree_h


using namespace std;

class BinaryTree
{
private:
    typedef struct Node{
        struct Node * parent;
        struct Node * lChild;
        struct Node * rChild;
        int data;
    }*pNode;
    pNode root;
    void _visitMiddle(pNode root);
    void _visitPre(pNode root);
    void _visitPost(pNode root);
    pNode _searchKey(pNode root, int key);//真查找函数，私有函数，隐藏root节点
    void _delAllNode(pNode root);
public:
    BinaryTree();
    BinaryTree(int * datum, int len);
    pNode SearchMaxNode(pNode node);
    pNode SearchMinNode(pNode node);
    pNode GetRoot();
    pNode SearchKey(int key);//查找函数
    bool DeleteNode(int key);//删除
    pNode SearchPredecessor(pNode node);
    pNode SearchSuccessor(pNode node);
    void VisitMiddle();//中序遍历
    void VisitPre();//先序遍历
    void VisitPost();//后序遍历
    bool InsertNode(pNode * cuRoot, int data, pNode self);//插入
    ~BinaryTree();
};

//构造函数
BinaryTree::BinaryTree(int * datum, int len)
{
    root = nullptr;
    for (int i = 0; i < len; i++)
        InsertNode(&root, datum[i], root);
}

BinaryTree::BinaryTree()
{
    root = nullptr;
}


bool BinaryTree::InsertNode(pNode * cuRoot, int data, pNode self)
{   //递归设计时找到最源头，才能得到最简设计
    if (*cuRoot == nullptr){
        pNode node = new Node;
        if (node == nullptr)
            return false;
        node->data = data;
        node->lChild = node->rChild = node->parent = nullptr;
        (*cuRoot) = node;
        node->parent = self;
        return true;
    }
    if (data > (*cuRoot)->data)
        InsertNode(&(*cuRoot)->rChild, data, *cuRoot);
    else
        InsertNode(&(*cuRoot)->lChild, data, *cuRoot);
    return true;
}

//查找函数
BinaryTree::pNode BinaryTree::_searchKey(pNode root, int key){
    if (root == nullptr)
        return nullptr;
    if (root->data == key)    //找到了
        return root;
    else if (root->data > key)//值偏小，到左子树找
        return _searchKey(root->lChild, key);
    else                      //值偏大，到右子树找
        return _searchKey(root->rChild, key);
}
//对外接口
BinaryTree::pNode BinaryTree::SearchKey(int key){
    return _searchKey(root, key);
}

BinaryTree::pNode BinaryTree::SearchPredecessor(pNode node){
    if (node == nullptr)
        return nullptr;
    else if (node->lChild != nullptr)
        return SearchMaxNode(node->lChild);
    else
    {
        if (node->parent == nullptr)
            return nullptr;
        while (node)
        {
            if (node->parent->rChild == node)
                break;
            node = node->parent;
        }
        return node->parent;
    }
}

BinaryTree::pNode BinaryTree::SearchSuccessor(pNode node){
    if (node == nullptr)
        return nullptr;
    else if (node->rChild != nullptr)
        return SearchMinNode(node->rChild);
    else
    {
        if (node->parent == nullptr)
            return nullptr;
        while (node)
        {
            if (node->parent->lChild == node)
                break;
            node = node->parent;
        }
        return node->parent;
    }
}

//查找最小值
BinaryTree::pNode BinaryTree::SearchMinNode(pNode curNode){//一直向左，直至找到左子树为空的节点
    if (curNode == nullptr)
        return nullptr;
    while (curNode->lChild != nullptr)
        curNode = curNode->lChild;
    return curNode;
}

//查找最大值
BinaryTree::pNode BinaryTree::SearchMaxNode(pNode curNode){//同理，一直向右
    if (curNode == nullptr)
        return nullptr;
    while (curNode->rChild != nullptr)
        curNode = curNode->rChild;
    return curNode;
}

//中序遍历的递归算法
void BinaryTree::_visitMiddle(pNode root){
    if (root != nullptr){
        _visitMiddle(root->lChild);
        printf("%d;", root->data);
        _visitMiddle(root->rChild);
    }
}

void BinaryTree::VisitMiddle(){
    _visitMiddle(root);
}

//先序遍历的递归算法
void BinaryTree::_visitPre(pNode root){
    if(root != nullptr){
        printf("%d;",root->data);
        _visitPre(root->lChild);
        _visitPre(root->rChild);
    }
}

void BinaryTree::VisitPre(){
    _visitPre(root);
}

//后序遍历的递归算法
void BinaryTree::_visitPost(pNode root){
    if(root != nullptr){
        _visitPost(root->lChild);
        _visitPost(root->rChild);
        printf("%d;",root->data);
    }
}

void BinaryTree::VisitPost(){
    _visitPost(root);
}
//节点删除
bool BinaryTree::DeleteNode(int key){
    //return _deleteNode(root, key);
    pNode node = SearchKey(key);
    if (!node)
        return false;
    //被删节点为叶子结点
    if (node->lChild == nullptr && node->rChild == nullptr){
        if (node->parent == nullptr){
            root = nullptr;
        }
        else
        {
            if (node->parent->lChild == node)
                node->parent->lChild = nullptr;
            else
                node->parent->rChild = nullptr;
        }
        delete node;
    }
    //被删节点只有左子树
    else if (node->lChild != nullptr && node->rChild == nullptr){
        //将左孩子的父亲指向被删节点的父亲
        node->lChild->parent = node->parent;
        //被删节点为根，修改根节点
        if (node->parent == nullptr)
            root = node->lChild;
        else if(node->parent->lChild == node)
            node->parent->lChild = node->lChild;
        else
            node->parent->rChild = node->lChild;
        delete node;
    }
    //被删节点只有右子树
    else if (node->lChild == nullptr && node->rChild != nullptr){
        //将右孩子的父亲指向被删节点的父亲
        node->rChild->parent = node->parent;
        //被删节点为根，修改根节点
        if (node->parent == nullptr)
            root = node->rChild;
        else if (node->parent->lChild == node)
            node->parent->lChild = node->rChild;
        else
            node->parent->rChild = node->rChild;
        delete node;
    }
    //被删节点左、右子树都有
    else {  //用后继节点取代删除节点，并删除后继
        pNode successor = SearchSuccessor(node);
        int temp = successor->data;
        DeleteNode(temp);
        node->data = temp;
    }
    return true;
}

//析构函数
BinaryTree::~BinaryTree()
{
    _delAllNode(root);
}
void BinaryTree::_delAllNode(pNode root){
    if (root != nullptr && root!=NULL){
        _delAllNode(root->lChild);
        _delAllNode(root->rChild);
        DeleteNode(root->data);
    }
}

#endif /* BSTree_h */
