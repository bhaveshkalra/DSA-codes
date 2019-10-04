#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
struct Stack {
  char c;
  struct Stack *next;
};
typedef struct Stack stack;


struct Stack1 {
  double num;
  struct Stack1 *next;
};
typedef struct Stack1 stack1;



int isoperator(char c)
{
  if(c == '+' || c == '-' ||c == '*' || c == '/' || c == '^' || c == '%' || c == '(' || c == ')')
    return 1;
  return 0;
}

stack* create_node(char c1)
{
  stack *ch = (stack*) malloc(sizeof(stack));
  ch->next = NULL;
  ch->c = c1;
  return ch;
}

stack* push(char ch,stack *top)
{
  stack *nptr = create_node(ch);
  nptr->next = top;
  top = nptr;
  return top;
}

stack* pop(stack *top)
{
  if(top  == NULL)
    return NULL;
  stack *ptr = top;
  if(ptr->c != '(')
    {
      printf("%c  ", ptr->c);
    }
  top = top->next;
  return top;
}

int priority(char x)
{
    if(x == '(' || x == ')')
        return 0;
    else if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/' || x == '%')
        return 2;
    else if(x == '^')
        return 3;
}
stack1* create_node1(double num)
{
  stack1 *ptr = (stack1*)malloc(sizeof(stack1));
  ptr->num = num;
  ptr->next = NULL;
  return ptr;
}

stack1* push1(int num,stack1 *top)
{
  stack1 *ptr = create_node1(num);
  ptr->next = top;
  return ptr;
}
stack1* pop1(stack1 *top)
{
  if(top  == NULL)
    return NULL;
  top = top->next;
  return top;
}

void evals(char *exp)
{
  char *e = exp;
  char e1,e2;
  stack1 *top = NULL;
  if(isalnum(*e))
    {
      double num = 0;
      printf("\nEnter the value of %c:",*e);
      scanf("%lf",&num);
      top = create_node1(num);
      e++;
    }
  while(*e != '\0')
  {
    if(isalnum(*e) && top != NULL)
    {
      double num = 0;
      printf("\nEnter the value of %c:",*e);
      scanf("%lf",&num);
      top = push1(num,top);
    }
    else if(isoperator(*e))
    {
      double a = top->num;
      top = pop1(top);
      double b = top->num;
      top = pop1(top);
      switch (*e)
      {
        case '+': top = push1(b+a,top); break;
        case '-': top = push1(b-a,top); break;
        case '*': top = push1(b*a,top); break;
        case '/': top = push1(b/a,top); break;
        case '%': top = push1((int)b % (int)a,top); break;
        case '^': top = push1(pow(b,a),top); break;
        default : printf("ERROR!!!!"); break;
      }
    }
    e++;
  }
  printf("The value of the expression:%lf\n", top->num);
}
int main()
{
  char c;
  char *exp = (char*)malloc(sizeof(char)*20);
  char *postExp = (char*)malloc(sizeof(char)*20);
  printf("Enter the expression:");
  scanf("%s", exp);
  stack *top= NULL;
  char *e = exp;
  char *e2 = postExp;
  while(*e != '\0')
  {
    if(isalnum(*e))
      {
        printf("%c  ",*e);
        *postExp = *e;
        postExp++;
      }
    else if(top == NULL && isoperator(*e))
      {
        top = create_node(*e);
      }
    else if(top != NULL && (priority(top->c) < priority(*e) || *e == '(') && *e != ')')
      top = push(*e,top);
    else if(top != NULL && (priority(top->c) >= priority(*e) || *e == ')'))
      {

//We are concerned about associativity when there are two or more operators of
// the same precedence are present in a row. At such a situation we have to decide
// which side operation will take place first. So, to maintain it when power (^) operator
// is present we don't do pop operation. Instead we push it. This is done to main right
// to left associativity of power operator. This is done because power (^)
// has the highest priority. 
if(*e != '^')
        {

          while(top != NULL && top->c != '(')
            {
              *postExp = top->c;
              postExp++;

              top = pop(top);
            }
        }
        if(*e != ')')
          top = push(*e,top);
      }
      e++;
    }
    while(top != NULL)
      {
        if(top->c != '(')
          {
            *postExp = top->c;
            postExp++;
          }

        top = pop(top);
      }
  printf("\nThe PostFix Expression is:%s", e2);
  evals(e2);
  return 0;
}
