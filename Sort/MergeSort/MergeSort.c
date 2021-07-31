//
// Created by 23276 on 2021/7/31.
//



// 合并有序子列
void Merge(int nums[], int tmp_arr[], int low, int mid, int high){
    int left = low, right = mid+1, tmp_index = low;
    while (left <= mid && right <= high){
        if(nums[left] <= nums[right]){
            tmp_arr[tmp_index++] = nums[left++];
        } else{
            tmp_arr[tmp_index++] = nums[right++];
        }
    }
    while (left <= mid) {
        tmp_arr[tmp_index++] = nums[left++];
    }
    while (right <= high) {
        tmp_arr[tmp_index++] = nums[right++];
    }
    for (int i = low; i <= high; i++) {
        nums[i] = tmp_arr[i];
    }
}


// 归并排序
void MSort(int nums[], int tmp_arr[], int low, int high){
    if (low >= high){
        return;
    }
    int mid = (low + high) / 2;
    // 对两个子列分别做归并排序
    MSort(nums, tmp_arr, low, mid);
    MSort(nums, tmp_arr, mid+1, high);
    // 合并两个有序子列
    Merge(nums, tmp_arr, low, mid, high);
}


// 归并排序的统一接口
void MergeSort(int nums[], int length){
    int tmp_arr[length];
    MSort(nums, tmp_arr, 0, length-1);
}