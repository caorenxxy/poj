#include <stdio.h>
#include <string.h>
#define MAX 60
#define inf 0x3f3f3f3f
//f[i,j]  j turns get position i

int T,t,m,line[MAX];
float f[MAX][MAX];

void dp(){
	memset(f,0,sizeof(f));
	f[0][0]=1.0;
	for(int j=0;j<=t;j++){
		for(int i=0;i<=m;i++){
			if(line[i+1]==inf)
				f[i+1][j+2]+=f[i][j]*0.5;
			else
				f[i+1+line[i+1]][j+1]+=f[i][j]*0.5;
			if(line[i+2]==inf)
				f[i+2][j+2]+=f[i][j]*0.5;
			else
				f[i+2+line[i+2]][j+1]+=f[i][j]*0.5;
		}
	}
	for(int i=0;i<t;i++) f[m+1][t]+=f[m+1][i];
}

void work(){
	char str[10];
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&m,&t);
		line[0]=0;line[m+1]=0;line[m+2]=-1;
		for(int i=1;i<=m;i++){
			if(scanf("%d",&line[i])==0){
				scanf("%s",str);
				line[i]=inf;	
			}
		}
		dp();
		if(f[m+1][t]>0.5) printf("Bet for. %.4f\n",f[m+1][t]); 
		else if(f[m+1][t]<0.5) printf("Bet against. %.4f\n",f[m+1][t]);
		else printf("Push. 0.5000\n");
	}
}

int main()
{
	freopen("input.in","r",stdin);
	work();
	return 0;
}