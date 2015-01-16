/* Reverse Polish calculator. Supported operators are +, -, *, /, %, !, exp, pow, sin, and cos.
   Supports 26 variables, a-z, initialized to 0. 
     Retrieving value: A B +, result of A + B is on top of stack 
     Storing value:    8 A =, the value 8 is stored in A. 8 and A is removed from stack.
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
  VARIABLE
};


/* value stack */
int sp = 0;
double value[MAXOP];

/* stores the last variable used to be able to assign a value. */
char lastVariable;
/* Stores the variables. Static initialization results in that they are initialized to 0 */
double variables['z'-'a'+1];

/* pushes a value to the value stack */
void push(double);
/* pops a value from the value stack */
double pop(void);
/* prints the value stack */
void printstack(void);


/* returns the operand type and places it into the string */
int getop(char s[]);


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
    case '!': /* factorial */
      op2 = pop();
      printf("factorial on %g\n", op2);
      if (op2 == 0)
	push(1.0);
      else if (op2 < 0){
	printf("error: factorial on negative number\n");
	push(op2);
      }
      else {
	for (temp = op2 - 1; temp > 0; temp--)
	  op2 *= temp;
	push(op2);
      }
      break;

    case VARIABLE:
      push(variables[lastVariable-'a']);
      break;
    case '=':
      pop();        /* ignore top of stack, which is the previous value of the variable */
      variables[lastVariable-'a'] = pop();
      break;
     
    case '\n': /* print result */
    case GET_TOP:
      if (sp > 0) 
	printf("\tTop is now: %.8g\n", value[sp-1]);
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
    else if (s[0] >= 'a' && s[0] <= 'z') {
      lastVariable = s[0];
      return VARIABLE;
    }
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
  if (c != EOF) /* more operators to come */
    ungetc(c, stdin);

  return NUMBER;
}

void push(double f)
{
  if (sp < MAXOP)
    value[sp++] = f;
  else 
    printf("error: operator stack full, can't push %g\n", f);
}

double pop()
{
  if (sp > 0)
    return value[--sp];
  else {
    printf("error: can't pop, stack is empty\n");
    return 0.0;
  }
}

void printstack(void)
{
  int i;
  putchar('\t');
  for (i = 0; i < sp; i++)
    printf("%g ", value[i]);
  putchar('\n');
}
