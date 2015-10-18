#include <stdio.h>
#include <algorithm>
#include <string.h>

int dp[100005];
int sum[100005];
int v[105],c[105];

int main()
{
    freopen("input.in","r",stdin);
    int i,j,k,n,m;
    while(~scanf("%d%d",&n,&m),n+m)
    {
        for(i = 1;i<=n;i++)
        scanf("%d",&v[i]);
        for(i = 1;i<=n;i++)
        scanf("%d",&c[i]);
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        int ans = 0;
        for(i=1;i<=n;i++)
        {
            memset(sum,0,sizeof(sum));
            for(j = v[i];j<=m;j++)
            {
                if(!dp[j] && dp[j-v[i]] && sum[j-v[i]]<c[i])
                {
                    dp[j] = 1;
                    sum[j] = sum[j-v[i]]+1;
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
