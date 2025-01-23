#ifndef __EMOJI_FONT_H__
#define __EMOJI_FONT_H__
#include "lvgl.h"
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

const lv_font_t* emoji_font_init(void);
const lv_font_t* emoji_font_64_lite_init(void);

#ifdef __cplusplus
}
#endif

#endif
