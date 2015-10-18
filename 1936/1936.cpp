#include <stdio.h>
#include <string.h>
#define MAXN 10001
#define max(a,b) ((a)>(b)?(a):(b))
char A[MAXN],B[MAXN];
int f[MAXN][MAXN];

void dp(){
	for(int i=0;A[i]!='\0';i++) f[i+1][0]=0;
	for(int i=0;B[i]!='\0';i++) f[0][i+1]=0;
	f[0][0]=0;
	int lena=strlen(A),lenb=strlen(B);
	for(int i=1;i<=lena;i++){
		for(int j=1;j<=lenb;j++){
			if(A[i-1]==B[j-1]) f[i][j]=f[i-1][j-1]+1;
			else{
				f[i][j]=max(f[i-1][j],f[i][j-1]);
			}
		}
	}
}

void work(){
	while(scanf("%s %s",A,B)!=EOF){
		int lena=strlen(A),lenb=strlen(B);
		dp();
		if(f[lena][lenb]==lena) printf("Yes\n");
		else printf("No\n");
	}
}

int main()
{
	freopen("input.in","r",stdin);
	work();
	return 0;
}