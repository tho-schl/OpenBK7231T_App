#ifndef DRV_TIMED_EVENTS_H
#define DRV_TIMED_EVENTS_H

#include "../new_common.h"

typedef struct clockEvent_s {
	byte hour;
	byte minute;
	byte second;
	byte weekDayFlags;
#if ENABLE_TIME_SUNRISE_SUNSET
	byte lastDay;  /* used so we don't repeat sunrise sunset events the same day */
	byte sunflags;  /* flags for sunrise/sunset as follows: */
#define SUNRISE_FLAG (1 << 0)
#define SUNSET_FLAG (1 << 1)
#endif
	int id;
	char *command;
	struct clockEvent_s *next;
} clockEvent_t;

clockEvent_t * getClockEvents();

#endif //DRV_TIMED_EVENTS_H
