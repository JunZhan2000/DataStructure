#ifndef _String_H

#define MAXLEN 50 

typedef struct SStringStruct{
    char ch[MAXLEN];    //存储串的一维数组
    int length;         //当前串的长度
} * SString;


//创建一个空串
SString CreateString();
//创建一个串，并用chars赋值
SString CreateStringAndValue(char *chars, int length);
//模式匹配：BF算法实现（暴力求解）
int IndexBF(SString S, SString T, int start);
//模式匹配：KMP算法实现
int IndexKMP(SString S, SString T, int start);
//获取KMP算法中需要的next数组
void get_next(SString T, int next[]);

#endif