//
// Created by 23276 on 2021/7/29.
//

// 交换nums数组中i和j的元素
void swap(int nums[], int i, int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}


// 直接插入排序
void InsertSort(int nums[], int length){
    int mov;  //用于和currentNum比较的数字下标
    for(int i = 1; i < length; i++){
        int currentNum = nums[i];   // 当前待插入的数字
        mov = i-1;
        while (mov >= 0 && currentNum < nums[mov]){
            swap(nums, mov+1, mov);
            mov--;
        }
    }
}


// 折半插入排序
void BinInsertSort(int nums[], int length){
    int mov;  //用于和currentNum比较的数字下标
    int start, end, mid, insertIndex;
    for(int i = 1; i < length; i++){
        int currentNum = nums[i];   // 当前待插入的数字
        start = 0;
        end  = i-1;
        mid = (start + end) / 2;
        while (start <= end){
            if (nums[mid] == nums[i]){
                insertIndex = mid;
                break;
            } else if (nums[mid] < nums[i]){
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        if (start > end){
            insertIndex = start;
        }
        // 进行插入
        int temp = nums[i];
        for (int j = i-1; j >= insertIndex; i--){
            nums[j+1] = nums[j];
        }
        nums[insertIndex] = temp;
    }
}


// 希尔排序
void ShellInsert(int nums[], int length, int hop){
    // hop为增量
    int mov;
    for(int i = 0; i < hop; i++){
        // 一个循环排序一个分组
        for(int j = i; j < length; j +=hop){
            int currentNum = nums[j];   // 当前待插入的数字
            mov = j - hop;
            while (mov >= 0 && currentNum < nums[mov]){
                swap(nums, mov+hop, mov);
                mov -= hop;
            }
        }
    }
}


void ShellSort(int nums[], int length){
    int hop_arr[] = {5, 3, 1};
    for (int i = 0; i < 1; i++){
        ShellInsert(nums, length, hop_arr[i]);
    }
}