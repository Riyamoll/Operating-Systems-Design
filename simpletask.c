#include <stdio.h>
#include <stdint.h>
#include "common.h"

static uint32_t count;
void TaskCounter(void)
{
while(count >0)
{ 
 printf("Counting  is downwards: %u", count); 
count--;
}
}

void CmdCount()
{
scanf(" Enter count: %u", count);
  }

ADD_CMD("count", CmdCount,"Reads the counter");
