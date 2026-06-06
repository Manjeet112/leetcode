class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>answer;
        for(int i=0;i<n;i++){
            int totalsum_left=0;
            int totalsum_right=0;
            for(int j=0;j<i;j++){
                totalsum_left+=nums[j];
            }
            for(int j=i+1;j<n;j++){
                totalsum_right+=nums[j];
            }
            int diff=abs(totalsum_left-totalsum_right);
            answer.push_back(diff);
        }
        return answer;
    }
};