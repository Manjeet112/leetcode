class Solution {
public:
int maxConsecutive(vector<int>&Bars){
    sort(Bars.begin(),Bars.end());
    int longest=1;
    int curr=1;
    if(Bars.empty())return 1;
    for(int i=1;i<Bars.size();i++){
        if(Bars[i]==Bars[i-1]+1){
            curr++;
        }
        else{
            curr=1;
        }
        longest=max(longest,curr);
    }
    return longest+1;
}
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxH=maxConsecutive(hBars);
        int maxV=maxConsecutive(vBars);
        int side=min(maxH,maxV);
        return side*side;
    }
};