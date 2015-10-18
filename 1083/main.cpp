#include <stdio.h>
#include <string.h>
#define MAXN 202
int N,t,flag[MAXN+1],L[MAXN+1],R[MAXN+1];
int max(int a,int b){return a>b?a:b;}
void work(){
	scanf("%d",&t);
	while(t--){
		memset(flag,0,sizeof(flag));
		scanf("%d",&N);
		int l,r;
		for(int i=1;i<=N;i++){
			scanf("%d %d",&l,&r);
			if(l%2!=0) l++;
			l/=2;
			if(r%2!=0) r++;
			r/=2;
			if(l<r) {L[i]=l;R[i]=r;}
			else {L[i]=r;R[i]=l;}
			while(L[i]<=R[i]){
				flag[L[i]]+=10;
				L[i]++;
			}
		}
		
		
		int MAX=-1;
		for(int i=1;i<200;i++) {
			MAX=max(MAX,flag[i]);
		}
		printf("%d\n",MAX);
	}
}

int main()
{
	freopen("input.in","r",stdin);
	work();
	return 0;
}