//
// Created by 23276 on 2021/7/31.
//

// 交换nums数组中i和j的元素
void swap(int nums[], int i, int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}


// 简单选择排序
void SelectSort(int nums[], int length){
    int min;
    for(int i = 0; i < length; i++){
        // 每一次外循环选出一个未排序序列中最小的元素
        min = i;
        for(int j = i+1; j < length; j++){
            if (nums[j] < nums[min]){
                min = j;
            }
        }
        swap(nums, i, min); //把最小的元素放在前面
    }
}


// 调整堆
void AdjustHeap(int nums[], int root, int end){
    int rootValue = nums[root]; // 初始状态根节点的元素
    int parent = root, son = parent * 2 + 1;
    while (son <= end){
        // 循环条件是parent存在子节点
        if (son != end && nums[son+1] > nums[son]){
            // 存在右儿子且右儿子比左儿子大，则使用右儿子替代父节点
            son++;
        }
        if (rootValue >= nums[son]){
            // 比左右儿子都大，则已经找到自己的位置，停止循环
            break;
        }
        nums[parent] = nums[son];
        parent = son;
        son = parent * 2 + 1;
    }
    nums[parent] = rootValue;
}


// 建立堆
void BuildHeap(int nums[], int length){
    int n = length / 2 - 1; // n为从后往前第一个非叶节点
    for (int i = n; i >= 0; i--){
        AdjustHeap(nums, i, length-1);
    }
}


// 堆排序
void HeapSort(int nums[], int length){
    BuildHeap(nums, length);    // 将nums数组转成最大堆
    for (int i = length-1; i >= 0; i--){
        swap(nums, 0, i);   // 把根节点放在末尾，即最大的元素放在未排序序列的末尾
        AdjustHeap(nums, 0, i-1);
    }
}


