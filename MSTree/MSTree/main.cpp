//
//  main.cpp
//  MSTree
//
//  Created by 覃思平 on 2016/10/15.
//  Copyright © 2016年 覃思平. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <limits>
#include <queue>
#include "MinSpannigTree.h"

using namespace std;


int main()
{
    /* Let us create following weighted graph
         10
     0--------1
     | \	 |
    6| 5\    |15
     |	 \   |
     2--------3
         4	 */
    int V = 4; // Number of vertices in graph
    int E = 6; // Number of edges in graph
    struct Graph* graph = createGraph(V, E);
    
    
    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;
    
    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;
    
    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;
    
    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;
    
    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;
    
    // add edge 1-2
    graph->edge[5].src = 1;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 1;
    
    KruskalMST(graph);
    
    return 0;
}


/*int main()
{
    创建以下的图
        2    3
     (0)--(1)--(2)
     |   / \   |
    6|  /8  \5 |7
     | /     \ |
     (3)-------(4)
          9
    int const V = 5;
 int graph[V][V] =
       {{0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0},
    };
    
    // Print the solution
    PrimMST(graph);
    
    return 0;
*/

