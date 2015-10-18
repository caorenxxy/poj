#include <stdio.h>
#include <string.h>
#define MAX 105

int F,V,A[MAX][MAX],f[MAX][MAX];
int max(int a,int b){return a>b?a:b;}
void init(){
	scanf("%d %d",&F,&V);
	for(int i=1;i<=F;i++){
		for(int j=1;j<=V;j++){
			scanf("%d",&A[i][j]);
		}
	}
}

void dp(){
	memset(f,0,sizeof(f));
	for(int i=1;i<=F;i++){
		for(int j=1;j<=V;j++){
			f[i][j]=f[i-1][j-1]+A[i][j];
			if(j>i) f[i][j]=max(f[i][j],f[i][j-1]);
		}
	}
}
void work(){
	dp();
	printf("%d\n",f[F][V]);
}
int main()
{
	freopen("input.in","r",stdin);
	init();
	work();
	return 0;
}