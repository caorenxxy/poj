//f[i,j] (1,1)(i,j)中的棵树
#include <stdio.h>
#include <string.h>
#define MAXN 105
#define max(a,b) ((a)>(b)?(a):(b))
int N,W,H,S,T,mat[MAXN][MAXN],f[MAXN][MAXN];
int res;

void dp(){
	memset(f,0,sizeof(f));
	for(int i=1;i<=H;i++){
		for(int j=1;j<=W;j++){
			f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+mat[i][j];
		}
	}
}

bool judge(int i,int j){
	if(i<1 || i>H || j<1 || j>W) return false;
	return true;
}

void work(){
	int x,y;
	while(scanf("%d",&N)!=EOF && N){
		memset(mat,0,sizeof(mat));
		scanf("%d %d",&W,&H);
		for(int i=1;i<=N;i++){
			scanf("%d %d",&x,&y);
			mat[y][x]=1;
		}
		scanf("%d %d",&S,&T);
		dp();
		int num,ii,jj;
		res=0;
		for(int i=1;i<=H;i++){
			for(int j=1;j<=W;j++){
				ii=i+T-1;
				jj=j+S-1;
				if(!judge(ii,jj)) continue;
				num=f[ii][jj]-f[i-1][jj]-f[ii][j-1]+f[i-1][j-1];
				res=max(res,num);
			}
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