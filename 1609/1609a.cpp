#include <stdio.h>
#include <algorithm>
#define MAXN 10005
#define MAX 105
#define max(a,b) ((a)>(b)?(a):(b))
int n,f[MAXN];
struct block{
	int l,m;
}num[MAXN];

int cmp(const void*a,const void*b)
{
	if(((block*)a)->l-((block*)b)->l)return ((block*)a)->l-((block*)b)->l;
	else return ((block*)a)->m-((block*)b)->m;
}

void dp(){
	f[1]=1;
	for(int i=2;i<=n;i++){
		f[i]=1;
		for(int j=1;j<i;j++){
			if(num[i].l>=num[j].l && num[i].m>=num[j].m){
				f[i]=max(f[i],f[j]+1);
			}
		}
	}
}

void work(){
	while(scanf("%d",&n)!=EOF && n){
		for(int i=1;i<=n;i++) scanf("%d %d",&num[i].l,&num[i].m);
		qsort(num+1,n,sizeof(block),cmp);
		dp();
		int res=1;
		for(int i=1;i<=n;i++) res=max(res,f[i]);
		printf("%d\n",res);
	}
	printf("*\n");
}

int main()
{
	freopen("input.in","r",stdin);
	work();
	return 0;
}