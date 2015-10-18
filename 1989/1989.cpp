#include <stdio.h>
#include <string.h>
#define MAXN 100005
#define MAXK 10005
int N,K,num[MAXN],flag[MAXK];

int main()
{
	freopen("input.in","r",stdin);
	int res=0,sum=0;
	scanf("%d %d",&N,&K);
	for(int i=1;i<=N;i++) scanf("%d",&num[i]);
	for(int i=1;i<=N;i++){
		if(!flag[num[i]]){
			sum++;
			flag[num[i]]=1;
		}
		if(sum==K){
			res++;
			sum=0;
			memset(flag,0,sizeof(flag));
		}
	}
	printf("%d\n",res+1);
	return 0;
}