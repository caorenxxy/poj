/*
多重背包 单调队列优化
*/
#include <stdio.h>
#include <string.h>

int a[1005],b[1005],dp[100005];
int w,v,c,n,V,l,r;
void insert(int x,int y)
{
	while(l<=r&&b[r]<=y)r--;
	a[++r]=x;b[r]=y;
}
int main()
{
	freopen("input.in","r",stdin);
	while(scanf("%d%d",&V,&n)!=EOF)
	{
		int i,j,d;
		memset(dp,0,sizeof(dp));	
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&c,&v);
			w=v;
			if(V/v<c)
				c=V/v;
			for(d=0;d<v;d++)
			{
				l=1;
				r=0;
				for(j=0;j<=(V-d)/v;j++)
				{
					insert(j,dp[j*v+d]-j*w);
					if(a[l]<j-c)l++;
					dp[j*v+d]=b[l]+j*w;
				}
			}
		}
		printf("%d\n",dp[V]);
	}
	return 0;
}
