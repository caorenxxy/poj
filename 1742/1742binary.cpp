#include <stdio.h>
#include <string.h>
#define MAX 1005
#define MAXN 100005
#define inf 999999
int binary[11]={1,2,4,8,16,32,64,128,256,512,1024};
int n,m,k;
int A[MAX],C[MAX],v[MAXN],f[MAXN],ans[MAXN],res;
void work(){

	for(int i=0;i<=m;i++) f[i]=0;
	//f[0]=1;
	for(int i=1;i<=k;i++){
		for(int j=m;j>=v[i];j--){
			if(f[j-v[i]]+v[i]>f[j])
				f[j]=f[j-v[i]]+v[i];
			//if(f[j-v[i]]==1) f[j]=1;
		}
	}
	res=0;
	for(int i=1;i<=m;i++) if(f[i]==i) res++;
	//for(int i=1;i<=m;i++) res+=f[i];
	printf("%d\n",res );

}
void init(){
	
	while(scanf("%d %d",&n,&m)!=EOF && n && m){
		k=0;
		int j;
		for(int i=1;i<=n;i++) scanf("%d",&A[i]);
		for(int i=1;i<=n;i++) scanf("%d",&C[i]);
		for(int i=1;i<=n;i++){
			j=1;
			while(j<C[i]){
				v[++k]=j*A[i];
				C[i]-=j;
				j*=2;
			}
			v[++k]=C[i]*A[i];
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