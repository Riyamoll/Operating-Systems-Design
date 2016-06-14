/*
   FILE          : simpletask.c
   PROGRAMMER    : Riyamoll Paulose
   FIRST VERSION : 2016-06-14
   DESCRIPTION   : This program demonstrates simple interprocess communication using
                   a shared global variable & demonstrate simple multitasking using
                   the simple monitor code.Here it reads the counter and prints the 
                   message count no. of times.
*/

#include <stdio.h>
#include <stdint.h>
#include "common.h"

static uint32_t count=0; // global to store count value

/* FUNCTION      : TaskCounter()
   DESCRIPTION   : prints count until zero 
   PARAMETERS    : nothing
   RETURNS       : nothing
*/
void TaskCounter(void)
{
if(count!=0)
{ 
 printf("The counter is %d\n",(unsigned int) count); // prints the count value
count--;                                             // decrement until zero
}
}

/* FUNCTION      : CmdCount()
   DESCRIPTION   : fetching the input by user 
   PARAMETERS    : int mode
   RETURNS       : nothing
*/
void CmdCount(int mode)
{
int rc;
uint32_t value = 0;            // value entered by user
  if(mode != CMD_INTERACTIVE)
 {
    return;
  }
rc = fetch_uint32_arg(&value); // fetching the input
if(rc)
{
printf(" Enter value");  
return;
}
else
count=value;                   // value stored to count variable
  }

ADD_CMD("count",CmdCount," Counting downwards");// count command is created

