#include <stdio.h>
#include <string.h>
#define MAX 100
int n,hashtab[MAX+1];
int main(){
	freopen("input.in","r",stdin);
	int num;
	while(scanf("%d",&n)!=EOF && n){
		memset(hashtab,0,sizeof(hashtab));
		for(int i=0;i<n;i++){
			scanf("%d",&num);
			hashtab[num]++;
		}
		if(n%2==0){
			int j;
			for(j=1;j<=MAX;j++){
				if(hashtab[j]>0 && hashtab[j]%2!=0){
					printf("1\n");
					break;
				}
			}
			if(j==MAX+1) printf("0\n");
		}
		else printf("1\n");
	}
}