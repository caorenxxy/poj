#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#define eps 0.00001
#define MAXN 105
#define MAXM 10005
using namespace std;
int deg[MAXN];
double ori[MAXN],X[MAXN][2];
int T,n,m;
vector<int> G[MAXN];
void dp(int t){
	for(int i=1;i<=n;i++){
		if(deg[i]>0) X[i][t%2]=0;
		else X[i][t%2]=X[i][(t-1)%2];
		for(int j=0;j<G[i].size();j++){
			X[i][t%2]+=X[G[i][j]][(t-1)%2]/(1.0*deg[G[i][j]]);
		}
	}
}

void work(){
	for(int i=1;i<=n;i++) X[i][0]=ori[i];
	int t=1;
	while(1){
		dp(t);
		bool flag=true;
		for(int i=1;i<=n;i++){
			if(fabs(X[i][t%2]-X[i][(t-1)%2])>eps)
			{
				flag=false;
				break;
			}
		}
		if(flag) break;
		t++;
	}
	for(int i=1;i<=n;i++) printf("%.3f\n",X[i][t%2]);
	printf("\n");
}

int main()
{
	freopen("input.in","r",stdin);
	int u,v;
	scanf("%d",&T);
	while(T--){
		memset(deg,0,sizeof(deg));
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%lf",&ori[i]);
		for(int i=1;i<=m;i++){
			scanf("%d %d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
			deg[u]++;deg[v]++;
		}
		work();
		for(int i=1;i<=n;i++) G[i].erase(G[i].begin(),G[i].end());
	}
	return 0;
}