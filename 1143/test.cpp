#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAX(a,b) (a) > (b)? (a):(b)
#define MIN(a,b) (a) < (b)? (a):(b)
#define mem(a) memset(a,0,sizeof(a))
#define INF 1000000007
#define MAXN 1<<20
#define MACN 20

#define JUDGE (((1<<(ma[j]-ma[i]-1)) & ~st) &&(ma[j]-ma[i] != 1)) || (!((ma[j]+1)%(ma[i]+1)))

using namespace std;

int DP[MAXN],ma[MACN],vis[MAXN];
int N;
int judge(int i,int j,int st){
    if(  (((1<<(ma[j]-ma[i]-1)) & ~st)&&(ma[j]-ma[i]!=1)) || (!((ma[j])%(ma[i]))) )
        return 1;
    return 0;
}
int  search(int k,int state)
{
    if(vis[state])return DP[state];
    vis[state]=1;
    if(state == 0)return 0;
    if(k == 1)return DP[state] = 1;//集合里面只有一个数了，一定是必胜状态
    int i, j, key=0;
    for(i = 0;i < N;i ++ )
    {
        int st = state;
        if((1<<(ma[i]-1)) & state)
        {
            for(j = i+1; j < N; j ++ )//首先去掉ma[i]的倍数和（ma[j]-ma[i]）已经使用了的ma[j]
            {
                if( ((1<<(ma[j]-1)) & st) && judge(i,j,st) )
                {
                    st ^= (1<<(ma[j]-1));
                }
            }
            key = search(k-1, st^(1<<(ma[i]-1)));
            if( !key )return DP[state]=1;//一旦下一个状态有必输的状态，那这个状态就是必胜的
        }
    }
    return DP[state]=0;
}

int main()
{
    freopen("input.in","r",stdin);
    int cas=1;
    while(~scanf("%d",&N) && N)
    {
        mem(vis);
        int i,j,state=0;
        int ans[MACN]={0},count=0;

        for(i=0;i<N;i++)
        {
            scanf("%d",&ma[i]);
           // ma[i]--;
            state ^= (1<<(ma[i]-1));//初始化状态集合state
        }

        sort(ma,ma+N-1);
        for(i = 0; i < N; i ++ )
        {
            int st = state;
            for(j = i+1; j < N; j ++ )
            {
                if(judge(i,j,st)) st ^= (1<<(ma[j]-1));
            }
            if(search(N-1, (1<<(ma[i]-1))^st) == 0)
            {
                ans[count++] = ma[i];
            }
        }

        printf("Test Case #%d\n", cas++);
        if(!count)printf("There's no winning move.\n\n");
        else {
            printf("The winning moves are:");
            for(i=0;i<count;i++)
                printf(" %d", ans[i]);
            printf("\n\n");
        }
    }
    return 0;
}