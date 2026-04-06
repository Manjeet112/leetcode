class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x=0;
        int y=0;
        int dir=0;
        vector<pair<int,int>>dirs={
            {0,1},{1,0},{0,-1},{-1,0}
        };
        int maxDist=0;
        for(int cmd : commands){
            if(cmd==-1){
                dir=(dir+1)%4;
            }
            else if(cmd==-2){
                dir=(dir+3)%4;
            }
            else{
                for(int i=0;i<cmd;i++){
                    int nx=x+dirs[dir].first;
                    int ny=y+dirs[dir].second;
                    bool blocked=false;
                    for(auto &obs :obstacles){
                        if(obs[0]==nx && obs[1]==ny){
                            blocked=true;
                            break;
                        }
                    }
                    if(blocked)break;
                    x=nx;
                    y=ny;
                    maxDist=max(maxDist, x*x+y*y);
                }
            }
        }
        return maxDist;
    }
};