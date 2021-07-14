#include <stdio.h>
#include <stdlib.h>
#include "string.h"


//创建一个空串
SString CreateString(){
    SString S = (SString)malloc(sizeof(struct SStringStruct));
    S->length = 0;
    return S;
}

//创建一个串，并用chars赋值
SString CreateStringAndValue(char * chars, int length){
    SString S = (SString)malloc(sizeof(struct SStringStruct));
    for (int i = 1; i <= length; i++){
        S->ch[i] = chars[i-1];
    }
    S->length = length;
    return S;
}


//模式匹配：BF算法实现（暴力求解）
int IndexBF(SString S, SString T, int start){
    //省略对参数合法性的检查
    int indexS = start, indexT = 1;
    while (indexS <= S->length && indexT <= T->length){
        //因前一个条件退出循环，是未找到匹配的子串
        //因后一个条件退出循环，是匹配成功
        if(S->ch[indexS] == T->ch[indexT]){
            //当前字符匹配成功，匹配下一个字符
            indexS++;
            indexT++;
        } else{
            //当前字符匹配失败，则匹配主串的下一个子串
            indexS = indexS - indexT + 2;
            indexT = 1;
        }
    }
    if(indexT == T->length+1){
        //匹配到子串，返回位置
        return indexS - T->length;
    }
    return 0;   //未匹配到子串
}


//模式匹配：KMP算法实现
int IndexKMP(SString S, SString T, int start){
    int indexS = start, indexT = 1;
    //获取get数组
    int next[T->length + 1];
    get_next(T, next);
    while (indexS <= S->length && indexT <= T->length){
        //因前一个条件退出循环，是未找到匹配的子串
        //因后一个条件退出循环，是匹配成功
        if(indexT == 0 || S->ch[indexS] == T->ch[indexT]){
            //当前字符匹配成功，匹配下一个字符
            //或者是T[1:indexT-1]没有相同的前后缀，则从头开始匹配
            indexS++;
            indexT++;
        } else{
            //当前字符匹配失败，indexS不动，确定子串应该向右移动的量，即修改后的indexT-1
            indexT = next[indexT];
        }
    }
    if(indexT == T->length+1){
        //匹配到子串，返回位置
        return indexS - T->length;
    }
    return 0;   //未匹配到子串
    
}


//获取KMP算法中需要的next数组
void get_next(SString T, int next[]){
    int i = 1, j = 0;
    next[1] = 0;
    while(i < T->length){
        if(j == 0 || T->ch[i] == T->ch[j]){
            i++;
            j++;
            next[i] = j;
        } else{
            j = next[j];
        }
    }
}


int main(void){
    char charsS[13] = {'a', 'b', 'a', 'b', 'c', 'a', 'b', 'c', 'a', 'c', 'b', 'a', 'b'};
    char charsT[5] = {'a', 'b', 'c', 'a', 'c'};
    SString S = CreateStringAndValue(charsS, 13);     // 主串
    SString T = CreateStringAndValue(charsT, 5);     // 子串

    printf("%d\n", IndexBF(S, T, 1));
    printf("%d\n", IndexBF(S, T, 7));
    printf("%d\n", IndexKMP(S, T, 1));
    printf("%d\n", IndexKMP(S, T, 7));
}