class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        sort(arr.begin(),arr.end(),[x](int a,int b){
            int dist1=abs(a-x);
            int dist2=abs(b-x);
            if(dist1==dist2){
                return a<b;
            }
            return dist1<dist2;
        });
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(arr[i]);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};