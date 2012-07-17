#ifndef UTILS_H
#define UTILS_H 1

/*\
 *
 *                          COPYRIGHT 1990
 *                    DIGITAL EQUIPMENT CORPORATION
 *                       MAYNARD, MASSACHUSETTS
 *                        ALL RIGHTS RESERVED.
 *
 * THE INFORMATION IN THIS SOFTWARE IS SUBJECT TO CHANGE WITHOUT NOTICE AND
 * SHOULD NOT BE CONSTRUED AS A COMMITMENT BY DIGITAL EQUIPMENT CORPORATION.
 * DIGITAL MAKES NO REPRESENTATIONS ABOUT THE SUITABILITY OF THIS SOFTWARE
 * FOR ANY PURPOSE.  IT IS SUPPLIED "AS IS" WITHOUT EXPRESS OR IMPLIED
 * WARRANTY.
 *
 * IF THE SOFTWARE IS MODIFIED IN A MANNER CREATING DERIVATIVE COPYRIGHT
 * RIGHTS, APPROPRIATE LEGENDS MAY BE PLACED ON THE DERIVATIVE WORK IN
 * ADDITION TO THAT SET FORTH ABOVE.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose and without fee is hereby granted, provided
 * that the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of Digital Equipment Corporation not be
 * used in advertising or publicity pertaining to distribution of the
 * software without specific, written prior permission.
 \*/

/***====================================================================***/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <X11/Xfuncproto.h>

/*
 * We sometimes malloc strings and then expose them as const char*'s. This
 * macro is used when we free these strings in order to avoid -Wcast-qual
 * errors.
 */
#define UNCONSTIFY(const_ptr)  ((void *) (uintptr_t) (const_ptr))

#define uTypedAlloc(t)         ((t *) malloc(sizeof(t)))
#define uTypedCalloc(n, t)     ((t *) calloc((n), sizeof(t)))

#define uDupString(s)          ((s) ? strdup(s) : NULL)
#define uStringText(s)         ((s) == NULL ? "<NullString>" : (s))
#define uStrCasePrefix(s1, s2) (strncasecmp((s1), (s2), strlen(s1)) == 0)

/***====================================================================***/

extern bool
uSetErrorFile(char *name);

#define INFO uInformation

extern _X_ATTRIBUTE_PRINTF(1, 2) void
uInformation(const char *s, ...);

#define ACTION uAction

extern _X_ATTRIBUTE_PRINTF(1, 2) void
uAction(const char *s, ...);

#define WARN uWarning

extern _X_ATTRIBUTE_PRINTF(1, 2) void
uWarning(const char *s, ...);

#define ERROR uError

extern _X_ATTRIBUTE_PRINTF(1, 2) void
uError(const char *s, ...);

#define FATAL uFatalError

extern _X_ATTRIBUTE_PRINTF(1, 2) _X_NORETURN void
uFatalError(const char *s, ...);

/* WSGO stands for "Weird Stuff Going On" (wtf???) */
#define WSGO uInternalError

extern _X_ATTRIBUTE_PRINTF(1, 2) void
uInternalError(const char *s, ...);

#endif /* UTILS_H */
