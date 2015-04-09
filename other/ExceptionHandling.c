/*
  This is an demonstration of exception handling in C.
  This implementation is using signals and setjmp/longjmp. sigaction is used for avoiding portability issues as suggested by the signal man page.
  
  The example should be updated to be more illustrative. Probably with sigsegv 
 */


#include <signal.h>
#include <stdio.h>
#include <setjmp.h>


jmp_buf jumper;

/* define floating point exceptions */
#define CRITICAL_REGION 0
#define RECOVERY_REGION 1

void sighandler(int signum, siginfo_t *info, void *ucontext)
{
  longjmp(jumper, RECOVERY_REGION);
}



int main(int argc, char **argv[]) 
{
  int a = 0;

  /* Set up fault handler */ 
  struct sigaction oldaction;
  struct sigaction newaction;

  newaction.sa_sigaction = sighandler;
  sigemptyset(&(newaction.sa_mask));
  newaction.sa_flags = SA_SIGINFO | SA_ONESHOT;
  sigaction(SIGINT, &newaction, &oldaction);


  switch (setjmp(jumper))
  {
  case CRITICAL_REGION: 
    /* Critical code region */

    while (1){
      a = 2/0;
      printf("Now in critical region, press ^C to raise signal, a is now %i\n", a++);
    }

    break;
  
  case RECOVERY_REGION:
    /* Forward recovery code */
    a = 0;
    printf("Entered forward recovery region, a reseted to %i\n", a);
    break;

  default:
    printf("Error setjmp shouldn't return this value\n");

  }


  /* Exit critical code region, restore signal handling state */
  sigaction(SIGFPE, &oldaction, NULL);
 

  return 0;
}
