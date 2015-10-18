#include <stdio.h>
#include <string.h>
#define inf 0x3f3f3f3f
#define MAXN 15
#define min(a,b) ((a)<(b)?(a):(b))
int g[MAXN];
int f(int k){
	
	return (1<<k)-1;
}

void dp(int n){
	g[1]=1;
	for(int i=2;i<=n;i++){
		for(int k=1;k<=i-1;k++){
			g[i]=min(g[i],2*g[i-k]+f(k));
		}
	}
}

int main()
{
	memset(g,inf,sizeof(g));
	dp(12);
	for(int i=1;i<=12;i++) printf("%d\n",g[i]);
	return 0;
}