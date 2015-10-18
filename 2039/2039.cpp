#include <stdio.h>
#define MAXN 205

char str[MAXN];
char mat[MAXN][MAXN];
int col;

void work(){
	while(scanf("%d",&col)!=EOF && col){
		scanf("%s",str);
		int i,j=0,k=0,sum=0;
		int flag=1;
		for(i=0;str[i];i++){
			mat[k][j]=str[i];
			sum++;
			if(flag>0) j++;
			else if(flag<0) j--;
			if(sum==col){
				if(flag>0) j--;
				else j++;
				flag*=-1;
				sum=0;
				k++;
			}
		}
		for(int i=0;i<col;i++){
			for(j=0;j<k;j++){
				printf("%c",mat[j][i]);
			}
		}
		printf("\n");
	}
}

int main()
{
	freopen("input.in","r",stdin);
	work();
	return 0;
}