#include <stdio.h>
#define MAXN 15
#define MAX 100005
int f[MAX],ni[MAXN],dk[MAXN],v[MAX],cash,N,k=0;

void dp(){
	for(int i=1;i<=cash;i++) f[i]=0;
	for(int i=1;i<=k;i++){
		for(int j=cash;j>=v[i];j--){
			if(f[j-v[i]]+v[i]>f[j])
				f[j]=f[j-v[i]]+v[i];
		}
	}
}

void work(){
	while(scanf("%d %d",&cash,&N)!=EOF){	
		for(int i=1;i<=N;i++){
			scanf("%d %d",&ni[i],&dk[i]);
		}
		if(!cash || !N) {printf("%d\n",0);continue;}
		k=0;
		for(int i=1;i<=N;i++){
			int j=1;
			while(j<ni[i]){
				v[++k]=j*dk[i];
				ni[i]-=j;
				j*=2;
			}
			v[++k]=ni[i]*dk[i];
		}
		dp();
		printf("%d\n",f[cash]);
	}
}

int main()
{
	freopen("input.in","r",stdin);
	work();
	return 0;
}