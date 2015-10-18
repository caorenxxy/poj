#include <stdio.h>
#include <string.h>
#define MAXN 1005
char a[MAXN],b[MAXN],c[MAXN];
int T,f[MAXN][MAXN],len1,len2,len;

void dp(){
	f[0][0]=1;
	if(a[0]==c[0]) f[1][0]=1;
	if(b[0]==c[0]) f[0][1]=1;
	for(int i=0;i<=len1;i++){
		for(int j=0;j<=len2;j++){
			if(i>=1 && a[i-1]==c[i+j-1])
				f[i][j]=f[i][j]||f[i-1][j];
			if(j>=1 && b[j-1]==c[i+j-1])
				f[i][j]=f[i][j]||f[i][j-1];
		}
	}
}

void work(){
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%s %s %s",a,b,c);
		memset(f,0,sizeof(f));
		len1=strlen(a);
		len2=strlen(b);
		len=strlen(c);
		dp();
		printf("Data set %d: ",t);
		if(f[len1][len2]) printf("yes\n");
		else printf("no\n");
	}
	
}

int main()
{
	freopen("input.in","r",stdin);
	work();
	return 0;
}