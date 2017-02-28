#ifndef Door_Timer_h
#define Door_Timer_h

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

static bool dt_timeout;
static int dt_timer;
static bool dt_timer_stopped;


void dt_start_timer(void);
bool dt_is_timeout(void);
void dt_init_timer(void);
void dt_stop_timer(void);


#endif /* Door_Timer_h */
