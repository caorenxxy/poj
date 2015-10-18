
#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
#define ls 2*i
#define rs 2*i+1
#define up(i,x,y) for(i=x;i<=y;i++)
#define down(i,x,y) for(i=x;i>=y;i--)
#define mem(a,x) memset(a,x,sizeof(a))
#define w(a) while(a)
#define LL long long
const double pi = acos(-1.0);
#define Len 63
#define mod 19999997
const int INF = 0x3f3f3f3f;

const int to1[8][2] = {1,0,0,1,-1,0,0,-1,1,1,1,-1,-1,1,-1,-1};
const int to2[8][2] = {1,2,2,1,1,-2,2,-1,-1,2,-2,1,-1,-2,-2,-1};
int king[65][65],knight[65][65];

int main()
{
    freopen("input.in","r",stdin);
    int i,j,k;
     mem(king,INF);
     mem(knight,INF);
    up(i,0,Len)
    king[i][i] = knight[i][i] = 0;
    int x1,x2,y1,y2;
    up(i,0,7)
    {
        up(j,0,7)
        {
            up(k,0,7)
            {
                x1 = i+to1[k][0];
                y1 = j+to1[k][1];
                x2 = i+to2[k][0];
                y2 = j+to2[k][1];
                if(x1>=0 && x1<8 && y1>=0 && y1<8)
                    king[i*8+j][x1*8+y1] = 1;
                if(x2>=0 && x2<8 && y2>=0 && y2<8)
                    knight[i*8+j][x2*8+y2] = 1;
            }
        }
    }
    up(k,0,Len)
    {
        up(i,0,Len)
        {
            up(j,0,Len)
            {
                king[i][j] = min(king[i][j],king[i][k]+king[k][j]);
                knight[i][j] = min(knight[i][j],knight[i][k]+knight[k][j]);
            }
        }
    }
    char str[1000];
    int len;
    int arthur,saber[100],l,ans,tem,sum;
    w(~scanf("%s",str))
    {
        len = strlen(str);
        l = 0;
        ans = INF;
        arthur = (str[0]-'A')*8+(str[1]-'1');
        for(i = 2; i<len; i+=2)
            saber[l++] = (str[i]-'A')*8+(str[i+1]-'1');
        up(i,0,Len)
        {
            up(j,0,Len)
            {
                sum = king[arthur][j];//假设国王在j位置遇上了一个骑士
                up(k,0,l-1)
                sum+=knight[saber[k]][i];//假设所有骑士在i点集合，把所有骑士到这个点的步数加起来
                tem = INF;
                up(k,0,l-1)//枚举是第k个骑士与国王相遇，那么这个其实先要移动到j点，然后带着傻逼国王回到i点
                tem=min(tem,sum-knight[saber[k]][i]+knight[saber[k]][j]+knight[j][i]);
                ans = min(ans,tem);
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
