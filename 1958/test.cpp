#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
     int dp[13] = {0, 1, 3, 5};
    for(int n = 4; n < 13; n++)
    {
        dp[n] = 0xfffff;
        for(int k = 1; k <= n; k++)
        {
            int t = (dp[n-k] << 1) + (1 << k) - 1;
            if(dp[n] > t) dp[n] = t;
        }        
    }
    for(int i = 1; i < 13; i++) printf("%d\n", dp[i]);
    return 0;
}