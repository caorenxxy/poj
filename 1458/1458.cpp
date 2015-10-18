#include <stdio.h>
#include <string.h>
#define MAX 1000
#define max(a,b) ((a)>(b)?(a):(b))
char a[MAX],b[MAX];
int f[MAX][MAX];

void dp(){
	int n1=strlen(a),n2=strlen(b);
	for(int i=1;i<=n1;i++) f[i][0]=0;
	for(int i=1;i<=n2;i++) f[0][i]=0;	
	f[0][0]=0;
	for(int i=1;i<=n1;i++){
		for(int j=1;j<=n2;j++){
			if(a[i-1]==b[j-1]) f[i][j]=f[i-1][j-1]+1;
			else{
				f[i][j]=max(f[i-1][j],f[i][j-1]);
			}
		}
	}
}

void work(){
	while(scanf("%s %s",a,b)!=EOF){
		int n1=strlen(a),n2=strlen(b);
		dp();
		printf("%d\n",f[n1][n2]);
	}
}

int main()
{
	freopen("input.in","r",stdin);
	work();
	return 0;
}