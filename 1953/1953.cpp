#include <stdio.h>
#define MAXM 50
int n,m,f[MAXM][2];

void dp() {
	f[0][0]=f[0][1]=0;
	f[1][0]=1;
	f[1][1]=1;
	for(int i=2;i<=m;i++){
		f[i][0]=f[i-1][0]+f[i-1][1];
		f[i][1]=f[i-1][0];
	}
}

void work() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&m);
		dp();
		printf("Scenario #%d:\n%d\n\n",i,f[m][0]+f[m][1]);
	}
}

int main()
{
	freopen("input.in","r",stdin);
	work();
	return 0;
}