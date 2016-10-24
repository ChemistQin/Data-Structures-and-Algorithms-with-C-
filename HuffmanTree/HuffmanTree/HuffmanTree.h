//
//  HuffmanTree.h
//  HuffmanTree
//
//  Created by 覃思平 on 2016/10/24.
//  Copyright © 2016年 覃思平. All rights reserved.
//
//  ref:skywang
//
//


#ifndef HuffmanTree_h
#define HuffmanTree_h
#include <iomanip>

using namespace std;

template <class T>
class HuffmanNode{
    public:
    T key;				// 权值
    HuffmanNode *left;	// 左孩子
    HuffmanNode *right;	// 右孩子
    HuffmanNode *parent;// 父结点
    
    
    HuffmanNode(){}
    HuffmanNode(T value, HuffmanNode *l, HuffmanNode *r, HuffmanNode *p):
    key(value),left(l),right(r),parent(p) {}
};



template <class T>
class MinHeap {
    private:
    HuffmanNode<T> *mHeap;	// 最小堆的数组
    int mCapacity;			// 总的容量
    int mSize;				// 当前有效数据的数量
    private:
    // 上调算法
    void filterUp(int start);
    // 下调算法
    void filterDown(int start, int end);
    // 交换两个HuffmanNode节点的全部数据，i和j是节点索引。
    void swapNode(int i, int j);
    public:
    MinHeap();
    ~MinHeap();
    
    // 将node的全部数据拷贝给"最小堆的指定节点"
    int copyOf(HuffmanNode<T> *node);
    // 获取最小节点
    HuffmanNode<T>* dumpFromMinimum();
    // 创建最小堆
    void create(T a[], int size);
    // 销毁最小堆
    void destroy();
};


template <class T>
MinHeap<T>::MinHeap()
{
}

template <class T>
MinHeap<T>::~MinHeap()
{
    destroy();
}

/*
 * 最小堆的向下调整算法
 *
 * 注：数组实现的堆中，第N个节点的左孩子的索引值是(2N+1)，右孩子的索引是(2N+2)。
 *
 * 参数说明：
 *     start -- 被下调节点的起始位置(一般为0，表示从第1个开始)
 *     end   -- 截至范围(一般为数组中最后一个元素的索引)
 */
template <class T>
void MinHeap<T>::filterDown(int start, int end)
{
    int c = start; 	 	// 当前(current)节点的位置
    int l = 2*c + 1; 	// 左(left)孩子的位置
    HuffmanNode<T> tmp = mHeap[c];	// 当前(current)节点
    
    while(l <= end)
    {
        // "l"是左孩子，"l+1"是右孩子
        if(l < end && mHeap[l].key > mHeap[l+1].key)
        l++;		// 左右两孩子中选择较小者，即mHeap[l+1]
        if(tmp.key <= mHeap[l].key)
        break;		//调整结束
        else
        {
            mHeap[c] = mHeap[l];
            c = l;
            l = 2*l + 1;
        }
    }
    mHeap[c] = tmp;
}

/*
 * 最小堆的向上调整算法(从start开始向上直到0，调整堆)
 *
 * 注：数组实现的堆中，第N个节点的左孩子的索引值是(2N+1)，右孩子的索引是(2N+2)。
 *
 * 参数说明：
 *     start -- 被上调节点的起始位置(一般为数组中最后一个元素的索引)
 */
template <class T>
void MinHeap<T>::filterUp(int start)
{
    int c = start;			// 当前节点(current)的位置
    int p = (c-1)/2;		// 父(parent)结点的位置
    HuffmanNode<T> tmp = mHeap[c];		// 当前节点(current)
    
    while(c > 0)
    {
        if(mHeap[p].key <= tmp.key)
        break;
        else
        {
            mHeap[c] = mHeap[p];
            c = p;
            p = (p-1)/2;
        }
    }
    mHeap[c] = tmp;
}

/*
 * 将node的全部数据拷贝给"最小堆的指定节点"
 *
 * 返回值：
 *     0，表示成功
 *    -1，表示失败
 */
template <class T>
int MinHeap<T>::copyOf(HuffmanNode<T> *node)
{
    // 如果"堆"已满，则返回
    if(mSize == mCapacity)
    return -1;
    
    mHeap[mSize] = *node;   // 将"node的数据"全部复制到"数组末尾"
    filterUp(mSize);		// 向上调整堆
    mSize++;				// 堆的实际容量+1
    
    return 0;
}

/*
 * 交换两个HuffmanNode节点的全部数据
 */
template <class T>
void MinHeap<T>::swapNode(int i, int j)
{
    HuffmanNode<T> tmp = mHeap[i];
    mHeap[i] = mHeap[j];
    mHeap[j] = tmp;
}

/*
 * 新建一个节点，并将最小堆中最小节点的数据复制给该节点。
 * 然后除最小节点之外的数据重新构造成最小堆。
 *
 * 返回值：
 *     失败返回nullptrptr。
 */
template <class T>
HuffmanNode<T>* MinHeap<T>::dumpFromMinimum()
{
    // 如果"堆"已空，则返回
    if(mSize == 0)
    return nullptr;
    
    HuffmanNode<T> *node;
    if((node = new HuffmanNode<T>()) == nullptr)
    return nullptr;
    
    // 将"最小节点的全部数据"复制给node
    *node = mHeap[0];
    
    swapNode(0, mSize-1);				// 交换"最小节点"和"最后一个节点"
    filterDown(0, mSize-2);	// 将mHeap[0...mSize-2]构造成一个最小堆
    mSize--;
    
    return node;
}

/*
 * 创建最小堆
 *
 * 参数说明：
 *     a -- 数据所在的数组
 *     size -- 数组大小
 */
template <class T>
void MinHeap<T>::create(T a[], int size)
{
    int i;
    
    // 创建最小堆所对应的数组
    mSize = size;
    mCapacity = size;
    mHeap = new HuffmanNode<T>[size];
    
    // 初始化数组
    for(i=0; i<size; i++)
    {
        mHeap[i].key = a[i];
        mHeap[i].parent = mHeap[i].left = mHeap[i].right = nullptr;
    }
    
    // 从(size/2-1) --> 0逐次遍历。遍历之后，得到的数组实际上是一个最小堆。
    for (i = size / 2 - 1; i >= 0; i--)
    filterDown(i, size-1);
}

// 销毁最小堆
template <class T>
void MinHeap<T>::destroy()
{
    mSize = 0;
    mCapacity = 0;
    delete[] mHeap;
    mHeap = nullptr;
}



template <class T>
class Huffman {
    private:
    HuffmanNode<T> *mRoot;	// 根结点
    
    public:
    Huffman();
    ~Huffman();
    
    // 前序遍历"Huffman树"
    void preOrder();
    // 中序遍历"Huffman树"
    void inOrder();
    // 后序遍历"Huffman树"
    void postOrder();
    
    // 创建Huffman树
    void create(T a[], int size);
    // 销毁Huffman树
    void destroy();
    
    // 打印Huffman树
    void print();
    private:
    // 前序遍历"Huffman树"
    void preOrder(HuffmanNode<T>* tree) const;
    // 中序遍历"Huffman树"
    void inOrder(HuffmanNode<T>* tree) const;
    // 后序遍历"Huffman树"
    void postOrder(HuffmanNode<T>* tree) const;
    
    // 销毁Huffman树
    void destroy(HuffmanNode<T>* &tree);
    
    // 打印Huffman树
    void print(HuffmanNode<T>* tree, T key, int direction);
};

/*
 * 构造函数
 */
template <class T>
Huffman<T>::Huffman():mRoot(nullptr)
{
}

/*
 * 析构函数
 */
template <class T>
Huffman<T>::~Huffman()
{
    destroy();
}

/*
 * 前序遍历"Huffman树"
 */
template <class T>
void Huffman<T>::preOrder(HuffmanNode<T>* tree) const
{
    if(tree != nullptr)
    {
        cout<< tree->key << " " ;
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

template <class T>
void Huffman<T>::preOrder()
{
    preOrder(mRoot);
}

/*
 * 中序遍历"Huffman树"
 */
template <class T>
void Huffman<T>::inOrder(HuffmanNode<T>* tree) const
{
    if(tree != nullptr)
    {
        inOrder(tree->left);
        cout<< tree->key << " " ;
        inOrder(tree->right);
    }
}

template <class T>
void Huffman<T>::inOrder()
{
    inOrder(mRoot);
}

/*
 * 后序遍历"Huffman树"
 */
template <class T>
void Huffman<T>::postOrder(HuffmanNode<T>* tree) const
{
    if(tree != nullptr)
    {
        postOrder(tree->left);
        postOrder(tree->right);
        cout<< tree->key << " " ;
    }
}

template <class T>
void Huffman<T>::postOrder()
{
    postOrder(mRoot);
}

/*
 * 创建Huffman树
 *
 * 参数说明：
 *     a 权值数组
 *     size 数组大小
 *
 * 返回值：
 *     Huffman树的根节点
 */
template <class T>
void Huffman<T>::create(T a[], int size)
{
    int i;
    HuffmanNode<T> *left, *right, *parent;
    MinHeap<T> *heap = new MinHeap<T>();
    
    // 建立数组a对应的最小堆
    heap->create(a, size);
    
    for(i=0; i<size-1; i++)
    {
        left = heap->dumpFromMinimum();  // 最小节点是左孩子
        right = heap->dumpFromMinimum(); // 其次才是右孩子
        
        // 新建parent节点，左右孩子分别是left/right；
        // parent的大小是左右孩子之和
        parent = new HuffmanNode<T>(left->key+right->key, left, right, nullptr);
        left->parent = parent;
        right->parent = parent;
        
        
        // 将parent节点数据拷贝到"最小堆"中
        if (heap->copyOf(parent)!=0)
        {
            cout << "插入失败!" << endl << "结束程序" << endl;
            destroy(parent);
            parent = nullptr;
            break;
        }
    }
    
    mRoot = parent;
    
    // 销毁最小堆
    heap->destroy();
    delete heap;
}

/*
 * 销毁Huffman树
 */
template <class T>
void Huffman<T>::destroy(HuffmanNode<T>* &tree)
{
    if (tree==nullptr)
    return ;
    
    if (tree->left != nullptr)
    return destroy(tree->left);
    if (tree->right != nullptr)
    return destroy(tree->right);
    
    delete tree;
    tree=nullptr;
}

template <class T>
void Huffman<T>::destroy()
{
    destroy(mRoot);
}

/*
 * 打印"Huffman树"
 *
 * key        -- 节点的键值
 * direction  --  0，表示该节点是根节点;
 *               -1，表示该节点是它的父结点的左孩子;
 *                1，表示该节点是它的父结点的右孩子。
 */
template <class T>
void Huffman<T>::print(HuffmanNode<T>* tree, T key, int direction)
{
    if(tree != nullptr)
    {
        if(direction==0)	// tree是根节点
        cout << setw(2) << tree->key << " is root" << endl;
        else				// tree是分支节点
        cout << setw(2) << tree->key << " is " << setw(2) << key << "'s "  << setw(12) << (direction==1?"right child" : "left child") << endl;
        
        print(tree->left, tree->key, -1);
        print(tree->right,tree->key,  1);
    }
}

template <class T>
void Huffman<T>::print()
{
    if (mRoot != nullptr)
    print(mRoot, mRoot->key, 0);
}



#endif /* HuffmanTree_h */
