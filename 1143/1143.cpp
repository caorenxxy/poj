#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#define numX(a,b) (a) > (b)? (a):(b)
#define MIn(a,b) (a) < (b)? (a):(b)
#define InF 1000000007
using namespace std;
int n,state,dp[1<<20],vis[20],num[20];

int judge(int i,int j,int st){
    if(  (((1<<(num[j]-num[i]-1)) & ~st)&&(num[j]-num[i]!=1)) || (!((num[j])%(num[i]))) )
        return 1;
    return 0;
}

int dfs(int st,int cnt){
	if(vis[st]) return dp[st];
	vis[st]=1;
	if(st==0) return 0;
	if(cnt==1) return dp[st]=1;
	int ans=0;
	for(int i=0;i<n;i++){
		int st_tmp=st;
		if( (1<<(num[i]-1)) & st ){
			for(int j=i+1;j<n;j++){
				if( ((1<<(num[j]-1)) & st_tmp) && judge(i,j,st_tmp) ){
					st_tmp^=(1<<(num[j]-1));
				}
			}
			ans=dfs(st_tmp^(1<<(num[i]-1)),cnt-1);
			if(!ans) return dp[st]=1;
		}
	}
	return dp[st]=0;
}


void work(){
	int t=0;
	while(scanf("%d",&n)!=EOF && n){
		t++;
		int res[20]={0};
		memset(vis,0,sizeof(vis));
		memset(dp,0,sizeof(dp));
		state=0;
		for(int i=0;i<n;i++){
			scanf("%d",&num[i]);
			state|=(1<<(num[i]-1));
		}
		sort(num,num+n-1);
		int count=0;
		for(int i=0;i<n;i++){
			int st=state;
			for(int j=i+1;j<n;j++){
				if(judge(i,j,st)) st^=(1<<(num[j]-1));
			}
			if( dfs((1<<(num[i]-1))^st,n-1)==0 ){
				res[count++]=num[i];
			}
		}
		printf("Test Case #%d\n",t);
		if(!count) printf("There's no winning move.\n\n");
		else {
			printf("The winning moves are: ");
			for(int i=0;i<count;i++) printf("%d ",res[i]);
			printf("\n\n");
		}

	}
}
int main()
{
	freopen("input.in","r",stdin);
	work();
	return 0;
}