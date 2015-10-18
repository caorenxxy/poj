//f[i,j]=min{ f[i-1,j],f[i,j-1],f[i,j+1] }+a[i,j]
#include <stdio.h>
#include <string.h>
#define MAXM 105
#define MAXN 505
#define inf 0x3fffffff
typedef long long LL;
int m,n,pre[MAXM][MAXN];
LL mat[MAXM][MAXN],f[MAXM][MAXN];
void init(){
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&mat[i][j]);
		}
	}
}

void dp(){
	for(int i=1;i<=n;i++) {
		f[1][i]=mat[1][i];
		pre[1][i]=0;
	}
	for(int i=2;i<=m;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=f[i-1][j]+mat[i][j];
			pre[i][j]=-2;
			if(j==1) continue;
			if(f[i][j]>f[i][j-1]+mat[i][j]){
				f[i][j]=f[i][j-1]+mat[i][j];
				pre[i][j]=-1;
			}
		}
		for(int j=n;j>=1;j--){
			if(j==n) continue;
			if(f[i][j]>f[i][j+1]+mat[i][j]){
				f[i][j]=f[i][j+1]+mat[i][j];
				pre[i][j]=1;
			}
		}
	}
}

void print(int i,int j){
	if(0==pre[i][j]){
		printf("%d\n",j);
		return ;
	}
	else if(-2==pre[i][j]){
		print(i-1,j);
		printf("%d\n",j);
	}
	else if(-1==pre[i][j]){
		print(i,j-1);
		printf("%d\n",j);
	}
	else{
		print(i,j+1);
		printf("%d\n",j);
	}
}

void work(){
	LL res=inf;
	int pos;
	dp();
	for(int i=1;i<=n;i++){
		if(f[m][i]<res){
			res=f[m][i];
			pos=i;
		}
	}
	print(m,pos);
}

int main()
{
	freopen("input.in","r",stdin);
	init();
	work();
	return 0;
}