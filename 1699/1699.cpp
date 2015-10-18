#include <stdio.h>
#include <string.h>
#define MAXN 25
#define inf 0x3f3f3f3f
#define min(a,b) ((a)<(b)?(a):(b))
int T,N,dp[MAXN][MAXN],vis[MAXN],res;
char input[MAXN][MAXN];

void EXKMP(int a,int b){
	char* str1=input[a];
	char* str2=input[b];
	int len1=strlen(str1),len2=strlen(str2);
	int next[MAXN],ex[MAXN];
	int i=0,po;
	//next
	next[0]=len2;
	while(str2[i]==str2[i+1]) i++;
	next[1]=i;
	po=1;
	for(i=2;i<len2;i++){
		if(i+next[i-po]<po+next[po]) next[i]=next[i-po];
		
		else{
			int j=po+next[po]-i;
			if(j<0) j=0;
			while(i+j<len2 && str2[i+j]==str2[j]) j++;
			next[i]=j;
			po=i;
		}
	}

	//exkmp
	i=0;
	while(str1[i]==str2[i] && i<len1 && i<len2){
		i++;
	}
	if(i==len1) {dp[a][b]=i;return ;}
	ex[0]=i;
	po=0;
	for(i=1;i<len1;i++){
		if(i+next[i-po]<po+ex[po]) ex[i]=next[i-po];
		else{
			int j=po+ex[po]-i;
			if(j<0) j=0;
			while(str1[i+j]==str2[j]) j++;
			ex[i]=j;
			po=i;
			if(ex[i]==len1-i){
				dp[a][b]=ex[i];
				break;
			}
		}
	}
}

void dfs(int i,int len,int n){
	if(n==N){
		if(res>len) res=len;
		return ;
	}
	for(int j=0;j<N;j++){
		if(i==j) continue;
		if(vis[j]) continue;
		if(len+strlen(input[j])-dp[i][j]>res) continue;
		vis[j]=1;
		dfs(j,len+strlen(input[j])-dp[i][j],n+1);
		vis[j]=0;
	}
}

void work(){
	scanf("%d",&T);
	while(T--){
		memset(dp,0,sizeof(dp));
		scanf("%d",&N);
		for(int i=0;i<N;i++) scanf("%s",input[i]);
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(i==j) continue;
				EXKMP(i,j);
			}
		}
		res=inf;
		for(int i=0;i<N;i++){
			vis[i]=1;
			dfs(i,strlen(input[i]),1);
			vis[i]=0;
		}
		printf("%d\n",res);
	}
}

int main()
{
	freopen("input.in","r",stdin);
	work();
	return 0;
}