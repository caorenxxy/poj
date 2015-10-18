#include <cstring>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <functional>
#include <cmath>
using namespace std;
#define PI acos(-1.0)
#define MAXN 10100
#define eps 1e-7
#define INF 0x7FFFFFFF
#define LLINF 0x7FFFFFFFFFFFFFFF
#define seed 131
#define MOD 1000000007
#define ll long long
#define ull unsigned ll
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

char a[15][25];
int next[MAXN],ret[MAXN];
int b[15][15],vis[15];
int ans,n;
int ExtendKMP(char a[],char b[]){
    int i,j,k;
    int M = strlen(a);
    int N = strlen(b);
    for(j=0;1+j<M&&a[j]==a[1+j];j++);
    next[1] = j;
    k = 1;
    for(i=2;i<M;i++){
        int Len = k + next[k], L = next[i-k];
        if(L<Len-i){
            next[i] = L;
        }
        else{
            for(j=max(0,Len-i);i+j<M&&a[j]==a[i+j];j++);
            next[i] = j;
            k = i;
        }
    }
    for(j=0;j<N&&j<M&&a[j]==b[j];j++);
    if(j==N)    return N;
    ret[0] = j;
    k = 0;
    for(i=1;i<N;i++){
        int Len = k + ret[k], L = next[i-k];
        if(L<Len-i){
            ret[i] = L;
        }
        else{
            for(j=max(0,Len-i);j<M&&i+j<N&&a[j]==b[i+j];j++);
            ret[i] = j;
            k = i;
        }
        if(ret[i]==N-i) return ret[i];
    }
    return 0;
}
void dfs(int x,int tot,int len){
    if(tot==n){
        if(ans>len) ans = len;
        return ;
    }
    if(len>ans) return ;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vis[i] = 1;
            dfs(i,tot+1,len+strlen(a[i])-b[i][x]);
            vis[i] = 0;
        }
    }
}
int main(){
    freopen("input.in","r",stdin);
    int t,i,j;
    scanf("%d",&t);
    while(t--){
        memset(b,0,sizeof(b));
        memset(vis,0,sizeof(vis));
        ans = INF;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%s",a[i]);
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i==j)    {printf("  ");continue;}
                b[j][i] = ExtendKMP(a[i],a[j]);
                printf("%d ",b[j][i]);
            }
            printf("\n");
        }
        for(i=0;i<n;i++){
            vis[i] = 1;
            dfs(i,1,strlen(a[i]));
            vis[i] = 0;
        }
        printf("%d\n",ans);
    }
    return 0;
}