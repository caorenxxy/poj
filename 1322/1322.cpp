#include <stdio.h>
#include <string.h>
#define MAX 1010
#define MAXC 101
#define min(a,b) ((a)<(b)?(a):(b))
int C,N,M;
float f[MAX][MAXC];

void dp(){
	memset(f,0,sizeof(f));
	for(int i=1;i<=C;i++) f[0][i]=0;
	f[0][0]=1.0;
	for(int i=1;i<=N;i++){
		for(int j=0;j<=min(i,C);j++){
			if(j>0){
				f[i][j]=f[i-1][j+1]*((j+1.0)/C)+f[i-1][j-1]*((C-j+1.0)/C);
			}
			else f[i][j]=f[i-1][j+1]*((j+1.0)/C);
		}
	}
}

void work(){
	while(scanf("%d",&C)!=EOF && C){
		scanf("%d %d",&N,&M);
		if(M>C || M>N || (M+N)%2) printf("%.3f\n",0);
		else{
			if(N>1000) N=1000+N%2;
			dp();
			printf("%.3f\n",f[N][M]);
		}
		
	}

}
int main()
{
	freopen("input.in","r",stdin);
	work();
	return 0;
}