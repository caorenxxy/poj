#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define MAX 102
int num[MAX][MAX],f[MAX][MAX],n;

void work(){
	int a,b;
	while(scanf("%d",&n)!=EOF && n){
		memset(num,0,sizeof(num));
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			scanf("%d %d",&a,&b);
			num[a][b]++;
		}
		for(int i=1;i<=100;i++){
			for(int j=1;j<=100;j++){
				f[i][j]=max(f[i-1][j],f[i][j-1])+num[i][j];
			}
		}
		printf("%d\n",f[100][100]);
	}
	printf("*\n");
}

int main()
{
	freopen("input.in","r",stdin);
	work();
	return 0;
}