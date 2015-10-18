#include <stdio.h>
#include <string.h>
#define MAX 1005
#define MAXN 100005
#define inf 999999
int n,m,k;
int A[MAX],C[MAX],f[MAXN],res=0;
int a[MAXN],b[MAXN],front=0,tail=0;

void push(int x,int index){
	while(front<tail && x>=b[tail-1]) tail--;
	a[tail]=index;
	b[tail]=x;
	tail++;
}
void pop(){front++;}
void clearqm(){front=tail=0;}

void work(){
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++){
		if(m/A[i]<C[i]) C[i]=m/A[i];
		for(int d=0;d<A[i];d++){
			clearqm();
			for(int j=0;j<=(m-d)/A[i];j++){
				push(f[j*A[i]+d]-j*A[i],j);
				if(a[front]<j-C[i]) front++;
				f[j*A[i]+d]=b[front]+j*A[i];
			}
		}
	}
	for(int i=1;i<=m;i++) if(f[i]==i) res++;
	printf("%d\n",res);

}

void init(){
	while(scanf("%d %d",&n,&m)!=EOF && n && m){
		res=0;
		for(int i=1;i<=n;i++) scanf("%d",&A[i]);
		for(int i=1;i<=n;i++) scanf("%d",&C[i]);
		work();
	}
}

int main()
{
	freopen("input.in","r",stdin);
	init();

	return 0;
}