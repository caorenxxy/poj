#include <stdio.h>
#define MAXN 500005
int a[MAXN];
int mat[8000005];
void cal(int k){
	a[0]=0;
	for(int i=1;i<=k;i++){
		if(a[i-1]-i>0 && mat[a[i-1]-i]==0)
		{
			a[i]=a[i-1]-i;
			mat[a[i]]=1;
		} 
		else{
			a[i]=a[i-1]+i;
			mat[a[i]]=1;
		}
	}
}

int main()
{
	int k;
	cal(500000);
	while(scanf("%d",&k)!=EOF && k!=-1){
		printf("%d\n",a[k]);
	}
	return 0;
}