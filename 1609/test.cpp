#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
const int Max = 102;
 
int num[Max][Max], dp[Max][Max];
 
int max(int a, int b){
 return a > b ? a : b;
}
 
int main(){
    freopen("input.in","r",stdin);
    int n, i, j;
    while(cin >> n && n != 0){
        memset(num, 0, sizeof(num));
        memset(dp, 0, sizeof(dp));
        for(i = 1; i <= n; i ++){
            int a, b;
            cin >> a >> b;
            num[a][b] ++;
        }
        for(i = 1; i <= 100; i ++)
            for(j = 1; j <= 100; j ++)
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + num[i][j];
        cout << dp[100][100] << endl;
    }
    cout << '*' << endl;
    return 0;
}