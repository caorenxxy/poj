#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int maxn=10;
const int inf=0x3fffffff;
int next[6][2]={{-1,-1},{-1,0},{0,-1},{0,1},{1,0},{1,1}};
bool vis[maxn][maxn];
int mat[maxn][maxn];
int n,c;
struct pos
{
    int x,y;
    pos(int ii,int jj){x=ii;y=jj;}
};
bool can(pos temp)
{
    if(temp.x<0||temp.y<0||temp.x>=n||temp.y>temp.x)
              return 0;
    return 1;
}
void dfs(pos pre)
{
     pos sec(0,0);
     for(int i=0;i<6;i++)
     {
         sec.x=pre.x+next[i][0];
         sec.y=pre.y+next[i][1];
         if(!can(sec)) continue;
         if(vis[sec.x][sec.y]) continue;
         if(mat[pre.x][pre.y]!=mat[sec.x][sec.y]&&mat[pre.x][pre.y]!=0)
              continue;
         if(mat[sec.x][sec.y]==0) continue;
         if(mat[pre.x][pre.y]==0||mat[pre.x][pre.y]==mat[sec.x][sec.y])
          {
             vis[sec.x][sec.y]=1;
             dfs(sec);
            }
     }
}
int main()
{
    freopen("input.in","r",stdin);
    int sum,ans;
    while(1){
        scanf("%d%d",&n,&c);
        if(!n&&!c) break;
        memset(vis,0,sizeof(vis));
        memset(mat,0,sizeof(mat));
        for(int i=0;i<n;i++)
            for(int j=0;j<=i;j++)
        {
            scanf("%d",&mat[i][j]);
        }
        ans=-inf;
        for(int i=0;i<n;i++)
            for(int j=0;j<=i;j++)
        {memset(vis,0,sizeof(vis));
            sum=0;
            if(mat[i][j]==0)
            {
            mat[i][j]=c;
            for(int ii=0;ii<n;ii++)
                for(int jj=0;jj<=ii;jj++)
            {
                if(mat[ii][jj]==0){

                    dfs(pos(ii,jj));
                }
            }
            for(int ii=0;ii<n;ii++)
                for(int jj=0;jj<=ii;jj++)
            {
                if(mat[ii][jj] == 0|| vis[ii][jj]==true )
                                continue;
                if(mat[ii][jj] ==c)
                                sum--;
                else   sum++;
                printf("%d\n",sum);
            }
            mat[i][j]=0;
            ans=max(ans,sum);
        }
        }
       // printf("%d\n",ans);
    }
    return 0;
}