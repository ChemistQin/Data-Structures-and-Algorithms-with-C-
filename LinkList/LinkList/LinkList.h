//
//  LinkList.h
//  LinkList
//
//  Created by 覃思平 on 2016/11/15.
//  Copyright © 2016年 覃思平. All rights reserved.
//

#ifndef LinkList_h
#define LinkList_h

#include <iostream>
using namespace std;

template<class T>
struct DoubleNode
{
public:
    T value;
    DoubleNode *prev;
    DoubleNode *next;

    DoubleNode() { }
    DoubleNode(T t, DoubleNode *prev, DoubleNode *next) {
        this->value = t;
        this->prev  = prev;
        this->next  = next;
    }
};

template<class T>
class DoubleLink
{
public:
    DoubleLink();
    ~DoubleLink();
    
    int Size();
    int IsEmpty();
    
    T Get(int index);
    
    int Insert(int index, T t);
    int InsertFirst(T t);
    int AppendLast(T t);
    int Delete(int index);
    
    int PrintList();
    
private:
    int count;
    DoubleNode<T> *phead;
    DoubleNode<T> *GetNode(int index);
};

template<class T>
DoubleLink<T>::DoubleLink() : count(0)
{
   
    phead = new DoubleNode<T>();
    phead->prev = phead->next = phead;
    // 设置链表计数为0
    //count = 0;
}

template<class T>
DoubleLink<T>::~DoubleLink()
{
    // 删除所有的节点
    DoubleNode<T>* ptmp;
    DoubleNode<T>* pnode = phead->next;
    while (pnode != phead)
    {
        ptmp = pnode;
        pnode=pnode->next;
        delete ptmp;
    }
    
    // 删除"表头"
    delete phead;
    phead = nullptr;
}

// 返回节点数目
template<class T>
int DoubleLink<T>::Size()
{
    return count;
}

// 返回链表是否为空
template<class T>
int DoubleLink<T>::IsEmpty()
{
    return count == 0;
}

// 获取第index位置的节点
template<class T>
DoubleNode<T>* DoubleLink<T>::GetNode(int index)
{
    // 判断参数有效性
    if (index < 0 || index >= count)
    {
        cout << "get node failed! the index in out of bound!" << endl;
        return nullptr;
    }
    
    // 正向查找
    if (index <= count/2)
    {
        int i = 0;
        DoubleNode<T>* pindex = phead->next;
        while (i++ < index) {
            pindex = pindex->next;
        }
        
        return pindex;
    }
    
    // 反向查找
    int j = 0;
    int rindex = count - index - 1;
    DoubleNode<T>* prindex = phead->prev;
    while (j++ < rindex) {
        prindex = prindex->prev;
    }
    
    return prindex;
}

// 获取第index位置的节点的值
template<class T>
T DoubleLink<T>::Get(int index)
{
    return GetNode(index)->value;
}

// 将节点插入到第index位置之前
template<class T>
int DoubleLink<T>::Insert(int index, T t)
{
    if (index == 0)
        return InsertFirst(t);
    
    DoubleNode<T>* pindex = GetNode(index);
    DoubleNode<T>* pnode  = new DoubleNode<T>(t, pindex->prev, pindex);
    pindex->prev->next = pnode;
    pindex->prev = pnode;
    count++;
    
    return 0;
}

// 将节点插入第一个节点处。
template<class T>
int DoubleLink<T>::InsertFirst(T t)
{
    DoubleNode<T>* pnode  = new DoubleNode<T>(t, phead, phead->next);
    phead->next->prev = pnode;
    phead->next = pnode;
    count++;
    
    return 0;
}

// 将节点追加到链表的末尾
template<class T>
int DoubleLink<T>::AppendLast(T t)
{
    DoubleNode<T>* pnode = new DoubleNode<T>(t, phead->prev, phead);
    phead->prev->next = pnode;
    phead->prev = pnode;
    count++;
    
    return 0;
}

// 删除index位置的节点
template<class T>
int DoubleLink<T>::Delete(int index)
{
    DoubleNode<T>* pindex = GetNode(index);
    pindex->next->prev = pindex->prev;
    pindex->prev->next = pindex->next;
    delete pindex;
    count--;
    
    return 0;
}



// 链表遍历
template<class T>
int DoubleLink<T>::PrintList()
{
    for (int i = 0; i < count; i++)
        cout << "pdlink("<<i<<")=" << GetNode(i)->value <<endl;
    
    return 0;
}



#endif /* LinkList_h */
