//
//  Queue.h
//  Queue
//
//  Created by 覃思平 on 2016/9/29.
//  Copyright © 2016年 覃思平. All rights reserved.
//
//  用数组实现的队列
#ifndef Queue_h
#define Queue_h
#include <vector>

using namespace std;



template<class T>
class Queue {
private:
    vector<T> c;
public:
    void Push(const T& key);
    bool Pop();
    T Top();
    bool Empty() const;
    void PrintQueue();
};

template<class T>
void Queue<T>::Push(const T& key){
    c.push_back(key);
}

template<class T>
bool Queue<T>::Pop(){
    if(!Empty())
        c.erase(c.begin());
    else cout << "Error : Queue is empty!" ;
}

template<class T>
T Queue<T>::Top(){
    if(!Empty())
        return c.back();
    else cout <<"Error : Queue is empty!" ;
}

template<class T>
bool Queue<T>::Empty() const{
    return c.empty();
}

template<class T>
void Queue<T>::PrintQueue(){
    for(auto v : c )
        cout << v <<" " ;
    cout << endl;
}



#endif
