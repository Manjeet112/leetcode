class Solution {
public:
int waviness(int x){
    string s=to_string(x);
    int n=s.size();
    if(n<3)return 0;
    int count=0;
    for(int i=1;i<n-1;i++){
        if(s[i]>s[i-1]&& s[i]>s[i+1]){
            count++;
        }
        else if(s[i]<s[i-1]&& s[i]<s[i+1]){
            count++;
        }
    }
    return count;
}
    int totalWaviness(int num1, int num2) {
        int totalsum=0;
        for(int i=num1;i<=num2;i++){
            totalsum+=waviness(i);
        }
        return totalsum;
    }
};