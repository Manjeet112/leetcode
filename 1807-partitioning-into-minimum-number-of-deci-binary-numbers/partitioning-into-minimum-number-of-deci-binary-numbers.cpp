class Solution {
public:
    int minPartitions(string n) {
        int maxdigit=0;
        for(int i=0;i<n.length();i++){
            int digit=n[i]-'0';
            if(digit>maxdigit)
            maxdigit=digit;
        }
        return maxdigit;
    }
};