//
//  MinSpannigTree.h
//  MSTree
//
//  Created by 覃思平 on 2016/10/15.
//  Copyright © 2016年 覃思平. All rights reserved.
//

#ifndef MinSpannigTree_h
#define MinSpannigTree_h
#include <vector>
#include <string>
#include <set>
#include <map>
#include <limits>
#include <queue>

using namespace std;

int const V = 5 ;

int minKey(vector<int> &key, vector<bool> &mstSet)
{
    int min = INT_MAX; //INT_MAX defined in limits.h
    int minIndex;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], minIndex = v;
    
    return minIndex;
}

// 打印MST
void printMST(vector<int> &parent, int n, int graph[V][V])
{
    printf("Edge   Weight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

// Prim算法
// 从任意根节点开始，直至树覆盖V

void PrimMST(int graph[V][V])
{
    vector<int> parent(V); // 保持MST信息
    vector<int> key(V,INT_MAX);   // 所有顶点的代价值,初始为无穷大
    vector<bool> mstSet(V,false);  //当前包含在MST中点的集合
    
    key[0] = 0;     //
    parent[0] = -1; // 第一个作为树的根。
    
    //  MST 有V的顶点
    for (int count = 0; count < V-1; count++)
    {
        int u = minKey(key, mstSet);
        // 添加u到 MST Set
        mstSet[u] = true;
        //更新和u相连的顶点的代价
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
                parent[v]  = u, key[v] = graph[u][v];
    }
    
    // 打印生成的MST
    printMST(parent, V, graph);
}

#endif /* MinSpannigTree_h */
