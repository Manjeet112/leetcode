class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n=nums.size();
        if(k==1)return nums[0];
        int need=k-1;
        multiset<int>small,large;
        long long sumSmall=0;
        long long ans=LLONG_MAX;
        auto balance=[&](){
            while(small.size()>need){
                auto it=prev(small.end());
                sumSmall-=*it;
                large.insert(*it);
                small.erase(it);
            }
            while(small.size()<need && !large.empty()){
                auto it=large.begin();
                sumSmall+=*it;
                small.insert(*it);
                large.erase(it);
            }
        };
        auto add=[&](int x){
            small.insert(x);
            sumSmall+=x;
            balance();
        };
        auto remove=[&](int x){
            auto it=small.find(x);
            if(it!=small.end()){
                sumSmall-=x;
                small.erase(it);
            }else{
                large.erase(large.find(x));
            }
            balance();
        };
        int L=1;
        for(int R=1;R<n;++R){
            add(nums[R]);
            if(R-L+1>dist+1){
                remove(nums[L]);
                L++;
            }
            if(R-L+1>=need){
                ans=min(ans,sumSmall+nums[0]);
            }
        }
        return ans;
    }
};