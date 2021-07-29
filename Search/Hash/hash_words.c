/*
1. 哈希表数据结构的实现
2. 统计一个文本中单词的词频
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef unsigned int Position;
typedef char *ElementType;
typedef struct TblNode Cell;

typedef enum Info {Legitimate, Empty, Deleted } Info;

struct TblNode{
    ElementType word;           //单词
    int count;                  //出现次数
    Info info;                  //状态
};

typedef struct HashTable{
    int TableSize;             //表的大小
    Cell * Cells;              //结点数组
} * HashTable;

HashTable InitHashTable(int TableSize);                //初始化一个哈希表并返回
void ShowTable(HashTable HT);                          //输出哈希表
Position StrHash(char *str, int TableSize);            //映射字符串的哈希函数
Position Find(HashTable HT, ElementType E);            //查找元素E在HT中的位置，查到则返回对应的位置，否则返回应该插入的位置
int InsertOrCount(HashTable HT, ElementType E);        //将E插入到哈希表中，插入成功返回1；已存在则增大词频并返回
int ReadAWord(FILE *fp, ElementType *E);               //从文件中读取一个单词至E，返回单词的长度
void RankHashTbl(HashTable HT);                        //输出哈希表中词频前一百的单词

int main(void){
    int length, wordCounts = 0, TableSize = 5000;
    char *word = NULL;
    FILE *fp;
    char txt[] = "C:\\SourceCode\\static\\txt\\ATQM.txt";       //要统计的文本

    HashTable HT = InitHashTable(TableSize);    //初始化一张哈希表

    if((fp = fopen(txt, "r")) == NULL){
        //未能成功打开文件
        printf("Open failed!\n");
        system("PAUSE");
        exit(0);
    }
    while(!feof(fp)){
        length = ReadAWord(fp, &word);      //从文本中读取一个单词
        if(length >= 3){
            //如果读出的字符串长度大于等于3，我们将其视为单词，主要是由于在表的size很大的情况下，
            wordCounts++;               //读取的单词数加1
            InsertOrCount(HT, word);    //若该单词第一次出现，插入表中；若已存在于表中，词频加一
        }
        else{
            //否则，弃之，释放空间
            free(word);
        }
    }
    // ShowTable(HT);       //输出哈希表

    RankHashTbl(HT);        //输出词频前一百的单词
    printf("words count: %d\n", wordCounts);
    fclose(fp);

    system("PAUSE");
    return 0;
}


//初始化一个哈希表并返回
HashTable InitHashTable(int TableSize){
    HashTable HT = (HashTable) malloc(sizeof(struct HashTable));

    HT->TableSize = TableSize;
    HT->Cells = (Cell * )malloc(TableSize * (sizeof(struct TblNode)));     //给表开辟相应的空间
    for (int i = 0; i < TableSize; i++){
        HT->Cells[i].info = Empty;         //将每个节点的状态置为空
    }

    return HT;
}


//输出哈希表
void ShowTable(HashTable HT){
    for(int i = 0; i < HT->TableSize; i++){
        if(HT->Cells[i].info != Legitimate){
            printf("%d: Not Inserted\n", i);
        }
        else{
            printf("%d: word:%s\tcount:%d\n", i, HT->Cells[i].word, HT->Cells[i].count);
        }
    }   
}


//映射字符串的哈希函数
Position StrHash(char * str, int TableSize){
    Position p = 0;

    while(*str != 0){
        //获取对应的128进制的数字
        p = (p << 5) + *str;
        str++;  
    }
    return p % TableSize;
}


//查找元素E在HT中的位置，查到则返回对应的位置，否则返回应该插入的位置
Position Find(HashTable HT, ElementType E){
    Position p, newP;
    int i = 1;      //探测次数

    newP = p = StrHash(E, HT->TableSize);     //根据哈希函数映射出一个存放的位置

    while(HT->Cells[newP].info != Empty && strcmp(E, HT->Cells[newP].word) != 0){
        //该位置上不是E，继续寻找下一个位置，使用平方探测法
        if(i++ % 2 == 0){
            //偶数次
            newP = p - ((i+1) / 2) * ((i+1) / 2);       //向左探测更新地址
            while(newP < 0){
                newP += HT->TableSize;                  //调整至合法地址
            }
        }
        else{
            newP = p + ((i+1) / 2) * ((i+1) / 2);       //向右探测更新地址
            if(newP > 0){
                newP = newP % HT->TableSize;            //调整至合法地址
            }
        }
    }
    
    return newP;
}


//将E插入到哈希表中，插入成功返回1；已存在则增大词频并返回
int InsertOrCount(HashTable HT, ElementType E){
    Position p = Find(HT, E);       //先查找E是否存在于表HT中

    if(HT->Cells[p].info != Legitimate){
        //若该位置未被占据，插入
        HT->Cells[p].word = E;
        HT->Cells[p].info = Legitimate;
        HT->Cells[p].count = 1;

        return 1;
    }
    else{
        //该位置已被占据，说明E已经存在于表中，词频加一
        HT->Cells[p].count++;

        return HT->Cells[p].count;
    }
}


//从文件中读取一个单词至E，返回单词的长度
int ReadAWord(FILE *fp, ElementType *E){
    char buffer[21];                //缓冲区，最多读取长度为20的字符串
    int j = 0;
    char ch;
    for(int i = 0; i < 100; i++){
        ch = fgetc(fp);      //读取一个字符
        if(ch < 48 || (ch >= 58 && ch <= 64) || (ch >= 91 && ch <= 96 && ch != 95) || ch > 122){
            //如果读到的字符是分隔符，退出循环不再读取
            if( j != 0 ){
                //缓冲区内已经读到了字符
                break;
            }
        }else {
            buffer[j++] = ch;   //读入缓冲区中
        }
    }
    buffer[j] = 0;          //在字符串结尾设置0
    *E = (char *)malloc((strlen(buffer)+1) * sizeof(char));
    strcpy(*E, buffer);
    return j;
}


//输出哈希表中词频前一百的单词
void RankHashTbl(HashTable HT){
    int empty = 0;
    int numMost[100];
    for (int i = 0; i < 100; i++){
        numMost[i] = -1;
    }

        for (int i = 0; i < HT->TableSize; i++)
        {
            if(HT->Cells[i].info == Empty){
                empty++;
            }
            if (HT->Cells[i].info == Legitimate && (numMost[99] == -1 || HT->Cells[i].count > HT->Cells[numMost[99]].count))
            {
                //若该位置处存在单词，且其词频足以排进目前的前100，则继续确定其排位
                int rank = 99;
                while (rank >= 0 && (numMost[rank] == -1 || HT->Cells[i].count > HT->Cells[numMost[rank]].count))
                {//找到这个单词应该排的位置
                    rank--;
                }
                //此时word的下标应为rank+1
                for (int j = 98; j > rank; j--)
                {
                    numMost[j + 1] = numMost[j];
                }
                numMost[rank + 1] = i; //记录这个单词的下标
            }
        }
    printf("\n\n\nTop 100:\n");
    for(int i = 0; i < 100; i++){
        struct TblNode cell = HT->Cells[numMost[i]];
        printf("%d:  word: %s\t count: %d  position:%d\n", i, cell.word, cell.count, numMost[i]);
    }
    printf("alpha: %d\n", empty);
}