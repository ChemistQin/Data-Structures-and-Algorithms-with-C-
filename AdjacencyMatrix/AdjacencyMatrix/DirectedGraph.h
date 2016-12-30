//
//  DirectedGraph.h
//  AdjacencyMatrix
//
//  Created by 覃思平 on 2016/12/29.
//  Copyright © 2016年 覃思平. All rights reserved.
//
//  ref:http://www.cnblogs.com/skywang12345/

#ifndef DirectedGraph_h
#define DirectedGraph_h
#include <vector>
#include <iomanip>

using namespace std;

const int MAX = 100;

class MatrixDG {
private:
    char mVexs[MAX];    // 顶点集合
    int mVexNum;             // 顶点数
    int mEdgNum;             // 边数
    int mMatrix[MAX][MAX];   // 邻接矩阵
    
public:
    // 创建图(自己输入数据)
    MatrixDG();
    // 创建图(用已提供的矩阵)
    MatrixDG(vector<char> &vexs, int vlen, char edges[][2], int elen);
    ~MatrixDG();
    
    // 打印矩阵队列图
    void print();
    
private:
    // 读取一个输入字符
    char readChar();
    // 返回ch在mMatrix矩阵中的位置
    int getPosition(char ch);
};

/*
 * 创建图(自己输入数据)
 */
MatrixDG::MatrixDG()
{
    char c1, c2;
    int p1, p2;
    
    // 输入"顶点数"和"边数"
    cout << "input vertex number: ";
    cin >> mVexNum;
    cout << "input edge number: ";
    cin >> mEdgNum;
    if ( mVexNum < 1 || mEdgNum < 1 || (mEdgNum > (mVexNum * (mVexNum-1))))
    {
        cout << "input error: invalid parameters!" << endl;
        return ;
    }
    
    // 初始化"顶点"
    for (int i = 0; i < mVexNum; i++)
    {
        cout << "vertex(" << i << "): ";
        mVexs[i] = readChar();
    }
    
    // 初始化"边"
    for (int i = 0; i < mEdgNum; i++)
    {
        // 读取边的起始顶点和结束顶点
        cout << "edge(" << i << "): ";
        c1 = readChar();
        c2 = readChar();
        
        p1 = getPosition(c1);
        p2 = getPosition(c2);
        if (p1 == -1 || p2 == -1)
        {
            cout << "input error: invalid edge!" << endl;
            return ;
        }
        
        mMatrix[p1][p2] = 1;
    }
}

/*
 * 创建图(用已提供的矩阵)
 *
 * 参数说明：
 *     vexs  -- 顶点数组
 *     vlen  -- 顶点数组的长度
 *     edges -- 边数组
 *     elen  -- 边数组的长度
 */
MatrixDG::MatrixDG(vector<char> &vexs, int vlen, char edges[][2], int elen)
{
    int p1, p2;
    
    // 初始化"顶点数"和"边数"
    mVexNum = vlen;
    mEdgNum = elen;
    // 初始化"顶点"
    for (int i = 0; i < mVexNum; i++)
        mVexs[i] = vexs[i];
    
    // 初始化"边"
    for (int i = 0; i < mEdgNum; i++)
    {
        // 读取边的起始顶点和结束顶点
        p1 = getPosition(edges[i][0]);
        p2 = getPosition(edges[i][1]);
        
        mMatrix[p1][p2] = 1;
    }
}

/*
 * 析构函数
 */
MatrixDG::~MatrixDG()
{
}

/*
 * 返回ch在mMatrix矩阵中的位置
 */
int MatrixDG::getPosition(char ch)
{

    for(int i = 0; i < mVexNum; i ++)
        if(mVexs[i] == ch)
            return i;
    return -1;
}

/*
 * 读取一个输入字符
 */
char MatrixDG::readChar()
{
    char ch;
    
    do {
        cin >> ch;
    } while(!((ch >= 'a' && ch <= 'z')||(ch >= 'A' && ch <= 'Z')));
    
    return ch;
}

/*
 * 打印矩阵队列图
 */
void MatrixDG::print()
{
    cout << "Martix Graph:" << endl;
    for (int i = 0; i < mVexNum; i++)
    {
        for (int j = 0; j < mVexNum; j++)
            cout << mMatrix[i][j] << " ";
        cout << endl;
    }
}

#endif /* DirectedGraph_h */
