#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stck{
	int top;
	unsigned capacity;
	int *array;
};
//stack opreration
struct stck* createStack(unsigned capacity)
{
	struct stck* stack=(struct stck*)malloc(sizeof(struct stck));
	stack->top=-1;
	stack->capacity=capacity;
	stack->array=(int*) malloc(stack->capacity*sizeof(int));
	return stack;
}
int isEmpty(struct stck* stack){
	return stack->top==-1;
}
int pop(struct stck* stack){
	if(!isEmpty(stack))
		return stack->array[stack->top--];
}
void push(struct stck* stack,int op){
	stack->array[++stack->top]=op;
}
int evaluatePostfix(char*exp){
	//create a stack of capacity equal to expression size
	struct stck* stack=createStack(strlen(exp));
	int i;
	//scan all characters one by one
	for(i=0;exp[i];++i){
		//if thr scanned character is operand,push it to stack
		if(isdigit(exp[i]))
		push(stack,exp[i]-'0');
		//if thr scanned character is operator ,pop from stack apply the operator
		else{
			int val1=pop(stack);
			int val2=pop(stack);
			printf("\n top two values are %d%d",val1,val2);
			switch(exp[i]){
				case'/':
					push(stack,val2/val1);
					break;
				case'*':
					push(stack,val2*val1);
					break;
				case'+':
					push(stack,val2+val1);
					break;
				case'-':
					push(stack,val2-val1);
					break;
			}
		}
	}
	return pop(stack);
	
}
int main(){
	char exp[]="54+82/3*-";
	printf("\n postfix evaluation:%d",evaluatePostfix(exp));
	return 0;
}
