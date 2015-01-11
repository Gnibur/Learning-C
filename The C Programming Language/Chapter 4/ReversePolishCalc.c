/* Reverse Polish calculator. Supported operators are +, -, *, /, %, exp, pow, sin, and cos.
   Other general commands are: 
    - top: gets the top of the value stack
    - swap: swaps the two top elements
    - stack: prints the whole value stack
    - clear: clears the stack

*/


#include <stdio.h>
#include <stdlib.h> /* using atof */
#include <math.h>   /* for math functions like sin, cos, exp, pow */
#include <string.h> /* for strcmp */

#define MAXOP   100            /* max size of operand or operator */
#define MAX_VARIABLE_LENGTH 32 /* max length of variable name */


enum commands {
  NUMBER,
  GET_TOP,
  SWAP_TOP,
  GET_STACK,
  CLEAR,
  SIN,
  COS,
  EXP,
  POW,
};


/* value stack */
int sp = 0;
double val[MAXOP];

int getop(char []);
void push(double);
double pop(void);
void printstack(void);


int main(int argc, char *argv[])
{
  int type;
  double op2, temp;
  char s[MAXOP];

  while ((type = getop(s)) != EOF){
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop(); /* pop() - pop() has an undefined order of evaluation */
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
	push(pop() / op2);
      else
	printf("error: zero divisor\n");
      break;
    case '%':
      op2 = pop();
      if (op2 != 0.0)
	push((int)pop() % (int)op2);
      else 
	printf("error: zero modulo\n");
      break;
    case SIN:
      push(sin(pop()));
      break;
    case COS:
      push(cos(pop()));
      break;
    case EXP:
      push(exp(pop()));
      break;
    case POW:
      op2 = pop();
      push(pow(pop(), op2));
      break;

    case '\n': /* print result */
    case GET_TOP:
      if (sp > 0) 
	printf("\tTop is now: %.8g\n", val[sp-1]);
      break;
    case SWAP_TOP:
      temp = pop();
      op2 = pop();
      push(temp);
      push(op2);
      break;
    case GET_STACK:
      printstack();
      break;
    case CLEAR:
      sp = 0;
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }

  }
}

int getop(char s[])
{
  int i,c;

  while ((s[0] = c = getchar()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
 
  if (isalpha(c)) { /* either variable or command */
    
    i = 0; 
    while (isalnum(c) || c == '_') {
      if (i < MAXOP)
	s[i] = tolower(c);
      c = getchar();
      i++;
    }
    s[i] = '\0';

    if (c != EOF)
      ungetc(c, stdin);

    if      (!strcmp(s, "sin"))   return SIN;
    else if (!strcmp(s, "cos"))   return COS;
    else if (!strcmp(s, "exp"))   return EXP;
    else if (!strcmp(s, "pow"))   return POW;
    else if (!strcmp(s, "clear")) return CLEAR;
    else if (!strcmp(s, "top"))   return GET_TOP;
    else if (!strcmp(s, "swap"))  return SWAP_TOP;
    else if (!strcmp(s, "stack")) return GET_STACK;
  }

  if (!isdigit(c) && c != '.')
    return c; /* operator, not a number */
  
  i = 0; 
  if (isdigit(c)) /* collect integer part */
    while (isdigit(s[++i] = c = getchar()))
      ;
  if (c == '.')   /* collect fractional part */
    while (isdigit(s[++i] = c = getchar()))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetc(c, stdin);

  return NUMBER;
}

void push(double f)
{
  if (sp < MAXOP)
    val[sp++] = f;
  else 
    printf("error: operator stack full, can't push %g\n", f);
}

double pop()
{
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: can't pop, stack is empty\n");
    return 0.0;
  }
}

void printstack(void)
{
  int i;
  for (i = 0; i < sp; i++)
    printf("%g ", val[i]);
  putchar('\n');
}
