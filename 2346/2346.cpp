#include <stdio.h>
#define MAXN 12
int N,f[MAXN][50];

void init(){
	scanf("%d",&N);
}

void dp(){
	int bit=N/2;
	for(int i=0;i<=9;i++) f[1][i]=1;
	for(int i=2;i<=bit;i++){
		for(int j=0;j<=45;j++){
			for(int k=0;k<=9;k++){
				f[i][j]+=f[i-1][j-k];
			}
		}
	}
}

void work(){
	int res=0;
	dp();
	for(int i=0;i<=45;i++){
		res+=f[N/2][i]*f[N/2][i];
	}
	if(N%2==0){
		printf("%d\n",res);
	}
	else{
		printf("%d\n",res*9);
	}
}

int main()
{
	freopen("input.in","r",stdin);
	init();
	work();
	return 0;
}