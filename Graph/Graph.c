#include <stdlib.h>
#include <stdio.h>
#include "Graph.h"
#include "queue.h"


// 创建一个用于测试的邻接矩阵
AMGraph CreateAMGraph(){
    AMGraph G = (AMGraph) malloc(sizeof(AMGraphStruct));
    G->vexNum = 8;
    G->edgeNum = 8;
    for(int i = 0; i < G->vexNum; i++){
        G->Vex[i] = i;
    }
    for(int i = 0; i < MaxVertexNum; i++){
        for(int j = 0; j < MaxVertexNum; j++){
            G->Edge[i][j] = MaxInt;     // 初始化为所有节点没有边
        }
    }
    // 自定义的测试数据
    G->Edge[0][1] = G->Edge[1][0] = 1;
    G->Edge[0][2] = G->Edge[2][0] = 1;
    G->Edge[1][3] = G->Edge[3][1] = 1;
    G->Edge[1][4] = G->Edge[4][1] = 1;
    G->Edge[2][5] = G->Edge[5][2] = 1;
    G->Edge[2][6] = G->Edge[6][2] = 1;
    G->Edge[3][7] = G->Edge[7][3] = 1;
    G->Edge[4][7] = G->Edge[7][4] = 1;

    return G;
}


//向无向图G插入一条边E
void InsertEdge(ALGraph G, int V1, int V2, WeightType weight){
    G->edgeNum++;    //图的边数加一

    // V1 to V2
    PtrToAdjNode newAdjNode = (PtrToAdjNode)malloc(sizeof(struct AdjNode));     //新建一个边节点
    newAdjNode->VEnd = V2;           //新边的终点为E的终点
    newAdjNode->Weight = weight;     //新边的权重为E的权重
    //插入新边
    newAdjNode->Next = G->adjList[V1].firstEdge;
    G->adjList[V1].firstEdge = newAdjNode;

    // V2 to V1
    PtrToAdjNode newAdjNode2 = (PtrToAdjNode)malloc(sizeof(struct AdjNode));     //新建一个边节点
    newAdjNode2->VEnd = V1;           //新边的终点为E的终点
    newAdjNode2->Weight = weight;     //新边的权重为E的权重
    //插入新边
    newAdjNode2->Next = G->adjList[V2].firstEdge;
    G->adjList[V2].firstEdge = newAdjNode2;
}


// 创建一个用于测试的邻接表
ALGraph CreateALGraph(){
    int vexNum = 8;
    ALGraph G = (ALGraph) malloc(sizeof(struct ALNode));
    G->vexNum = vexNum;
    G->edgeNum = 0;
    G->adjList = (AdjList) malloc(vexNum * sizeof(struct AdjNode));
    for(int i = 0; i < vexNum; i++){
        G->adjList[i].firstEdge = NULL;
    }
    Edge edge = (Edge) malloc(sizeof(struct Edge));
    // 和邻接矩阵一样的测试数据
    InsertEdge(G, 0, 1, 1);
    InsertEdge(G, 0, 2, 1);
    InsertEdge(G, 1, 3, 1);
    InsertEdge(G, 1, 4, 1);
    InsertEdge(G, 2, 5, 1);
    InsertEdge(G, 2, 6, 1);
    InsertEdge(G, 3, 7, 1);
    InsertEdge(G, 4, 7, 1);

    return G;
}


// 访问一个节点
void Visit(Vertex v){
    printf("%d ", v);
}


//深度优先搜索
void DFS_AM(AMGraph G, Vertex v, Bool *visited){
    if(visited[v] == true){
        return;
    }
    Visit(v);
    visited[v] = true;
    for(int i = 0; i < G->vexNum; i++){
        if (G->Edge[v][i] != MaxInt && visited[i] == false){
            //存在边
            DFS_AM(G, i, visited);
        }
    }
}


//深度优先遍历 邻接矩阵表示的图
void DFSTraverse_AM(AMGraph G){
    // 初始化visited数组
    Bool visited[G->vexNum];
    for(int i = 0; i < G->vexNum; i++){
        visited[i] = false;
    }
    // 深度优先遍历
    for(Vertex v = 0; v < G->vexNum; v++){
        if(visited[v] == false){
            DFS_AM(G, v, visited);
        }
    }
}


//深度优先搜索
void DFS_AL(ALGraph G, Vertex v, Bool *visited){
    if(visited[v] == true){
        return;
    }
    Visit(v);
    visited[v] = true;
    // 遍历邻接矩阵和邻接表的区别主要在于怎么查找一个节点连接的点
    // 邻接矩阵直接遍历数组，邻接矩阵需要遍历链表
    for(PtrToAdjNode adjNode = G->adjList[v].firstEdge; adjNode != NULL; adjNode = adjNode->Next){
        Vertex nextVex = adjNode->VEnd;
        if (visited[nextVex] == false){
            //存在边
            DFS_AL(G, nextVex, visited);
        }
    }
}


// 深度优先遍历 邻接表表示的图
void DFSTraverse_AL(ALGraph G){
    // 初始化visited数组
    Bool visited[G->vexNum];
    for(int i = 0; i < G->vexNum; i++){
        visited[i] = false;
    }
    // 深度优先遍历
    for(Vertex v = 0; v < G->vexNum; v++){
        if(visited[v] == false){
            DFS_AL(G, v, visited);
        }
    }
}


// 广度优先搜索
void BFS_AM(AMGraph G, Vertex v, Bool *visited){
    Queue Q = CreateQueue();
    Enqueue(Q, v);
    Visit(v);
    visited[v] = true;
    while (!QueueIsEmpty(Q)){
        //访问当前节点
        Vertex currentV = Dequeue(Q);
        //当前节点的邻接节点入队
        for(int i = 0; i < G->vexNum; i++){
            if (G->Edge[currentV][i] != MaxInt && !visited[i]){
                //存在边
                Visit(i);
                visited[i] = true;
                Enqueue(Q, i);
            }
        }
    }
}


//从第v个节点 广度优先遍历 邻接矩阵表示的图
void BFSTraverse_AM(AMGraph G){
    // 初始化visited数组
    Bool visited[G->vexNum];
    for(int i = 0; i < G->vexNum; i++){
        visited[i] = false;
    }
    // 广度优先遍历
    for(Vertex v = 0; v < G->vexNum; v++){
        if(visited[v] == false){
            BFS_AM(G, v, visited);
        }
    }
}


// 广度优先搜索
void BFS_AL(ALGraph G, Vertex v, Bool *visited){
    Queue Q = CreateQueue();
    Enqueue(Q, v);
    Visit(v);
    visited[v] = true;
    while (!QueueIsEmpty(Q)) {
        Vertex currentV = Dequeue(Q);
        for (PtrToAdjNode adjNode = G->adjList[currentV].firstEdge; adjNode != NULL; adjNode = adjNode->Next) {
            Vertex nextVex = adjNode->VEnd;
            if (visited[nextVex] == false) {
                //存在边
                Visit(nextVex);
                visited[nextVex] = true;
                Enqueue(Q, nextVex);
            }
        }

    }
}


//从第v个节点 广度优先遍历 邻接表表示的图
void BFSTraverse_AL(ALGraph G){
    // 初始化visited数组
    Bool visited[G->vexNum];
    for(int i = 0; i < G->vexNum; i++){
        visited[i] = false;
    }
    // 广度优先遍历
    for(Vertex v = 0; v < G->vexNum; v++){
        if(visited[v] == false){
            BFS_AL(G, v, visited);
        }
    }
}