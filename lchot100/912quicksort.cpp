#include<bits/stdc++.h>
using namespace std;

//快排
class Solutionquick {
public:
    void quicksort(vector<int>& nums, int low, int high){
        if(low<high){
            int index = partition(nums,low,high);
            quicksort(nums,low,index-1);
            quicksort(nums,index+1,high);
        }
    }
    int partition(vector<int>& nums, int low, int high){
        int s = low;
        swap(nums[low],nums[low + rand()%(high-low+1)]); //随机换一个数到最左
        int pivot = nums[low]; // 最左作为pivot
        while(low<high){
            while(low<high && nums[high]>pivot) high--;
            while(low<high && nums[low]<=pivot) low++;
            if(low >= high) break;
            swap(nums[low],nums[high]);
        }
        swap(nums[s],nums[low]);
        return low;

    }
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size()<2) return nums;
        quicksort(nums,0,nums.size()-1);
        return nums;
    }
};
//partition的其他写法
/*
int partition(vector<int>& nums, int l, int r) {
    int pivot = nums[r];
    int i = l - 1;
    for (int j = l; j <= r - 1; ++j) {
        if (nums[j] <= pivot) {
            i = i + 1;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[r]);
    return i + 1;
}
int randomized_partition(vector<int>& nums, int l, int r) {
    int i = rand() % (r - l + 1) + l; // 随机选一个作为我们的主元
    swap(nums[r], nums[i]);
    return partition(nums, l, r);
*/

int main(){

    vector<int> nums = {5,2,3,1};
    Solutionquick sol;
    vector<int> ans = sol.sortArray(nums);
    return 0;
}