#include "lvgl.h"
#include <stdio.h>

// 声明所有21个emoji图像
extern lv_img_dsc_t em64_f602;
extern lv_img_dsc_t em64_f606;
extern lv_img_dsc_t em64_f609;
extern lv_img_dsc_t em64_f60a;
extern lv_img_dsc_t em64_f60b;
extern lv_img_dsc_t em64_f60c;
extern lv_img_dsc_t em64_f60d;
extern lv_img_dsc_t em64_f60e;
extern lv_img_dsc_t em64_f60f;
extern lv_img_dsc_t em64_f614;
extern lv_img_dsc_t em64_f615;
extern lv_img_dsc_t em64_f618;
extern lv_img_dsc_t em64_f620;
extern lv_img_dsc_t em64_f628;
extern lv_img_dsc_t em64_f62d;
extern lv_img_dsc_t em64_f62f;
extern lv_img_dsc_t em64_f633;
extern lv_img_dsc_t em64_f634;
extern lv_img_dsc_t em64_f636;
extern lv_img_dsc_t em64_f914;
extern lv_img_dsc_t em64_f92a;


//typedef bool (*lv_get_imgfont_path_cb_t)(const lv_font_t * font, void * img_src, uint16_t len, uint32_t unicode, uint32_t unicode_next);
static bool get_imgfont_path(const lv_font_t * font, void * img_src,
                             uint16_t len, uint32_t unicode, uint32_t unicode_next)
{


    // 修改emoji表，包含所有21个emoji
    static const lv_img_dsc_t *emoji_table[] = {
        &em64_f602, &em64_f606, &em64_f609, &em64_f60a, &em64_f60b,
        &em64_f60c, &em64_f60d, &em64_f60e, &em64_f60f, &em64_f614,
        &em64_f615, &em64_f618, &em64_f620, &em64_f628, &em64_f92a,
        &em64_f62d, &em64_f62f, &em64_f633, &em64_f634, &em64_f636,
        &em64_f914
    };
    
 

    // 检查是否在支持的emoji范围内
    uint32_t supported_unicodes[] = {
        0x1F602, 0x1F606, 0x1F609, 0x1F60A, 0x1F60B,
        0x1F60C, 0x1F60D, 0x1F60E, 0x1F60F, 0x1F614,
        0x1F615, 0x1F618, 0x1F620, 0x1F628, 0x1F92A,
        0x1F62D, 0x1F62F, 0x1F633, 0x1F634, 0x1F636,
        0x1F914
    };
    
    for(int i = 0; i < sizeof(emoji_table)/sizeof(emoji_table[0]); i++) {
        if(unicode == supported_unicodes[i]) {
            memcpy(img_src, emoji_table[i], sizeof(lv_img_dsc_t));
            return true;
        }
    }

    return false;
}
 
 
const lv_font_t* emoji_font_64_lite_init(void)
{
    lv_font_t* emoji_font_64_lite = lv_imgfont_create(64, get_imgfont_path);
    if(emoji_font_64_lite == NULL) {
        LV_LOG_ERROR("imgfont init error");
        return NULL;
    }
    emoji_font_64_lite->base_line = 0;
    

    emoji_font_64_lite->fallback = NULL;

    return emoji_font_64_lite;
}

