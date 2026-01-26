class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int min_val=INT_MAX;
        for(int i=1;i<n;i++){
            min_val=min(min_val,arr[i]-arr[i-1]);
        }
        vector<vector<int>>result;
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1]==min_val){
                result.push_back({arr[i-1],arr[i]});
            }
        }
        return result;
    }
};