class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int total=0;
        int max_value=0;
        for(int i=0;i<n;i++){
            total+=gain[i];
            max_value=max(total,max_value);
        }
        return max_value;
    }
};