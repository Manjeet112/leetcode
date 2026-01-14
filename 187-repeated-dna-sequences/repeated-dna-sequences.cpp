class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>result;
        unordered_map<string,int>freq;
        if(s.length()<10)return result;
        for(int i=0;i+9<s.length();i++){
            string sub=s.substr(i,10);
            freq[sub]++;
            if(freq[sub]==2){
                result.push_back(sub);
            }
        }
        return result;
    }
};