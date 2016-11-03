//
//  Search.h
//  Search
//
//  Created by 覃思平 on 2016/11/3.
//  Copyright © 2016年 覃思平. All rights reserved.
//

#ifndef Search_h
#define Search_h

using namespace std;

//顺序查找
void OrderSearch(vector<int> &vec , int key){
    int i = 0;
    while (i < vec.size() && vec[i] != key) {
        i++;
        if(vec[i] == key)
            cout << key << " in No." << i <<endl;
        if(i >= vec.size())
            cout << key <<" Not Found \n" ;
    }
}

//折半查找
void BinarySearch(vector<int> &vec , int key){
    int low = 0 , high = vec.size() - 1 ;
    int mid = (low + high) >> 1;
    while (low <= high && vec[mid] != key) {
        mid = (low + high)/2;
        if(vec[mid] == key)
            cout << key << " in No." << mid  <<endl;
        if(vec[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
}

#endif /* Search_h */
