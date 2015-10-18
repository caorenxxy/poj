#include <stdio.h>
#include <string.h>
#define MAXN 1000001
#define max(a,b) ((a)>(b)?(a):(b))
char A[MAXN],B[MAXN];

void work(){
	while(scanf("%s %s",A,B)!=EOF){
		int lena=strlen(A),lenb=strlen(B);
		int i=0,j=0;
		while(A[i] && B[j]){
			if(A[i]==B[j]) {
				i++;j++;
			}
			else j++;
			if(i==lena) break;
		}
		if(i==lena) printf("Yes\n");
		else printf("No\n");
	}
}

int main()
{
	freopen("input.in","r",stdin);
	work();
	return 0;
}