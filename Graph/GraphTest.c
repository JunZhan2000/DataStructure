//
// Created by 23276 on 2021/7/20.
//

#include <stdio.h>
#include "Graph.h"

int main(void){
    AMGraph amGraph = CreateAMGraph();
    ALGraph alGraph = CreateALGraph();

    // 深度优先遍历邻接矩阵
    printf("深度优先遍历邻接矩阵：\n");
    DFSTraverse_AM(amGraph);
    // 深度优先遍历邻接表
    printf("\n深度优先遍历邻接表：\n");
    DFSTraverse_AL(alGraph);
    // 广度优先遍历邻接矩阵
    printf("\n广度优先遍历邻接矩阵：\n");
    BFSTraverse_AM(amGraph);
    // 广度优先遍历邻接表
    printf("\n广度优先遍历邻接表：\n");
    BFSTraverse_AL(alGraph);

    return 0;
}