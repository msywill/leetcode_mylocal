#include<bits/stdc++.h>
using namespace std;
/*
 * 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于val的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/remove-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
//双指针法
void swap(vector<int>& nums, int i, int j)
{
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}
int removeElement(vector<int>& nums, int val) {
    int j = nums.size()-1;
    for(int i=0;i<=j;i++){
        if(nums[i]==val)
        {
//            swap(nums,i,j);
//            i--,j--;
            swap(nums, i--, j--);  // i--巧妙的检查了交换之后的新的元素是否于val相等
        }
    }
    return j+1;
}


//原地拷贝覆盖法
/* 遍历nums， 当前遍历到 n
 * 如果 n和val相等，则跳过
 * 如果 n和val不等，则将n赋值给 idx下标位置，idx++
 *
*/
int removeElement2 (vector<int>& nums, int val){
    int idx = 0;
    for(int n: nums){
        if(n!=val){
            nums[idx] = n;
            idx++;
        }
    }
    return idx;

}

int main()
{

    string str;
    vector<int> nums;
    while(getline(cin,str))
    {
        if(str.size()>0)
        {
            stringstream sstr(str);
            int n;
            while(sstr>>n)
            {
                nums.push_back(n);
            }
        }
        else{
            int ans = removeElement(nums, 3);
            cout<< ans<< endl;
        }
    }

//    while((n = cin.get())!=EOF)
//    {
//        nums.push_back(n);
//    }


    return 0;
}