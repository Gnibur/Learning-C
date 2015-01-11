#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP   100 /* max size of operand or operator */
#define NUMBER  '0' /* signal that a number was found */

/* operator stack */
int sp = 0;
double val[MAXOP];

int getop(char []);
void push(double);
double pop(void);
void printstack(void);


int main(int argc, char *argv[])
{
  int type;
  double op2;
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
    case '\n': /* print result */
      printf("\t%.8g\n", pop()); 
      break;
    case '?': /* print stack */
      printstack();
      break;
    case '!': /* clear stack */
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
