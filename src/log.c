/*
* Copyright (C) 2014 Jolla Ltd.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
*/

#include <stdarg.h>
#include <stdio.h>
#include <syslog.h>
#include <stdlib.h>
#include <string.h>
#include "log.h"

#define JOURNAL "1"
#define STDERR "2"
#define NONE 0x00
#define LOGJOURNAL 0x01
#define LOGSTDERR 0x02

static int logtarget = NONE;
static int log_priority = LOG_DEBUG;//LOG_ERR;
/*
 * Reads log target from env setting.
 * May be called several times, supports dynamic re-configuration.
 *
 * call "$export set PROVISIONING_SERVICE_LOG=" with a value to activate logging.
 */
extern void initlog()
{
	char *logarg = NULL;
	logarg = getenv("PROVISIONING_SERVICE_LOG");

	if (logarg) {
		if (!strcmp(logarg, JOURNAL))
			logtarget = LOGJOURNAL;
		else if (!strcmp(logarg, STDERR))
			logtarget = LOGSTDERR;
	}
}

/* Implementation of logging function */
extern void prov_debug(const char *format, ...)
{
	va_list args;

	/* Skip all function calls if no logging */
	if (logtarget == NONE)
		return;
	
	va_start(args, format);
	if (logtarget == LOGJOURNAL)
		vsyslog(log_priority, format, args);
	else if (logtarget == LOGSTDERR) {
		vfprintf(stderr, format, args);
		fprintf(stderr, "\n");
	}

	va_end(args);
}
