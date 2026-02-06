class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int j=0;
        int maxkeep=0;
        for(int i=0;i<n;i++){
            while(j<n && nums[j]<=1LL*nums[i]*k){
                j++;
            }
            maxkeep=max(maxkeep,j-i);
        }
        return n-maxkeep;
    }
};