#include <stdio.h>
#include <string.h>
#define MAX 1005
#define MAXN 1000005
#define inf 999999
int n,m,k;
int A[MAX],C[MAX],v[MAXN],f[MAXN],ans[MAXN],res;

void work(){

	for(int i=0;i<=m;i++) f[i]=0;
	f[0]=1;
	for(int i=1;i<=k;i++){
		for(int j=m;j>=0;j--){
			if(j>=v[i]){
				if(f[j-v[i]]==1)
					f[j]=1;
			}
		}
	}
	res=0;
	for(int i=1;i<=m;i++) res+=f[i];
	printf("%d\n",res );
}
void init(){
	
	while(scanf("%d %d",&n,&m)!=EOF && n && m){
		k=0;
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;i++) scanf("%d",&A[i]);
		for(int i=1;i<=n;i++) scanf("%d",&C[i]);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=C[i];j++)
				v[++k]=A[i];
		}
		work();
	}
}

int main()
{
	freopen("input.in","r",stdin);
	init();

	return 0;
}