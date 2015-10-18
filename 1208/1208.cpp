#include <stdio.h>
#include <string.h>
#define MAX 26
int n;
int stacks[MAX][MAX],tp[MAX]={0},hash_table[MAX];
int stk[MAX],ttop;
char op1[5],op2[5];
int num1,num2;
void push(int index,int x){
	stacks[index][tp[index]++]=x;
}
void pop(int index){
	tp[index]--;
}
int top(int index){
	return stacks[index][tp[index]-1];
}
//temp stack
void pushtt(int x){stk[ttop++]=x;}
void poptt(){ttop--;}
int toptt(){return stk[ttop-1];}

//command
void moveonto(){
	int a_st=hash_table[num1],b_st=hash_table[num2];
	int temp;
	while(1){
		temp=top(b_st);
		if(temp!=num2){
			push(temp,temp);
			pop(b_st);
			hash_table[temp]=temp;
		}
		else break;
	}
	while(1){
		temp=top(a_st);
		if(temp!=num1){
			push(temp,temp);
			pop(a_st);
			hash_table[temp]=temp;
		}
		else{
			push(b_st,temp);
			pop(a_st);
			hash_table[temp]=b_st;
			break;
		}
	}
}

void moveover(){
	int a_st=hash_table[num1],b_st=hash_table[num2];
	int temp;
	while(1){
		temp=top(a_st);
		if(temp!=num1){
			push(temp,temp);
			pop(a_st);
			hash_table[temp]=temp;
		}
		else{
			pop(a_st);
			push(b_st,temp);
			hash_table[temp]=b_st;
			break;
		}
	}
}

void pileonto(){
	int a_st=hash_table[num1],b_st=hash_table[num2];
	int temp;
	while(1){
		temp=top(b_st);
		if(temp!=num2){
			push(temp,temp);
			pop(b_st);
			hash_table[temp]=temp;
		}
		else break;
	}
	while(1){
		temp=top(a_st);
		pushtt(temp);
		pop(a_st);
		if(temp==num1) break;
	}
	while(ttop){
		temp=toptt();
		push(b_st,temp);
		poptt();
		hash_table[temp]=b_st;
	}
}

void pileover(){
	int a_st=hash_table[num1],b_st=hash_table[num2];
	int temp;
	while(1){
		temp=top(a_st);
		pushtt(temp);
		pop(a_st);
		if(temp==num1) break;
	}
	while(ttop){
		temp=toptt();
		push(b_st,temp);
		poptt();
		hash_table[temp]=b_st;
	}
}

void command(){
	if(num1==num2 || hash_table[num1]==hash_table[num2]) return ;
	if(!strcmp(op1,"move") && !strcmp(op2,"onto")) moveonto();
	else if(!strcmp(op1,"move") && !strcmp(op2,"over")) moveover();
	else if(!strcmp(op1,"pile") && !strcmp(op2,"onto")) pileonto();
	else pileover();
}

void work(){
	
	scanf("%d",&n);
	for(int i=0;i<n;i++) {hash_table[i]=i;push(i,i);}
	while(1){
		scanf("%s",op1);
		if(!strcmp(op1,"quit")) break;
		scanf("%d %s %d",&num1,op2,&num2);
		command();
	}
	for(int i=0;i<n;i++){
		printf("%d:",i);
		for(int j=0;j<tp[i];j++)
			printf(" %d",stacks[i][j]);
		printf("\n");
	}
}

int main()
{
	freopen("input.in","r",stdin);
	work();
	return 0;
}