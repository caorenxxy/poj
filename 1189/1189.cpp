#include <stdio.h>
#define MAX 52
typedef long long LL;
int m,n;
char map[MAX][MAX];
LL f[MAX][MAX];
LL gcd(LL a,LL b) { 
    LL g; 
    if(b==0) 
        g=a; 
    else 
        g=gcd(b,a%b); 
    return g; 
} 
 
void init(){
	char ch;
	scanf("%d %d",&n,&m);
	getchar();
	for(int i=1;i<=n;i++){
		int cnt=1;
		while(1){
			ch=getchar();
			if(ch=='.'||ch=='*'){map[i][cnt]=ch;cnt++;}
			else if(ch=='\n') break;
		}
	}
}

void dp(){
	f[1][1]=(LL)(1)<<n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(map[i][j]=='*'){
				f[i+1][j]+=f[i][j]>>1;
				f[i+1][j+1]+=f[i][j]>>1;
			}
			else{
				f[i+2][j+1]+=f[i][j];
			}
		}
	}
}

void work(){
	dp();
	LL sum=0;
	for(int i=1;i<=n+1;i++){
		sum+=f[n+1][i];
	}
	LL GCD=gcd(sum,f[n+1][m+1]);
	if(f[n+1][m+1]==0) printf("%lld/%lld\n",0,sum);
	else
		printf("%lld/%lld\n",f[n+1][m+1]/GCD,sum/GCD);

	
}

int main()
{
	freopen("input.in","r",stdin);
	init();
	work();
	return 0;
}