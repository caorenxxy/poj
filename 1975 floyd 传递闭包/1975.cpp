//floyd 传递闭包
#include <stdio.h>
#include <string.h>
#define MAXN 110
int mat[MAXN][MAXN];
int t,n,m;

void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(mat[i][j]==1 || (mat[i][k]==1 && mat[k][j]==1))
					mat[i][j]=1;
				if(mat[i][j]==-1 || (mat[i][k]==-1 && mat[k][j]==-1))
					mat[i][j]=-1;
			}
		}
	}
}

void work(){
	int u,v,res,sum1,sum2;
	scanf("%d",&t);
	while(t--){
		memset(mat,0,sizeof(mat));
		scanf("%d %d",&n,&m);
		for(int i=0;i<m;i++){
			scanf("%d %d",&u,&v);
			mat[u][v]=1;
			mat[v][u]=-1;
		}
		floyd();
		res=0;
		for(int i=1;i<=n;i++){
			sum1=0;sum2=0;
			for(int j=1;j<=n;j++){
				if(mat[i][j]==1) sum1++;
				if(mat[i][j]==-1) sum2++;
			}
			if(sum1>=(n+1)/2 || sum2>=(n+1)/2) res++;
		}
		printf("%d\n",res);
	}
}

int main()
{
	freopen("input.in","r",stdin);
	work();
	return 0;
}