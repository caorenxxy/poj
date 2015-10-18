#include <stdio.h>
#include <string.h>
#define inf 0x3f3f3f3f
char str[130];
int king,kingn[65],mk[65][65],mkn[65][65];
int mvk[8][2]={{-1,0},{1,0},{0,1},{0,-1},{-1,1},{-1,-1},{1,1},{1,-1}};
int mvkn[8][2]={{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2}};
int min(int a,int b){return a<b?a:b;}
int transform(int x,int y){
	return y*8+x;
}
int judge(int x,int y){
	if(x>=0 && x<=7 && y>=0 && y<=7) return 1;
	return 0;
}
void init(){
	memset(mk,inf,sizeof(mk));
	memset(mkn,inf,sizeof(mkn));
	for(int i=0;i<64;i++) mk[i][i]=mkn[i][i]=0;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			for(int k=0;k<8;k++){
				int xk=i+mvk[k][0],yk=j+mvk[k][1];
				int xkn=i+mvkn[k][0],ykn=j+mvkn[k][1];
				if(judge(xk,yk)) {
					mk[transform(i,j)][transform(xk,yk)]=1;
					mk[transform(xk,yk)][transform(i,j)]=1;
				}
				if(judge(xkn,ykn)) {
					mkn[transform(i,j)][transform(xkn,ykn)]=1;
					mkn[transform(xkn,ykn)][transform(i,j)]=1;
				}
			}
		}
	}
	//floyd
	for(int k=0;k<64;k++)
		for(int i=0;i<64;i++)
			for(int j=0;j<64;j++){
				mk[i][j]=min(mk[i][j],mk[i][k]+mk[k][j]);
				mkn[i][j]=min(mkn[i][j],mkn[i][k]+mkn[k][j]);
			}
	scanf("%s",str);
	int len=strlen(str);
	int ans=inf;
	int l=0,sum=0,temp;
	king=transform(str[0]-'A',str[1]-'1');
	
	for(int i=2;i<len;i+=2){
		kingn[l++]=transform(str[i]-'A',str[i+1]-'1');
	}
	for(int i=0;i<64;i++){
		for(int j=0;j<64;j++){
			sum=mk[king][j];
			for(int k=0;k<l;k++){
				sum+=mkn[kingn[k]][i];
			}
			temp=inf;
			for(int k=0;k<l;k++){
				ans=min(ans,sum-mkn[kingn[k]][i]+mkn[kingn[k]][j]+mkn[j][i]);
			}
			//ans=min(ans,temp);
		}
	}
	printf("%d\n",ans);
}

int main()
{
	freopen("input.in","r",stdin);
	init();
	return 0;
}