#include <stdio.h>
#define MAXN 202
int N,t,L[MAXN+1],R[MAXN+1],S[MAXN+1][MAXN+1],e[MAXN+1][MAXN+1],flag[MAXN];
void swap(int a,int b){
	int temp=L[a];
	L[a]=L[b];L[b]=temp;
	temp=R[a];
	R[a]=R[b];R[b]=temp;
}

int partition(int p,int q){
	int x=p-1,y=p,pivot=q;
	while(y<pivot){
		if(L[y]<L[pivot]){
			x++;
			swap(x,y);
		}
		y++;
	}
	x++;
	swap(x,pivot);
	return x;
}

void quick_sort(int p,int q){
	int pivot;
	if(p<q){
		pivot=partition(p,q);
		quick_sort(p,pivot-1);
		quick_sort(pivot+1,q);
	}
}

void dp(){
	for(int i=1;i<=N;i++) S[i][i]=1;
	for(int l=2;l<=N;l++){
		for(int i=1;i<=N-l+1;i++){
			int j=l+i-1;
			if(L[j]<R[i]){S[i][j]=0;continue;}
			for(int k=i+1;k<=j-1;k++){
				if(L[k]<R[i] || R[k]>L[j]) continue;
				if(S[i][j]<S[i][k]+S[k][j]+1) {
					S[i][j]=S[i][k]+S[k][j]+1;
				}
			}
		}
	}
}

void work(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&N);
		int l,r;
		for(int i=1;i<=N;i++){
			scanf("%d %d",&l,&r);
			if(l%2!=0) l++;
			if(r%2!=0) r++;
			if(l<r) {L[i]=l;R[i]=r;}
			else {L[i]=r;R[i]=l;}
		}
		quick_sort(1,N);
	}
}

int main()
{
	return 0;
}