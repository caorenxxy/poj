#include <stdio.h>
#include <string.h>
#define MAXN 15
#define max(a,b) ((a)>(b)?(a):(b))
int N,money,year,d,c[MAXN],w[MAXN],f[50005],ans;

void dp(){
	for(int i=1;i<=d;i++){
		for(int j=c[i];j<=ans;j++){
			f[j]=max(f[j],f[j-c[i]]+w[i]);
		}
	}
}

void work(){
	scanf("%d",&N);
	while(N--){
		scanf("%d %d",&money,&year);
		scanf("%d",&d);
		for(int i=1;i<=d;i++){
			scanf("%d %d",&c[i],&w[i]);
			c[i]/=1000;
		}
		for(int t=1;t<=year;t++){
			ans=money/1000;
			memset(f,0,sizeof(f));
			dp();
			money+=f[ans];
		}
		printf("%d\n",money);
	}
}

int main()
{
	freopen("input.in","r",stdin);
	work();
	return 0;
}