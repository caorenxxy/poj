#include <stdio.h>
#define MAX 10005
int n,p[MAX],d[MAX],fa[MAX],sum;

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
		if(p[y]>p[pivot]){
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

int find(int x){
	return (fa[x]==x)? x:(fa[x]=find(fa[x]));
}
void work(){
	int j;
	while(scanf("%d",&n)!=EOF){
		sum=0;
		for(int i=1;i<=n;i++) scanf("%d %d",&p[i],&d[i]);
		for(int i=1;i<MAX;i++) fa[i]=i;
		quick_sort(1,n);
		for(int i=1;i<=n;i++){
			if(!(j=find(d[i])) ) continue;
			sum+=p[i];
			fa[j]=j-1;
		}
		printf("%d\n",sum);
	}

}

int main()
{
	freopen("input.in","r",stdin);
	work();
	return 0;
}