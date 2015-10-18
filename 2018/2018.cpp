#include <stdio.h>
#define MAXN 100005
#define max(a,b) ((a)>(b)?(a):(b))
int N,F,field[MAXN],sum[MAXN];
int f[MAXN];
void work(){
	scanf("%d %d",&N,&F);
	for(int i=1;i<=N;i++) scanf("%d",&field[i]);
	for(int i=1;i<=N;i++){
		sum[i]=sum[i-1]+field[i];
		for(int j=i-F+1;j>=1;j--){
			if(f[i]<1000.0*(sum[i]-sum[j]+field[j])/(1.0*i-j+1))
				f[i]=1000.0*(sum[i]-sum[j]+field[j])/(1.0*i-j+1);
		}
	}
	int res=0;
	for(int i=1;i<=N;i++){
		res=max(res,f[i]);
	}
	printf("%d\n",res);
}

int main()
{
	freopen("input.in","r",stdin);
	work();
	return 0;
}