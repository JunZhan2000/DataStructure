//
// Created by 23276 on 2021/7/30.
//


// 交换nums数组中i和j的元素
void swap(int nums[], int i, int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}


// 冒泡排序
void BubbleSort(int nums[], int length){
    int flag;   // 用于标记一趟排序中有没有出现交换
    for (int i = 0; i < length; i++){
        flag = 0;
        for (int j = 0; j < length-i-1; j++) {
            if (nums[j] > nums[j+1]){
                swap(nums, j, j+1);
                flag = 1;
            }
        }
        if (flag == 0){
            break;
        }
    }
}


// 快速排序
void QuickSort(int nums[], int length){

}