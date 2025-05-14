#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// function to return precedence of operator
int prec(char c){
    if(c=='^')return 3;
    else if(c=='/'||c=='*')return 2;
    else if(c=='+'||c=='-') return 1;
    else return -1;
}
// function to associativity of operator
char associativity(char c){
    if(c=='^')return 'R';
    return 'L';// default to left associative
}
//function to convert infix expression to postfix expression
void infixToPostfix(char s[]){
    char result[100];int ri =0;
    int len =strlen(s);
    char stack[100];
    int si =-1;
    for(int i =0;i<len;i++){
        char c = s[i];
        //if the scanned character is an operand , add it to the output string
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')){
            result[ri++]=c;

        }
    
        //if the scanned character is an "(" push it to the stack
        else if(c=='('){
            stack[++si]=c;
               }
        //if the second character is an ')' pop and add to the output string from the stack
        // until an'(' is encountered
        else if(c==')'){
            while(si>=0&&stack[si]!='('){
                result[ri++]=stack[si--];
            }
            si--;//pop'('
        }
        //if an operator is scanned
        else{
            while(si>=0&&(prec(s[i])<prec(stack[si])||prec(s[i])==prec(stack[si])&& associativity(s[i])=='L')){
                result[ri++]=stack[si--];
            }
            stack[++si]=c;
        }
    }//pop all the remaining elements from the stack
    while (si>=0){
        result[ri++]=stack[si--];
    }
    result[ri]='\0';
    printf("%s\n",result);
}
int main(){
    char exp[]="(A+(B*C-(D/E^F)+G)+H)";
    // char exp[100];
    // printf("enter the expression :");
    // scanf("%s",exp);
    infixToPostfix(exp);
return 0;
}
