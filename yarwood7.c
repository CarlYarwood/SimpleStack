#include <stdio.h>
#include <stdlib.h>
struct stackNode{
  int data;
  struct stackNode *nextPtr;
};
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;
int evaluatePostfixExpression(char *expr);
int calculate(int op1, int op2, char operator);
void push(StackNodePtr *topPtr, int value);
int pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr topPtr);

int main(){
  char operater[]="53*2%6+1-2/";
  StackNodePtr top;
  int op1;
  int op2;
  int i;
  int number;
  for( int c =0; operater[c] != '\0'; c++){
  if(operater[c] != '+' && operater[c]!= '-' && operater[c] !='*' &&
     operater[c] != '/' && operater[c]!= '^' && operater[c] !='%'){
    number = evaluatePostfixExpression(operater+c);
    push(&top, number);
  }
  else{
    op1 = pop(&top);
    op2 = pop(&top);
    i = calculate(op1,op2,operater[c]);
    push(&top, i);
  }
 }

 
 printf("Your operation comes out to ");
 printStack(top);
 printf("\n");
  

}
int evaluatePostfixExpression(char *expr){
  return (*expr) - '0';
}
int calculate(int op1, int op2, char operator){
  int temp;
  if(operator == '+'){
    return op2 + op1;
  }
  else if(operator == '-'){
    return op2 - op1;
  }
  else if(operator == '*'){
    return op2 * op1;
  }
  else if(operator == '/'){
    return op2 / op1;
  }
  else if(operator == '^'){
    if(op1 == 0){
      return 1;
    }
    else{
      temp = op2;
      for(int i = 0; i<op1; i++){
	op2 = op2 * temp;
      }
      return op2;
    }
  }
  else{
    return op2%op1;
  }
}
void push(StackNodePtr *topPtr, int value){
  StackNodePtr newPtr = malloc(sizeof(StackNode));
  if(newPtr != NULL) {
    newPtr->data = value;
    newPtr->nextPtr = *topPtr;
    *topPtr = newPtr;
  }
  else{
    printf("%d not inserted no memory available.\n", value);
  }
}
int pop(StackNodePtr *topPtr){
  StackNodePtr tempPtr = *topPtr;
  int popValue = (*topPtr)->data;
  *topPtr = (*topPtr)->nextPtr;
  free(tempPtr);
  return popValue;
}
int isEmpty(StackNodePtr topPtr){
  return topPtr==NULL;
}
void printStack(StackNodePtr topPtr){
  printf("%d",(topPtr->data));
}
    
