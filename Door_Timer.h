#ifndef Door_Timer_h
#define Door_Timer_h

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

static bool dt_timeout;
static int dt_timer;

void dt_start_timer(void);
bool dt_is_timeout(void);


#endif /* Door_Timer_h */
