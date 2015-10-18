#include <stdio.h>
#include <string.h>
#define MAX 55
#define inf 99999999
int N,ver[MAX],op_n[MAX],ver_n[MAX];
char op[MAX];
int MMAX,MMIN,dp_min[MAX][MAX],dp_max[MAX][MAX],res[MAX];
int Min(int a,int b,int c,int d)
{
	int m=a;
	if(m>b)
	{
		m=b;
	}
	if(m>c)
	{
		m=c;
	}
	if(m>d)
	{
		m=d;
	}
	return m;
}

int Max(int a,int b,int c,int d)
{
	int m=a;
	if(m<b)
	{
		m=b;
	}
	if(m<c)
	{
		m=c;
	}
	if(m<d)
	{
		m=d;
	}
	return m;
}

void init(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf(" %c",&op[i]);
		scanf(" %d",&ver[i]);
	}
	for(int i=0;i<N;i++){
		printf("%c %d ",op[i],ver[i]);
	}
	printf("\n");
}

void dp(){
	for(int l=2;l<=N;l++){
		for(int i=0;i<N-l;i++){
			int j=i+l-1;
			MMAX=inf;MMIN=-inf;
			for(int k=i;k<=j-1;k++){
				if(op_n[k]=='t'){
					dp_min[i][j]=dp_min[i][k]+dp_min[k+1][j];
					dp_max[i][j]=dp_max[i][k]+dp_max[k+1][j];
					if(MMAX<dp_max[i][j]) MMAX=dp_max[i][j];
					if(MMIN<dp_min[i][j]) MMIN=dp_min[i][j];
				}
				else{
					dp_min[i][j]=min(dp_min[i][k]*dp_min[k+1][j],dp_min[i][k]*dp_max[k+1][j],dp_max[i][k]*dp_max[k+1][j],dp_max[i][k]*dp_min[k+1][j]);
					dp_max[i][j]=max(dp_min[i][k]*dp_min[k+1][j],dp_min[i][k]*dp_max[k+1][j],dp_max[i][k]*dp_max[k+1][j],dp_max[i][k]*dp_min[k+1][j]);
					if(MMAX<dp_max[i][j]) MMAX=dp_max[i][j];
					if(MMIN<dp_min[i][j]) MMIN=dp_min[i][j];
				}
			}
			dp_min[i][j]=MMIN;
			dp_max[i][j]=MMAX;
		}
	}
}

void work(){
	for(int i=0;i<N;i++){
		memset(ver_n,0,sizeof(ver));
		memset(op_n,0,sizeof(op_n));
		int s=i-1,t=i,p=0;
		while(s>=0){ver_n[p]=ver[s];p++;s--;}
		while(t<N){ver_n[p]=ver[t];p++;t++;}
		p=0;s=i-1;t=i+1;
		while(s>=0){op_n[p]=op[s];p++;s--;}
		while(t<N){op_n[p]=op[t];p++;t++;}
		dp();
		res[i]=dp_max[0][p];
	}
}

int main()
{
	freopen("input.in","r",stdin);
	init();
	work();
	return 0;
}