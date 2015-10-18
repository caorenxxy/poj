#include <stdio.h>
#include <string.h>
#define MAXN 5005
int N,num[MAXN],f[MAXN],g[MAXN];

void dp(){
	f[1]=1;
	g[1]=1;
	for(int i=2;i<=N;i++)
	{
		f[i]=g[i]=1;
		for(int j=i-1;j>=1;j--)
		{
			if(num[i]<num[j])
			{
				if(f[i]<f[j]+1)
				{
					f[i]=f[j]+1;
					g[i]=g[j];
				}
				else if(f[i]==f[j]+1)
				{
					g[i]+=g[j];
				}
			}
			else if(num[i]==num[j])
			{
				if(f[i]==1)
				{
					g[i]=0;
				}
				break;
			}
		}
	}
}

void work(){
	int res=0,number=0;
	dp();
	for(int i=1;i<=N;i++){
		if(res<f[i]){
			res=f[i];
		}
	}
	for(int i=1;i<=N;i++){
		if(f[i]==res) number+=g[i];
	}
	printf("%d %d\n",res,number);
}

int main()
{
	freopen("input.in","r",stdin);
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&num[i]);
	memset(f,0,sizeof(f));
	work();
	return 0;
}