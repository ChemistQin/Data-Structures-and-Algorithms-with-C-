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



class HashMap
{
    private:
    int const MaxSize = 256;
    HashItem **table;

    //std::vector<std::shared_ptr<HashTable> > table(MaxSize, nullptr);
    public:
    HashMap()
    {
        table = new HashItem *[MaxSize];
        for (int i = 0; i < MaxSize; i++)
        {
            table[i] = nullptr;
        }
    }
    
    int get(int key)
    {
        int hash = (key % MaxSize);
        while (table[hash] != nullptr && table[hash]->getKey() != key)
        {
            hash = (hash + 1) % MaxSize;
        }
        if (table[hash] == nullptr)
        {
            std::cout << "Not found \n";
            return -1;
        }
        else
        {
            return table[hash]->getValue();
        }
    }
    
    void put(int key,int value)
    {
        int hash = (key % MaxSize);
        while (table[hash] != nullptr && table[hash]->getKey() != key)
        {
            hash = (hash + 1) % MaxSize;
        }
        if (table[hash] != nullptr)
        {
            delete table[hash];
        }
        table[hash] = new HashItem(key,value);
    }
    
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
