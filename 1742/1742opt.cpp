#include <stdio.h>
#define MAX 110
#define MAXN 100010
int A[MAX],C[MAX];
int a[MAXN],f[MAXN],s,t;
int n,m;
void work(){
	while(scanf("%d %d",&n,&m)!=EOF && n && m){
		for(int i=1;i<=n;i++) scanf("%d",&A[i]);
		for(int i=1;i<=n;i++) scanf("%d",&C[i]);
		for(int i=1;i<=m;i++) f[i]=0;
		f[0]=1;
		int res=0;
		for(int i=1;i<=n;i++){
			if(1==C[i]){
				for(int j=m;j>=A[i];j--){
					if(!f[j] && f[j-A[i]]) 
					{
						res++;
						f[j]=1;
					}
				}
				continue;
			}
			if(A[i]*C[i]>=m){
				for(int j=A[i];j<=m;j++){
					if(!f[j] && f[j-A[i]]){
						res++;
						f[j]=1;
					}
				}
				continue;
			}
			for(int d=0;d<A[i];d++){
				s=0;t=-1;
				int sum=0;
				for(int j=d;j<=m;j+=A[i]){
					if(t-s==C[i]) sum-=a[s++];
					a[++t]=f[j];
					sum+=f[j];
					if(!f[j] && sum){
						res++;
						f[j]=1;
					}
				}
			}

		}
		printf("%d\n",res);
	}
		
}
int main()
{
	freopen("input.in","r",stdin);
	work();
	return 0;
}