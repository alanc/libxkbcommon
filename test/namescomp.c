/*
 * Copyright 2009 Dan Nicholson
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

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "xkb-priv.h"
#include "xkbcommon/xkbcommon.h"
#include "test.h"

static int
test_names(struct xkb_context *context, const char *keycodes,
           const char *types, const char *compat, const char *symbols)
{
    int ret = 1;
    struct xkb_keymap *keymap;
    struct xkb_component_names kccgst = {
        .keycodes = strdup(keycodes),
        .types = strdup(types),
        .compat = strdup(compat),
        .symbols = strdup(symbols),
    };

    fprintf(stderr, "\nCompiling %s %s %s %s\n", kccgst.keycodes, kccgst.types,
            kccgst.compat, kccgst.symbols);

    keymap = xkb_map_new_from_kccgst(context, &kccgst, 0);
    if (!keymap) {
        ret = 0;
        goto err_context;
    }

    xkb_map_unref(keymap);
err_context:
    free(kccgst.keycodes);
    free(kccgst.types);
    free(kccgst.compat);
    free(kccgst.symbols);
    return ret;
}

int
main(void)
{
    struct xkb_context *ctx = test_get_context();

    assert(ctx);

    assert(test_names(ctx, "evdev+aliases(qwertz)",   "complete", "complete", "pc+de"));
    assert(test_names(ctx, "evdev+aliases(qwerty)",   "complete", "complete", "pc+us"));
    assert(test_names(ctx, "evdev+aliases(qwertz)",   "complete", "complete",
                      "pc+de+level3(ralt_switch_for_alts_toggle)+group(alts_toggle)"));

    assert(!test_names(ctx, "",                        "",         "",         ""));
    assert(!test_names(ctx, "evdev+aliases(qwerty)",   "",         "",         ""));
    assert(!test_names(ctx, "evdev+aliases(qwertz)",   "",         "",         "pc+de"));
    assert(!test_names(ctx, "evdev+aliases(qwertz)",   "complete", "",         "pc+de"));
    assert(!test_names(ctx, "evdev+aliases(qwertz)",   "",         "complete", "pc+de"));
    assert(!test_names(ctx, "evdev+aliases(qwertz)",   "complete", "complete", ""));
    assert(!test_names(ctx, "badnames",                "complete", "pc+us",    "pc(pc101)"));

    xkb_context_unref(ctx);

    return 0;
}
