file(GLOB EMOJI_SOURCES "emoji/*.c"  "emoji_64/*.c")
 idf_component_register(SRCS "emoji_font.c" "emoji_font_64_lite.c" ${EMOJI_SOURCES}
                       INCLUDE_DIRS "include"
                       PRIV_REQUIRES "lvgl")

include(package_manager)
cu_pkg_define_version(${CMAKE_CURRENT_LIST_DIR})
