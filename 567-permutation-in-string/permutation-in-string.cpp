class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<int>freqs1(26,0);
        vector<int>winfreqs2(26,0);
        vector<int>ans;
        for(int i=0;i<n;i++){
            freqs1[s1[i]-'a']++;
        }
        int left=0;
        for(int right=0;right<m;right++){
            winfreqs2[s2[right]-'a']++;
        if(right-left+1>n){
            winfreqs2[s2[left]-'a']--;
            left++;
        }
        if(right-left+1==n){
            if(winfreqs2==freqs1){
                return true;
            }
        }
        }
        return false;
    }
};