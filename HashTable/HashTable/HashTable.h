//
//  HashTable.h
//  HashTable
//
//  Created by 覃思平 on 2016/10/17.
//  Copyright © 2016年 覃思平. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h
#include <vector>


class HashItem
{
    private:
    
    int key,value;
    
    public:
    
    HashItem(int key,int value)
    {
        this->key = key;
        this->value = value;
    }
    
    int getKey()
    {
        return key;
    }
    
    int getValue()
    {
        return value;
    }
    
};



class HashMap{
    private:
    
    int const MaxSize = 256;
    HashItem **table;

    public:
//构造函数，先把table指向的指针置空
    HashMap(){
        table = new HashItem *[MaxSize];   //取MaxSize的空间
        for (int i = 0; i < MaxSize; i++)
        {
            table[i] = nullptr;
        }
    }
    
    
//插入元素
    void put(int key,int value)
    {
        int hash = (key % MaxSize);
        while (table[hash] != nullptr && table[hash]->getKey() != key)
            hash = (hash + 1) % MaxSize;
        
        if (table[hash] != nullptr)
            delete table[hash];
        
        table[hash] = new HashItem(key,value);
    }

//获取元素
    int get(int key)
    {
        int hash = (key % MaxSize);
        while (table[hash] != nullptr && table[hash]->getKey() != key)
        {
            hash = (hash + 1) % MaxSize;
        }
        if (table[hash] == nullptr) //hash为空指针，返回-1
        {
            std::cout << "Not found \n";
            return -1;
        }
        else
        {
            return table[hash]->getValue();
        }
    }
    
//析构函数
    ~HashMap()
    {
        for (int i = 0; i < MaxSize; i++)
        {
            if (table[i] != nullptr)
            {
                delete table[i];
            }
        }
        delete[] table;
    }
};

#endif /* HashTable_h */
