//
//  MinSpannigTree.h
//  MSTree
//
//  Created by 覃思平 on 2016/10/15.
//  Copyright © 2016年 覃思平. All rights reserved.
//
//  最小路径生成树
//

#ifndef MinSpannigTree_h
#define MinSpannigTree_h
#include <vector>
#include <string>
#include <limits>
#include <stdlib.h>


using namespace std;



// 边
struct Edge
{
    int src, dest, weight; //起点，终点，路径长度
};

// 图
struct Graph
{
    int V, E;
    struct Edge* edge;
};

// 创建图. V个节点，E条边
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;
    
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
    
    return graph;
}

// 子集
struct subset
{
    int parent;
    int rank;
};

// 查找
int find(struct subset subsets[], int i)
{
    // 查找root并设置root 为 i 的 parent
    if (subsets[i].parent != i)
    subsets[i].parent = find(subsets, subsets[i].parent);
    
    return subsets[i].parent;
}

// Union 用于连接x-y
void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    
    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
    subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
    subsets[yroot].parent = xroot;
    
    // If ranks are same, then make one as root and increment
    // its rank by one
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// 对边进行快速排序
int myComp(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}

// Kruskal 算法
// 以weight来排序，逐渐连接。
// 若x,y已连接，进入下一条边
void KruskalMST(struct Graph* graph)
{
    int V = graph->V;
    struct Edge result[V]; // 保存结果
    int e = 0; // result[] 的索引
    int i = 0; // edges 的索引
    
    // 第一步  对所有边进行升序排序    （当图无法改动时，创建一个新的数组来进行存储
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
    
    // 创建 V subsets
    struct subset *subsets =
    (struct subset*) malloc( V * sizeof(struct subset) );
    
    // 初始化 V subsets
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    
    while (e < V - 1)
    {
        // 第二步  找出最小边. i++
        struct Edge next_edge = graph->edge[i++];
        
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        
        // If including this edge does't cause cycle, include it
        // in result and increment the index of result for next edge
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        // Else discard the next_edge
    }
    
    // 打印result[],显示最小路径生成树
    printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e; ++i)
    printf("%d -- %d == %d\n", result[i].src, result[i].dest,
           result[i].weight);
    return;
}



// Driver program to test above functions

/*

int const V = 5 ; //图的容量设为常数

int minKey(vector<int> &key, vector<bool> &mstSet)
{
    int min = INT_MAX; //INT_MAX defined in limits.h
    int minIndex = 0;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], minIndex = v;
    
    return minIndex; //当前连接到树的节点
}

// 打印MST
void printMST(vector<int> &parent, int n, int graph[V][V])
{
    printf("Edge   Weight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
    
    //see the value of parents
    //for (auto a : parent)
    //   cout << a << endl;
    //print -1,0,1,0,1
}

// Prim算法
// 从任意根节点开始，直至树覆盖V


void PrimMST(int graph[V][V])
{
    vector<int> parent(V); // 保持MST信息
    vector<int> key(V,INT_MAX);   // 所有顶点的代价值,初始为无穷大
    vector<bool> mstSet(V,false);  //当前包含在MST中点的集合，true == connected ; false == unconnected
    
    key[0] = 0;     //
    parent[0] = -1; // 第一个作为树的根。
    
    //  MST 有V的顶点
    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);//index
        // 添加u到 MST Set 表示u已连接
        mstSet[u] = true;
        //更新和u相连的顶点的代价
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
                parent[v]  = u, key[v] = graph[u][v];
    }
    
    // 打印生成的MST
    printMST(parent, V, graph);
}


void KruskalMST(int graph[V][V]){
    vector<int> parent(V); // 保持MST信息
    vector<int> key(V,INT_MAX);   // 所有顶点的代价值,初始为无穷大
    vector<bool> mstSet(V,false);  //当前包含在MST中点的集合，true == connected ; false == unconnected
    
    key[0] = 0;     //
    parent[0] = -1; // 第一个作为树的根。
    
    for(int count = 0; count < V - 1 ; count++){
        
    }
  
}

 */




#endif /* MinSpannigTree_h */
