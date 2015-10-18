#include <stdio.h>
#define MAX 1000005
int n,k,num[MAX],ansmin[MAX],ansmax[MAX];

struct QUE{
	int pos,val;
};
QUE qmin[MAX],qmax[MAX];
int fmin,fmax,tmin,tmax;

void push_min(int x,int pos){
	while(fmin<tmin && x<=qmin[tmin-1].val)tmin--;
	qmin[tmin].val=x;
	qmin[tmin].pos=pos;
	tmin++;
}
void push_max(int x,int pos){
	while(fmax<tmax && x>=qmax[tmax-1].val)tmax--;
	qmax[tmax].val=x;
	qmax[tmax].pos=pos;
	tmax++;
}
void pop_min(){fmin++;}
void pop_max(){fmax++;}

void init(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}	
}
void work(){
	for(int i=0;i<k-1;i++){
		push_max(num[i],i);
		push_min(num[i],i);
	}
	for(int i=k-1;i<n;i++){
		push_max(num[i],i);
		push_min(num[i],i);
		while(qmax[fmax].pos<i-k+1) pop_max();
		while(qmin[fmin].pos<i-k+1) pop_min();
		ansmax[i-k+1]=qmax[fmax].val;
		ansmin[i-k+1]=qmin[fmin].val;
	}
	for(int i=0;i<n-k+1;i++) printf("%d ",ansmin[i]);
	printf("\n");
	for(int i=0;i<n-k+1;i++) printf("%d ",ansmax[i]);
	printf("\n");
}

int main()
{
	freopen("input.in","r",stdin);
	init();
	work();
	return 0;
}