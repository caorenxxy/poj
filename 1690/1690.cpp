#include <stdio.h>
#include <string.h>
#define MAX 260
int m;
int mark[MAX],vis[MAX],del[MAX];
char input[MAX],str[MAX];
void work(){
	scanf("%d",&m);
	getchar();
	while(m--){
		memset(mark,0,sizeof(mark));
		memset(vis,0,sizeof(vis));
		memset(del,0,sizeof(del));
		gets(input);
		int len=0;
		for(int i=0;input[i]!='\0';i++){
			if(input[i]==' ') continue;
			str[len++]=input[i];
		}
		str[len]='\0';
		for(int i=0;i<len;i++){
			if(str[i]==')'){
				for(int j=i-1;j>=0;j--){
					if(str[j]=='(' && !vis[j]){
						vis[j]=1;
						mark[i]=j;
						break;
					}
				}
			}
		}
		for(int i=0;i<len;i++){
			if(str[i]==')'){
				if(i==len-1 && mark[i]==0) del[i]=del[mark[i]]=1;
				if(str[mark[i]-1]!='-'){
					del[i]=del[mark[i]]=1;
				}
				else if(str[mark[i]-1]=='-'){
					int cnt=0;
					for(int j=i-1;j>=mark[i];j--){
						if(str[j]=='+' || str[j]=='-') cnt++;
					}
					if(!cnt) del[i]=del[mark[i]]=1;
				}
			}
		}
		for(int i=0;i<len;i++){
			if(del[i]) continue;
			printf("%c",str[i]);
		}
		printf("\n");
	}

	
}
int main()
{
	freopen("input.in","r",stdin);
	work();
	return 0;
}
