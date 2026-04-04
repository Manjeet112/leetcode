class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n=rows;
        int total=encodedText.length();
        int m=total/rows;
        string result="";
        for(int c=0;c<m;c++){
            int i=0,j=c;
            while(i<n && j<m){
                 result+=encodedText[i*m+j];
                 i++;
                 j++;
            }
        }
        while(!result.empty() && result.back()==' '){
            result.pop_back();
        }
        return result;
    }
};