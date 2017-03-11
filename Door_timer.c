//  Door_timer.c
//
// Simple timer for elevator project "Heisprosjekt-master"
//
// Copyright © 2017 Alexander Johansen & Bendik Standal. All rights reserved.


#include "Door_timer.h"


void dt_start_timer(void) {
    dt_timer = time(NULL);
}


bool dt_is_timeout(void) {
	if ((time(NULL) - dt_timer) > 2) {
		return true;
	}
	else {
		return false;
	}
}
