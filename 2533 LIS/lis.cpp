#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define MAX 1005
int a[MAX],d[MAX],f[MAX],n;

int binary(int l,int r,int key){
	int left=l,right=r;
	int mid;
	while(left<=right){
		mid=(left+right)>>1;
		if(key>d[mid] && key<=d[mid+1]) return mid;
		else if(key>d[mid]) left=mid+1;
		else right=mid-1;
	}
	return 0;
}

void LIS(){
	f[1]=1;
	d[1]=a[1];
	int len=1;
	int j;
	for(int i=2;i<=n;i++){
		if(d[len]<a[i]){
			j=++len;
		}
		else
			j=binary(1,len,a[i])+1;
		d[j]=a[i];
		f[i]=j;
	}
}

void work(){
	LIS();
	int res=0;
	for(int i=1;i<=n;i++) res=max(res,f[i]);
	printf("%d\n",res);
}

void init(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
}

int main()
{		
	freopen("input.in","r",stdin);
	init();
	work();
	return 0;
}
