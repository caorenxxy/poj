#include <stdio.h>
#include <string.h>
#define MAX 8
#define MAXN 64
#define INF 0x3f3f3f3f
int mvk[8][2]={{-1,0},{1,0},{0,1},{0,-1},{-1,1},{-1,-1},{1,1},{1,-1}};
int mvkn[8][2]={{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2}};
char str[130];
int king[MAXN][MAXN],knight[MAXN][MAXN];
int arthur,kns[MAXN],n,len=0;
int judge(int x,int y){if(x>=0 && x<MAX && y>=0 && y<MAX) return 1;return 0;}
int min(int a,int b){return a<b?a:b;}
int transform(int x,int y){return y*8+x;}

void floyd(){
	for(int k=0;k<MAXN;k++)
		for(int i=0;i<MAXN;i++)
			for(int j=0;j<MAXN;j++){
				king[i][j]=min(king[i][j],king[i][k]+king[k][j]);
				knight[i][j]=min(knight[i][j],knight[i][k]+knight[k][j]);
			}
}


void init(){
	memset(king,INF,sizeof(king));
	memset(knight,INF,sizeof(knight));
	for(int i=0;i<MAXN;i++) king[i][i]=knight[i][i]=0;
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			for(int k=0;k<8;k++){
				int xk=i+mvk[k][0],yk=j+mvk[k][1];
				int xkn=i+mvkn[k][0],ykn=j+mvkn[k][1];

				if(judge(xk,yk)) {king[transform(i,j)][transform(xk,yk)]=1;}
				if(judge(xkn,ykn)) {knight[transform(i,j)][transform(xkn,ykn)]=1;}
			}
		}
	}
	floyd();
	scanf("%s",str);
	arthur=transform(str[0]-'A',str[1]-'1');
	n=strlen(str);
	for(int i=2;i<n;i+=2){
		kns[len++]=transform(str[i]-'A',str[i+1]-'1');
	}
}

void work(){
	int sum=0,ans=INF;
	for(int i=0;i<MAXN;i++){
		for(int j=0;j<MAXN;j++){
			sum=king[arthur][j];
			for(int k=0;k<len;k++){
				sum+=knight[kns[k]][i];
			}
			for(int k=0;k<len;k++){
				ans=min(ans,sum-knight[kns[k]][i]+knight[kns[k]][j]+knight[j][i]);
			}
		}
	}
	printf("%d\n",ans);
}

int main()
{
	freopen("input.in","r",stdin);
	init();
	work();
	return 0;
}