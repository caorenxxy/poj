#include <stdio.h>
#include <string.h>
#define MAXN 100002
#define MAX 12
int cash,N,ni[MAX],dk[MAX],f[MAXN];
int a[MAXN],b[MAXN],front=0,tail=0;
void push(int x,int index){
	while(front<tail && x>=b[tail-1]) tail--;
	a[tail]=index;
	b[tail]=x;
	tail++;
}
void pop(){front++;}
void clearmq(){front=tail=0;}

void dp(){
	memset(f,0,sizeof(f));
	for(int i=1;i<=N;i++){
		if(cash/dk[i]<ni[i]) ni[i]=cash/dk[i];
		for(int d=0;d<dk[i];d++){
			clearmq();
			for(int j=0;j<=(cash-d)/dk[i];j++){
				push(f[j*dk[i]+d]-j*dk[i],j);
				if(a[front]<j-ni[i]) front++;
				f[j*dk[i]+d]=b[front]+j*dk[i];
			}
		}
	}
}

void work(){
	while(scanf("%d %d",&cash,&N)!=EOF){
		for(int i=1;i<=N;i++){
			scanf("%d %d",&ni[i],&dk[i]);
		}
		if(!cash || !N) {printf("%d\n",0);continue;}
		dp();
		printf("%d\n",f[cash]);
	}
	
}

int main()
{
	freopen("input.in","r",stdin);
	work();
	return 0;
}