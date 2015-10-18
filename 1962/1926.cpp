#include <stdio.h>
#include <string.h>
#define MOD 1000
#define MAXN 20005
#define abs(a) ((a)>0?(a):-(a))
int T,n,pa[MAXN],dis[MAXN];

int find(int x){
	if(pa[x]==x) return x;
	else {
		int parent=find(pa[x]);
		dis[x]+=dis[pa[x]];
		pa[x]=parent;
		return pa[x];
	}
}

void work(){
	char ch;
	int u,v;
	scanf("%d",&T);
	while(T--){
		memset(dis,0,sizeof(dis));
		scanf("%d",&n);
		for(int i=1;i<=n;i++) pa[i]=i;
		while(scanf("%c",&ch)!=EOF && ch!='O'){
			if(ch=='I') {
				scanf("%d %d",&u,&v);
				pa[u]=v;
				dis[u]=(abs(u-v))%MOD;
			}
			else if(ch=='E'){
				scanf("%d",&u);
				find(u);
				printf("%d\n",dis[u]);
			}
		}
	}
}

int main()
{
	freopen("input.in","r",stdin);
	work();
	return 0;
}