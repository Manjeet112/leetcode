class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>>pre(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                pre[i][j]=mat[i-1][j-1]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
            }
        }
        int maxLen=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                while(i-maxLen-1>=0 && j-maxLen-1>=0){
                    int len=maxLen+1;
                    int sum=pre[i][j]-pre[i-len][j]-pre[i][j-len]+pre[i-len][j-len];
                    if(sum<=threshold)
                    maxLen=len;
                    else
                    break;
                }
            }
        }
        return maxLen;
    }
};