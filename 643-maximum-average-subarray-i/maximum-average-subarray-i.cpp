class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long sum=0;
        int n=nums.size();
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        long long maxsum=sum;
        for(int i=k;i<n;i++){
            sum+=nums[i]-nums[i-k];
            maxsum=max(maxsum,sum);
        }
        return (double)maxsum/k;
    }
};