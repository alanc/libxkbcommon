/*
 * Copyright 2009  Dan Nicholson
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Except as contained in this notice, the names of the authors or their
 * institutions shall not be used in advertising or otherwise to promote the
 * sale, use or other dealings in this Software without prior written
 * authorization from the authors.
 */

#ifndef TEXT_H
#define TEXT_H

#include "xkb-priv.h"

extern const char *
XkbcVModMaskText(struct xkb_keymap *keymap, unsigned modMask, unsigned mask);

extern const char *
XkbcModIndexText(unsigned ndx);

extern const char *
XkbcModMaskText(unsigned mask, bool cFormat);

extern const char *
XkbcFileTypeText(enum xkb_file_type type);

extern const char *
XkbcActionTypeText(unsigned type);

extern const char *
XkbcKeysymText(xkb_keysym_t sym);

extern const char *
XkbcKeyNameText(char *name);

extern const char *
XkbcSIMatchText(unsigned type);

#endif /* TEXT_H */
