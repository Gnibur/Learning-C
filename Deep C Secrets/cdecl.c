/* A basic cdecl, inspired by the tentative solution given in 
   Expert C Programming, Deep C Secrets */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


#define MAX_TOKEN_LENGTH 20
#define MAX_TOKENS 50

enum token_tag {
  TYPE,
  QUALIFIER,
  IDENTIFIER
};

struct token {
  char type;
  char string[MAX_TOKEN_LENGTH];
};

void deal_with_declarator(void);

struct token stack[MAX_TOKENS];
int top = -1;

#define pop() stack[top--]
#define push(token) (stack[++top] = token)

/* Returns the token type */
enum token_tag classify_string(char *str)
{
  if      (!strcmp(str, "void"))     return TYPE;
  else if (!strcmp(str,"char"))      return TYPE;
  else if (!strcmp(str, "int"))      return TYPE;
  else if (!strcmp(str, "short"))    return TYPE;
  else if (!strcmp(str, "long"))     return TYPE;
  else if (!strcmp(str, "float"))    return TYPE;
  else if (!strcmp(str, "double"))   return TYPE;
  else if (!strcmp(str, "enum"))     return TYPE;
  else if (!strcmp(str, "struct"))   return TYPE;
  else if (!strcmp(str, "union"))    return TYPE;
  else if (!strcmp(str, "unsigned")) return TYPE;
  else if (!strcmp(str, "const"))    return QUALIFIER;
  else if (!strcmp(str, "volatile")) return QUALIFIER;
  else return IDENTIFIER;
}

/* Returns the next token from the input */
struct token gettoken()
{
  struct token this;
  int c, i;
  
  /* Ignore whitespaces */
  while ( (c = getchar()) == ' ')
    ;

  if ( isalpha(c) ){
    /* A qualifier or identifier starts with a letter and
       can further consist of other letters, numbers,
       or underscores */
    i = 0;
    while (isalnum(c) || c == '_'){
      if (i < MAX_TOKEN_LENGTH-1)
	this.string[i] = c;
      c = getchar();
      i++;
    }

    this.string[i] = '\0';

    /* The next character read is part of another token */
    ungetc(c, stdin);

    this.type = classify_string(this.string);
  }
  else {
    this.type = c;
    this.string[1] = '\0';
  }
  
  /* Makes it easier to write the declarator */ 
  if (this.type == '*')
    strcpy(this.string,"pointer to");

  return this;
}

/* Pushes all tokens to stack and prints identifier */
void read_to_first_identifier(void)
{
  do {
    push(gettoken());
  } while (stack[top].type != IDENTIFIER);
  printf("%s is a", stack[top].string);
  pop();
}

/* Prints out the function argument list
   To be able to print cdecl-like, one must create a new
   token stack. */
void deal_with_function_args()
{
  printf(" function(");
  
  int c;
  while ( (c = getchar()) != ')')
    putchar(c);
  putchar(')');

  ungetc(')', stdin);
  
  push(gettoken());

  printf(", returning");
}

void deal_with_arrays()
{
  int c, i;
  while (stack[top].type == '['){
    printf(" array"); 
    
    /* Check if size is specified */ 
    if ( isdigit(c = getchar()) ){
      ungetc(c, stdin);
      scanf("%d",&i);
      printf(" [0..%i]", i-1);      
    }
    ungetc(c,stdin);
    /* pop the '[' and read the ']' */
    pop();
    gettoken();

    /* Check next token */
    push(gettoken());

    printf(" of");
  }
}

void deal_with_pointers()
{
  while (stack[top].type == '*'){
    printf(" pointer to");
    pop();
  }
}

void deal_with_declarator(void)
{
  /* First read to the right */
  push(gettoken());
  
  /* Parantheses and brackets have the highest precedence */
  if (stack[top].type == '(')
    deal_with_function_args();
  else if (stack[top].type == '[')
    deal_with_arrays();
    
  /* Then indirection */
  deal_with_pointers();

  /* Only tokens left is ')' or ';', start reading to the left */ 
  pop();
  while (top >= 0){
    if (stack[top].type == '('){
      /* Start reading to the right again */ 
      pop();
      deal_with_declarator();
    } else {
      printf(" %s", stack[top].string);
      pop();
    }
  }
}

int main(int argc, char *argv[])
{
  read_to_first_identifier();
  deal_with_declarator();
  putchar('\n');
  return 0;
}
