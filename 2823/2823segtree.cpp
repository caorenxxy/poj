#include <stdio.h>
#define lson p<<1
#define rson p<<1|1
#define MAX 1000005
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
int n,k,m,num[MAX];
struct Segment_Tree{
	int l,r,Min,Max;
}Seg[MAX<<2];

void bulid(int p,int l,int r){
	Seg[p].l=l;Seg[p].r=r;
	if(l==r){Seg[p].Min=Seg[p].Max=num[++m];return ;}
	int mid=(r+l)>>1;
	bulid(lson,l,mid);
	bulid(rson,mid+1,r);
	Seg[p].Min=min(Seg[lson].Min,Seg[rson].Min);
	Seg[p].Max=max(Seg[lson].Max,Seg[rson].Max);
}

void update(int p,int x,int val){
	if(Seg[p].l==x && Seg[p].r==x) {
		Seg[p].Max=Seg[p].Min=val;
		return ;
	}
	int mid=(Seg[p].l+Seg[p].r)>>1;
	if(x<=mid) update(lson,x,val);
	else update(rson,x,val);
	Seg[p].Max=max(Seg[lson].Max,Seg[rson].Max);
	Seg[p].Min=min(Seg[lson].Min,Seg[rson].Min);
}

int querry_max(int p,int l,int r){
	if(Seg[p].l==l && Seg[p].r==r) return Seg[p].Max;
	int mid=(Seg[p].l+Seg[p].r)>>1;
	if(r<=mid) return querry_max(lson,l,r);
	else if(l>mid) return querry_max(rson,l,r);
	else return max(querry_max(lson,l,mid),querry_max(rson,mid+1,r));
}
int querry_min(int p,int l,int r){
	if(Seg[p].l==l && Seg[p].r==r) return Seg[p].Min;
	int mid=(Seg[p].l+Seg[p].r)>>1;
	if(r<=mid) return querry_min(lson,l,r);
	else if(l>mid) return querry_min(rson,l,r);
	else return min(querry_min(lson,l,mid),querry_min(rson,mid+1,r));
}

void init(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&num[i]);
	m=0;
	bulid(1,1,n);	
}
void work(){

	for(int i=1;i<=n-k+1;i++)
		printf("%d ",querry_min(1,i,i+k-1));
	printf("\n");
	for(int i=1;i<=n-k+1;i++)
		printf("%d ",querry_max(1,i,i+k-1));
	printf("\n");

}
int main()
{
	freopen("input.in","r",stdin);
	init();
	work();
	return 0;
}