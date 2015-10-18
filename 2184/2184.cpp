//f[i,j] 前i个奶牛的S值为j时，F的最大值
//f[i,j]=max{f[i-1][j],f[i-1][j-Si]+Fi}
#include <stdio.h>
#include <string.h>
#define MAXN 1005
#define MAXM 200005
#define inf 0x3f3f3f3f
#define max(a,b) ((a)>(b)?(a):(b))
int N,f[MAXM],S[MAXN],F[MAXN];

void init(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d %d",&S[i],&F[i]);
}

void work(){
	for(int i=0;i<=200000;i++) f[i]=-inf;
	f[100000]=0;
	for(int i=1;i<=N;i++){
		if(S[i]<=0 && F[i]<=0) continue;
		
		if(S[i]>0){
			for(int j=200000;j>=S[i];j--){
				f[j]=max(f[j],f[j-S[i]]+F[i]);
			}
		}
		else{
			for(int j=0;j<=200000+S[i];j++){
				f[j]=max(f[j],f[j-S[i]]+F[i]);
			}
		}

	}
	int ans=0;
	for(int i=100000;i<=200000;i++){
		 if(f[i]>=0 && f[i]+i-100000>ans)
		 	ans=f[i]+i-100000;
	}
	printf("%d\n",ans);
}	

int main()
{
	freopen("input.in","r",stdin);
	init();
	work();
	return 0;
}