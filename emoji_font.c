#include "lvgl.h"
#include <stdio.h>
 

extern lv_img_dsc_t f601;
extern lv_img_dsc_t f602;
extern lv_img_dsc_t f603;
extern lv_img_dsc_t f604;
extern lv_img_dsc_t f605;
extern lv_img_dsc_t f606;
extern lv_img_dsc_t f607;
extern lv_img_dsc_t f608;
extern lv_img_dsc_t f609;
extern lv_img_dsc_t f60a;
extern lv_img_dsc_t f60b;
extern lv_img_dsc_t f60c;
extern lv_img_dsc_t f60d;
extern lv_img_dsc_t f60e;
extern lv_img_dsc_t f60f;
extern lv_img_dsc_t f610;
extern lv_img_dsc_t f611;
extern lv_img_dsc_t f612;
extern lv_img_dsc_t f613;
extern lv_img_dsc_t f614;
extern lv_img_dsc_t f615;
extern lv_img_dsc_t f616;
extern lv_img_dsc_t f617;
extern lv_img_dsc_t f618;
extern lv_img_dsc_t f619;
extern lv_img_dsc_t f61a;
extern lv_img_dsc_t f61b;
extern lv_img_dsc_t f61c;
extern lv_img_dsc_t f61d;
extern lv_img_dsc_t f61e;
extern lv_img_dsc_t f61f;
extern lv_img_dsc_t f620;
extern lv_img_dsc_t f621;
extern lv_img_dsc_t f622;
extern lv_img_dsc_t f623;
extern lv_img_dsc_t f624;
extern lv_img_dsc_t f625;
extern lv_img_dsc_t f626;
extern lv_img_dsc_t f627;
extern lv_img_dsc_t f628;
extern lv_img_dsc_t f629;
extern lv_img_dsc_t f62a;
extern lv_img_dsc_t f62b;
extern lv_img_dsc_t f62c;
extern lv_img_dsc_t f62d;
extern lv_img_dsc_t f62e;
extern lv_img_dsc_t f62f;
extern lv_img_dsc_t f630;
extern lv_img_dsc_t f631;
extern lv_img_dsc_t f632;
extern lv_img_dsc_t f633;
extern lv_img_dsc_t f634;
extern lv_img_dsc_t f635;
extern lv_img_dsc_t f636;
extern lv_img_dsc_t f637;
extern lv_img_dsc_t f266a;
extern lv_img_dsc_t f914;
extern lv_img_dsc_t f92a;


//typedef bool (*lv_get_imgfont_path_cb_t)(const lv_font_t * font, void * img_src, uint16_t len, uint32_t unicode, uint32_t unicode_next);
static bool get_imgfont_path(const lv_font_t * font, void * img_src,
                             uint16_t len, uint32_t unicode, uint32_t unicode_next)
{

    static const lv_img_dsc_t *emoji_table[] = {
        &f601, &f602, &f603, &f604, &f605, &f606, &f607, &f608, &f609, &f60a, &f60b, &f60c, &f60d, &f60e, &f60f,
        &f610, &f611, &f612, &f613, &f614, &f615, &f616, &f617, &f618, &f619, &f61a, &f61b, &f61c, &f61d, &f61e, &f61f,
        &f620, &f621, &f622, &f623, &f624, &f625, &f626, &f627, &f628, &f629, &f62a, &f62b, &f62c, &f62d, &f62e, &f62f,
        &f630, &f631, &f632, &f633, &f634, &f635, &f636, &f637
    };

    //printf("unicode: %lx\n", unicode);
    if(unicode == 0x266A) {
        memcpy(img_src, &f266a, sizeof(lv_img_dsc_t));
        return true;
    }
    if(unicode == 0x1f914) {
        memcpy(img_src, &f914, sizeof(lv_img_dsc_t));
        return true;
    }   
    
    if(unicode == 0x1f92a) {
        memcpy(img_src, &f92a, sizeof(lv_img_dsc_t));
        return true;
    }   

    if(unicode < 0x1F601 || unicode > 0x1F637 ) return false;

    int index = unicode - 0x1F601;

    memcpy(img_src, emoji_table[index], sizeof(lv_img_dsc_t));

    return true;
  
}
 
 
const lv_font_t* emoji_font_init(void)
{
    lv_font_t* emoji_font = lv_imgfont_create(32, get_imgfont_path);
    if(emoji_font == NULL) {
        LV_LOG_ERROR("imgfont init error");
        return NULL;
    }
    emoji_font->base_line = 0;

    emoji_font->fallback = NULL;

    return emoji_font;
}

 