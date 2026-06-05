class Solution {
public:
    struct Node{
        long long cnt;
        long long wav;
    };

    vector<int> dig;
    Node dp[16][11][11][4][2];
    bool vis[16][11][11][4][2];

    Node rec(int pos,int p2,int p1,int len,bool tight){
        int n=dig.size();

        if(pos==n){
            return {1,0};
        }

        if(!tight&&vis[pos][p2][p1][len][0]){
            return dp[pos][p2][p1][len][0];
        }

        int lim=tight?dig[pos]:9;
        Node res={0,0};

        for(int d=0;d<=lim;d++){
            bool nt=tight&&(d==lim);

            if(len==0){
                if(d==0){
                    Node child=rec(pos+1,10,10,0,nt);
                    res.cnt+=child.cnt;
                    res.wav+=child.wav;
                }
                else{
                    Node child=rec(pos+1,10,d,1,nt);
                    res.cnt+=child.cnt;
                    res.wav+=child.wav;
                }
            }
            else if(len==1){
                Node child=rec(pos+1,p1,d,2,nt);
                res.cnt+=child.cnt;
                res.wav+=child.wav;
            }
            else{
                int add=((p1>p2&&p1>d)||(p1<p2&&p1<d));
                Node child=rec(pos+1,p1,d,3,nt);
                res.cnt+=child.cnt;
                res.wav+=child.wav+1LL*add*child.cnt;
            }
        }

        if(!tight){
            vis[pos][p2][p1][len][0]=true;
            dp[pos][p2][p1][len][0]=res;
        }

        return res;
    }

    long long solve(long long x){
        if(x<=0) return 0;

        dig.clear();

        while(x){
            dig.push_back(x%10);
            x/=10;
        }
        reverse(dig.begin(),dig.end());
        memset(vis,0,sizeof(vis));
        Node ans=rec(0,10,10,0,1);
        return ans.wav;
    }

    long long totalWaviness(long long num1,long long num2){
        return solve(num2)-solve(num1-1);
    }
};