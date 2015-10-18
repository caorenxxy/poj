#include <stdio.h>
#include <string.h>
#define MAX 10005
#define max(a,b) ((a)>(b)?(a):(b))
int n,p[MAX],d[MAX],f[MAX][MAX];

void swap(int a,int b){
	int temp=p[a];
	p[a]=p[b];
	p[b]=temp;
	temp=d[a];
	d[a]=d[b];
	d[b]=temp;
}

int partition(int l,int r){
	int x=l-1,y=l,pivot=r;
	while(y<pivot){
		if(d[y]<d[pivot]){
			x++;
			swap(x,y);
		}
		y++;
	}
	x++;
	swap(x,pivot);
	return x;

}

void quick_sort(int l,int r){
	int pivot;
	if(l<r){
		pivot=partition(l,r);
		quick_sort(l,pivot-1);
		quick_sort(pivot+1,r);
	}
}

void dp(){
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=d[n];j++){
			if(j<=d[i])
			{
				if(f[i-1][j]<f[i-1][j-1]+p[i])
				{
					f[i][j]=f[i-1][j-1]+p[i];
				}
				else
					f[i][j]=f[i-1][j];
			}
			else 
				f[i][j]=f[i-1][j];
		
		}
	
	}
}

void work(){
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++) scanf("%d %d",&p[i],&d[i]);
		quick_sort(1,n);
		dp();
		int res=0;
		for(int i=1;i<=d[n];i++) res=max(res,f[n][i]);
		printf("%d\n",res);
	}

}
int main()
{
	freopen("input.in","r",stdin);
	work();
	return 0;
}