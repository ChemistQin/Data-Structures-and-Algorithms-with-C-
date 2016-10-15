//
//  stack.h
//  Stack
//
//  Created by 覃思平 on 2016/9/28.
//  Copyright © 2016年 覃思平. All rights reserved.
//

#ifndef stack_h
#define stack_h
#include <vector>

using namespace std;

//const int MaxSize = 100;
template<class T>
class Stack {
private:
    vector<T> c;
public:
    void Push(const T& key);
    bool Pop();
    T Top();
    bool Empty() const;
    void PrintStack();
};

template<class T> void Stack<T>::Push(const T& key){
    c.push_back(key);
}

template<class T> bool Stack<T>::Pop(){
    if(!Empty())
        c.pop_back();
    else cout << "Error : Stack is empty!" ;
}

template<class T> T Stack<T>::Top(){
    if(!Empty())
        return c.back();
    else cout <<"Error : Stack is empty!" ;
}

template<class T> bool Stack<T>::Empty() const{
    return c.empty();
}

template<class T> void Stack<T>::PrintStack(){
    for(auto v : c )
        cout << v <<" " ;
    cout <<endl;
}

#endif

/* Stack() {       // 构造函数 Constructor
 }
 
 ~Stack() { }    // 析构函数 Destructor
 
 int Top() {
 
 if (size == 0) {
 std::cout<<"Error: stack empty 空栈\n";
 return -1;
 }
 return data[size-1];
 }
 
 void Push(int d) { //将元素进栈
 
 if (size < MaxSize)
 data[size++] = d;
 else
 std::cout<<"Error: stack full 满栈\n";
 }
 
 void Pop() { //出栈
 if (size == 0)
 std::cout<<"Error: stack empty 空栈\n";
 else
 size--;
 }
 
 void Show() { //遍历栈中元素
 for (auto &a:data){  //for auto range语句，c++11特性
 std::cout<<a<<std::endl;
 if(size--<1) break;
 }
 }*/
