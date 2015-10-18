#include <stdio.h>
#include <string.h>
#define MAX 12
#define inf 0x3f3f3f3f
#define max(a,b) ((a)>(b)?(a):(b))
int mat[MAX][MAX],vis[MAX][MAX];
int move[6][2]={{-1,-1},{-1,0},{0,-1},{0,1},{1,0},{1,1}};
int N,C,sum;

bool judge(int x,int y){
	if(x<1 || x>N || y<1 || y>x) return false;
	return true;
}

void dfs(int x,int y){
	for(int i=0;i<6;i++){
		int xx=x+move[i][0];
		int yy=y+move[i][1];
		if(!judge(xx,yy)) continue;
		if(vis[xx][yy]) continue;
		if(mat[x][y]!=mat[xx][yy] && mat[x][y]!=0) continue;
		if(mat[xx][yy]==0) continue;
		if(mat[x][y]==0 || mat[x][y]==mat[xx][yy]){
			vis[xx][yy]=1;
			dfs(xx,yy);
		}
	}
}

void work(){
	while(scanf("%d %d",&N,&C)!=EOF && N && C){
		int ans=-inf;
		for(int i=1;i<=N;i++)
			for(int j=1;j<=i;j++)
				scanf("%d",&mat[i][j]);
		for(int i=1;i<=N;i++){
			for(int j=1;j<=i;j++){
				memset(vis,0,sizeof(vis));
				sum=0;
				if(!mat[i][j]){
					mat[i][j]=C;
					for(int ii=1;ii<=N;ii++){
						for(int jj=1;jj<=ii;jj++){
							if(mat[ii][jj]==0){
								dfs(ii,jj);
							}
						}
					}
					for(int ii=1;ii<=N;ii++){
						for(int jj=1;jj<=ii;jj++){
							if(mat[ii][jj]==0 || vis[ii][jj]) continue;
							if(mat[ii][jj]==C) sum--;
							else sum++;
						}
					}
					mat[i][j]=0;
					ans=max(ans,sum);
				}
			}
		}
		printf("%d\n",ans);
	}
}

int main()
{
	freopen("input.in","r",stdin);
	work();
	return 0;
}