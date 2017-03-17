//  Door_timer.h
//
// Simple timer for elevator project "Heisprosjekt-master"
//

#ifndef Door_timer_h
#define Door_timer_h

#include <stdbool.h>
#include <time.h>

static int dt_timer;

/*
  Setting variable dt_timer to time() in seconds.
*/
void dt_start_timer(void);


/*
  Calculates time passed based som new value of time().
  @return true if more than 3 seconds have passed, false if not.
*/
bool dt_is_timeout(void);


#endif /* Door_Timer_h */
