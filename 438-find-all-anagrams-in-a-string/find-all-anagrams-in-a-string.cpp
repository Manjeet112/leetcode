class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<int>ans;
        vector<int>pfreq(26,0);
        vector<int>winfreq(26,0);
        for(int i=0;i<m;i++){
            pfreq[p[i]-'a']++;
        }
        int left=0;
        for(int right=0;right<n;right++){
            winfreq[s[right]-'a']++;
            if(right-left+1>m){
                winfreq[s[left]-'a']--;
                left++;
            }
            if(right-left+1==m){
                if(pfreq==winfreq){
                    ans.push_back(left);
                }
            }
        }
        return ans;
    }
};