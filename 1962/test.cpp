#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#define max(a,b) (a>b?a:b)
#define abs(a) ((a)>0?(a):-(a))
#define min(a,b) (a<b?a:b)
using namespace std;
const int N=20005;
int n;
int root[N];
int dis[N];
char oper;
int query(int x)
{
	if(root[x]==x)
	{
		return x;
	}
	int ret=query(root[x]);
	dis[x]=(dis[x]+dis[root[x]]);//要在query函数之后，因为每次query函数都会更新dis值.
	root[x]=ret;
	return ret;
}
int main()
{
	freopen("input.in","r",stdin);
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		memset(dis,0,sizeof(dis));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			root[i]=i;
		while(getchar(),scanf("%c",&oper),oper!='O')
		{
			int x,y;
			if(oper=='E')
			{
				scanf("%d",&x);
				query(x);
				printf("%d\n",dis[x]);
			}
			else
			{
				scanf("%d%d",&x,&y);
				root[x]=y;
				dis[x]=(abs(x-y))%1000;
			}
		}
	}
	return 0;
}