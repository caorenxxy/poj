//odd,even
//odd f[i,0]=max{f[i-1,0],f[i-1,1]+a[i]}
//even f[i,1]=max{f[i-1,1],f[i-1,0]-a[i]}
#include <stdio.h>
#define MAXN 150005
#define max(a,b) ((a)>(b)?(a):(b))
int p,a[MAXN],f[MAXN][2];

void work(){
	scanf("%d",&p);
	for(int i=1;i<=p;i++) scanf("%d",&a[i]);
	f[0][0]=f[0][1]=0;
	f[1][0]=a[1];
	f[1][1]=0;
	for(int i=2;i<=p;i++){
		f[i][0]=max(f[i-1][0],f[i-1][1]+a[i]);
		f[i][1]=max(f[i-1][1],f[i-1][0]-a[i]);
	}
	printf("%d\n",max(f[p][0],f[p][1]));
}

int main()
{
	freopen("input.in","r",stdin);
	work();
	return 0;
}