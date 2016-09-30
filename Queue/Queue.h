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
#define MaxSize 100

using namespace std;

template<class T> class Queue{
public:
    Queue(); //constructor
    ~Queue(); //destructor
    
    void add(T t);
    T front();
    T pop();
    void show();
    int size();
    int isEmpty();
    
private:
    T *arr;
    int count;
};


template<class T>
Queue<T>::Queue()  //构造函数，用于创建队列
{
    arr = new T[MaxSize];  //creat a queue ,default size == 100
    if (!arr)
    {
        cout<<"无法创建队列!"<<endl;
    }
}


template<class T>
Queue<T>::~Queue()  //析构函数，用于销毁队列
{
    if (arr)
    {
        delete[] arr;
        arr = NULL;
    }
}


template<class T>
void Queue<T>::add(T t) //入队 add a new element to the rear of the queue
{
    arr[count++] = t;
}


template<class T>
T Queue<T>::front()
{
    return arr[0]; //返回队头元素 return the front of the queue
}



template<class T>
T Queue<T>::pop() //出队
{
    int i = 0;;
    T ret = arr[0];
    
    count--;
    while (i++<count)
        arr[i-1] = arr[i];
    
    return ret; //返回出队元素
}


template<class T>
void Queue<T>::show() //打印队列元素，从队尾开始
{
    while (count)
        cout << arr[--count] <<endl;
}


template<class T>
int Queue<T>::size() //队列大小
{
    return count;
}


template<class T>
int Queue<T>::isEmpty() //是否为空
{
    return count==0;
}


#endif
