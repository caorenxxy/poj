#include<stdio.h>
#include<iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=110;
int dp[200010];
int value[MAXN];
int weight[MAXN];
int nKind;
int main()
{
    freopen("input.in","r",stdin);
    int k=100000;
    while(scanf("%d",&nKind)!=EOF)
    {
        for(int i=0;i<nKind;i++)
        {
            scanf("%d%d",&value[i],&weight[i]);
        }
        for(int i=0;i<=200000;i++)dp[i]=-INF;
        dp[k]=0;
        for(int i=0;i<nKind;i++)
        {
            if(value[i]>0)//正的是逆序
            {
                for(int j=200000;j>=value[i];j--)//注意范围
                  if(dp[j-value[i]]>-INF)
                    dp[j]=max(dp[j],dp[j-value[i]]+weight[i]);
            }
            else//负的是顺序
            {
                for(int j=0;j<=200000+value[i];j++)//注意范围
                  if(dp[j-value[i]]>-INF)
                    dp[j]=max(dp[j],dp[j-value[i]]+weight[i]);
            }
        }
        int ans=0;
        for(int i=100000;i<=200000;i++)
            if(dp[i]>=0&&dp[i]+i-100000>ans)
                ans=dp[i]+i-100000;
        printf("%d\n",ans);
    }
    return 0;
}