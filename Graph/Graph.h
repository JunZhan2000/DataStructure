//
// Created by 23276 on 2021/7/20.
//

#ifndef DATASTRUCTURE_GRAPH_H
#define DATASTRUCTURE_GRAPH_H

#define MaxInt 32767        // 表示无穷大
#define MaxVertexNum 100    // 最大节点数量

typedef int VertexType;    // 顶点数据类型
typedef int EdgeType;       // 边数据类型
typedef int Vertex;     //节点
typedef int WeightType; //边的权重
typedef int DataType;       //节点存储的值
typedef enum Bool{false=0, true=1} Bool;

// 图的邻接矩阵存储
typedef struct {
    VertexType Vex[MaxVertexNum];   // 存储节点
    EdgeType Edge[MaxVertexNum][MaxVertexNum];  // 存储边的矩阵
    int vexNum, edgeNum;    //节点和边的数量
} AMGraphStruct, *AMGraph;

// 图的邻接表存储
typedef struct Edge{
    int V1, V2;         //边的起点，终点
    WeightType Weight;  //边的权重
} *Edge;
typedef struct AdjNode{
    Vertex VEnd;            //边的终点
    WeightType Weight;      //边的权重
    struct AdjNode *Next;   //指向下一个节点
} *PtrToAdjNode;   //链表的一个节点
typedef struct Vnode{
    PtrToAdjNode firstEdge; //存储了节点所有的边的链表
    DataType Data;       //节点存储的数据
} *AdjList;          //邻接表用于表示一个结点的连接情况的节点

typedef struct ALNode{
    int vexNum;     //结点数
    int edgeNum;     //边数
    AdjList adjList;  //邻接表
} *ALGraph;      //以邻接矩阵存储图的数据结构

AMGraph CreateAMGraph();    // 创建一个用于测试的邻接矩阵
ALGraph CreateALGraph();    // 创建一个用于厕所的邻接表
void InsertEdge(ALGraph G, int V1, int V2, WeightType weight);  //向无向图G插入一条边E(邻接表)
void DFS_AM(AMGraph G, Vertex v, Bool *visited);  //深度优先搜索
void DFSTraverse_AM(AMGraph G);  //从第v个节点 深度优先遍历 邻接矩阵表示的图
void DFS_AL(ALGraph G, Vertex v, Bool *visited);  //深度优先搜索
void DFSTraverse_AL(ALGraph G);  //从第v个节点 深度优先遍历 邻接表表示的图
void BFS_AM(AMGraph G, Vertex v, Bool *visited);  // 广度优先搜索
void BFSTraverse_AM(AMGraph G);  //从第v个节点 广度优先遍历 邻接矩阵表示的图
void BFS_AL(ALGraph G, Vertex v, Bool *visited);  // 广度优先搜索
void BFSTraverse_AL(ALGraph G);  //从第v个节点 广度优先遍历 邻接表表示的图


#endif //DATASTRUCTURE_GRAPH_H
