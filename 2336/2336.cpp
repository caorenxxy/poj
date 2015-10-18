//f[i]=min{ max{f[i-1]+t,time[t]},max{f[i-2]+t,time[t]},...,max{f[i-n]+t,time[t]} }
//f[i] 1---i辆车时的最短时间，决策：和前0,1,2,...,n一起运
#include <stdio.h>
#include <string.h>
#define MAXN 1445
#define inf 0x3f3f3f3f
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
int c,n,t,m,time[MAXN],f[MAXN],g[MAXN];

void dp(){
	f[0]=-t;
	f[1]=time[1]+t;
	g[1]=1;
	for(int i=2;i<=m;i++){
		f[i]=inf;
		for(int j=max(0,i-n);j<i;j++){
			int tmp=max(f[j]+t,time[i])+t;
			if(tmp<f[i]){
				f[i]=tmp;
				g[i]=g[j]+1;
			}
		} 
	}
}

void work(){
	scanf("%d",&c);
	while(c--){
		scanf("%d %d %d",&n,&t,&m);
		for(int i=1;i<=m;i++) scanf("%d",&time[i]);
		dp();
		printf("%d %d\n",f[m],g[m]);
	}
}

int main()
{
	freopen("input.in","r",stdin);
	work();
	return 0;
}