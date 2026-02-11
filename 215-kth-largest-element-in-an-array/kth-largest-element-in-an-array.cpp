class Solution {
public:
int partition(vector<int>&nums,int low,int high){
    int pivot=nums[high];
    int i=low;
    for(int j=low;j<high;j++){
        if(nums[j]>pivot){
        swap(nums[i],nums[j]);
        i++;
        }
    }
    swap(nums[i],nums[high]);
    return i;
    }
    int quickSelect(vector<int>&nums,int low,int high,int k){
        while(low<=high){
            int p=partition(nums,low,high);
            if(p==k)return nums[p];
            else if(p>k)high=p-1;
            else low=p+1;
        }
        return -1;
}
int findKthLargest(vector<int>& nums, int k) {
    return quickSelect(nums,0,nums.size()-1,k-1);
}
};