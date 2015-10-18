#include <stdio.h>
#include <string.h>
#define MAXN 101
int mat[MAXN][MAXN],num[MAXN],f[MAXN];
int n;
int max(int a,int b){return a>b?a:b;}
void init(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&mat[i][j]);
}

int dp(){
	memset(f,0,sizeof(f));
	f[0]=num[0];
	for(int i=1;i<n;i++){
		if(f[i-1]+num[i]>num[i]) f[i]=f[i-1]+num[i];
		else f[i]=num[i];
	}
	int MAX=-999999;
	for(int i=0;i<n;i++) MAX=max(MAX,f[i]);
	return MAX;
}

void work(){
	int ans=-99999999;
	for(int i=0;i<n;i++){
		memset(num,0,sizeof(num));
		for(int j=i;j<n;j++){
			for(int k=0;k<n;k++){
				num[k]+=mat[j][k];
			}

			ans=max(ans,dp());
		}
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