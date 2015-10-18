#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll __int64
#define ls rt<<1
#define rs ls|1
#define lson l,mid,ls
#define rson mid+1,r,rs
#define middle (l+r)>>1
#define eps (1e-8)
#define clr_all(x,c) memset(x,c,sizeof(x))
#define clr(x,c,n) memset(x,c,sizeof(x[0])*(n+1))
#define MOD (1000000007)
#define inf (0x3f3f3f3f)
#define pi (acos(-1.0))
#define _max(x,y) (((x)>(y))? (x):(y))
#define _min(x,y) (((x)<(y))? (x):(y))
#define _abs(x) ((x)<0? (-(x)):(x))
#define getmin(x,y) (x= (x<0 || (y)<x)? (y):x)
#define getmax(x,y) (x= ((y)>x)? (y):x)
template <class T> void _swap(T &x,T &y){T t=x;x=y;y=t;}
int TS,cas=1;
const int M=10000+5;
int n,fa[M];
struct node{
	int p,d;
	void read(){scanf("%d%d",&p,&d);}
	bool operator <(const node& t) const{
		return p > t.p; 
	}
}a[M];

int find(int x){
	return (fa[x]==x)? x:(fa[x]=find(fa[x]));
}

void run(){
    int i,j;
	for(i=1;i<=n;i++) a[i].read();
	sort(a+1,a+n+1);
	for(i=1;i<M;i++) fa[i]=i;
	int sum=0;
	for(i=1;i<=n;i++){
		if(!(j=find(a[i].d))) continue;
		sum+=a[i].p;
		fa[j]=j-1;
	}
	printf("%d\n",sum);
}

void preSof(){
}

int main(){
    freopen("input.in","r",stdin);
    //freopen("output.txt","w",stdout);
    preSof();
    //run();
    while(~scanf("%d",&n)) run();
    //for(scanf("%d",&TS);cas<=TS;cas++) run();
    return 0;
}