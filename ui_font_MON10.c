/*******************************************************************************
 * Size: 10 px
 * Bpp: 1
 * Opts: --bpp 1 --size 10 --font J:/Projects/Attendence_System/COREX_Security_System/OS/assets/Montserrat-Medium.ttf -o J:/Projects/Attendence_System/COREX_Security_System/OS/assets\ui_font_MON10.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "ui.h"

#ifndef UI_FONT_MON10
#define UI_FONT_MON10 1
#endif

#if UI_FONT_MON10

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xf2,

    /* U+0022 "\"" */
    0xb4,

    /* U+0023 "#" */
    0x24, 0x51, 0xf9, 0x4f, 0xc9, 0x12, 0x0,

    /* U+0024 "$" */
    0x23, 0xa9, 0x47, 0x16, 0xae, 0x20,

    /* U+0025 "%" */
    0xe4, 0xa4, 0xa8, 0xf6, 0x29, 0x29, 0x6,

    /* U+0026 "&" */
    0x30, 0x91, 0x41, 0xd, 0x51, 0x9d, 0x80,

    /* U+0027 "'" */
    0xc0,

    /* U+0028 "(" */
    0x6a, 0xaa, 0x40,

    /* U+0029 ")" */
    0x95, 0x55, 0x80,

    /* U+002A "*" */
    0x23, 0x9c,

    /* U+002B "+" */
    0x21, 0x3e, 0x42, 0x0,

    /* U+002C "," */
    0xd0,

    /* U+002D "-" */
    0xc0,

    /* U+002E "." */
    0xc0,

    /* U+002F "/" */
    0x12, 0x22, 0x44, 0x48, 0x80,

    /* U+0030 "0" */
    0x7b, 0x38, 0x61, 0x87, 0x37, 0x80,

    /* U+0031 "1" */
    0xe4, 0x92, 0x48,

    /* U+0032 "2" */
    0x70, 0x42, 0x22, 0x23, 0xe0,

    /* U+0033 "3" */
    0xf8, 0x88, 0xe0, 0x87, 0xc0,

    /* U+0034 "4" */
    0x10, 0xc6, 0x12, 0xfc, 0x20, 0x80,

    /* U+0035 "5" */
    0x7c, 0x21, 0xe0, 0x87, 0xc0,

    /* U+0036 "6" */
    0x7e, 0x21, 0xe8, 0xc5, 0xc0,

    /* U+0037 "7" */
    0xfe, 0x20, 0x84, 0x10, 0x82, 0x0,

    /* U+0038 "8" */
    0x72, 0x28, 0x9e, 0x86, 0x17, 0x80,

    /* U+0039 "9" */
    0x74, 0x62, 0xf0, 0x8f, 0xc0,

    /* U+003A ":" */
    0xc0, 0xc0,

    /* U+003B ";" */
    0xc0, 0xd0,

    /* U+003C "<" */
    0x36, 0x18, 0x30,

    /* U+003D "=" */
    0xf0, 0xf0,

    /* U+003E ">" */
    0xc1, 0xd9, 0x0,

    /* U+003F "?" */
    0x74, 0x42, 0x22, 0x0, 0x80,

    /* U+0040 "@" */
    0x1f, 0x18, 0x6d, 0xee, 0x89, 0xa2, 0x68, 0x9d,
    0xf9, 0x80, 0x3c, 0x0,

    /* U+0041 "A" */
    0x10, 0x50, 0xa1, 0x27, 0xc8, 0x60, 0x80,

    /* U+0042 "B" */
    0xfa, 0x18, 0x7f, 0x86, 0x1f, 0x80,

    /* U+0043 "C" */
    0x3d, 0x18, 0x20, 0x81, 0x13, 0xc0,

    /* U+0044 "D" */
    0xf9, 0xa, 0xc, 0x18, 0x30, 0xbe, 0x0,

    /* U+0045 "E" */
    0xfc, 0x21, 0xf8, 0x43, 0xe0,

    /* U+0046 "F" */
    0xfc, 0x21, 0xf8, 0x42, 0x0,

    /* U+0047 "G" */
    0x39, 0x18, 0x21, 0x85, 0x13, 0x80,

    /* U+0048 "H" */
    0x86, 0x18, 0x7f, 0x86, 0x18, 0x40,

    /* U+0049 "I" */
    0xfe,

    /* U+004A "J" */
    0xf1, 0x11, 0x19, 0xe0,

    /* U+004B "K" */
    0x8a, 0x6b, 0x38, 0xd2, 0x28, 0x40,

    /* U+004C "L" */
    0x84, 0x21, 0x8, 0x43, 0xe0,

    /* U+004D "M" */
    0x83, 0x8f, 0x1d, 0x5a, 0xb2, 0x60, 0x80,

    /* U+004E "N" */
    0x87, 0x1e, 0x6d, 0x9e, 0x38, 0x40,

    /* U+004F "O" */
    0x38, 0x8a, 0xc, 0x18, 0x28, 0x8e, 0x0,

    /* U+0050 "P" */
    0xfa, 0x18, 0x61, 0xfa, 0x8, 0x0,

    /* U+0051 "Q" */
    0x38, 0x8a, 0xc, 0x18, 0x28, 0x8e, 0x7,

    /* U+0052 "R" */
    0xfa, 0x18, 0x61, 0xfa, 0x28, 0x40,

    /* U+0053 "S" */
    0x74, 0x20, 0xe0, 0xc7, 0xc0,

    /* U+0054 "T" */
    0xf9, 0x8, 0x42, 0x10, 0x80,

    /* U+0055 "U" */
    0x86, 0x18, 0x61, 0x87, 0x37, 0x80,

    /* U+0056 "V" */
    0x82, 0x89, 0x11, 0x22, 0x85, 0x4, 0x0,

    /* U+0057 "W" */
    0x84, 0x28, 0xc9, 0x29, 0x25, 0x22, 0x98, 0x63,
    0xc, 0x60,

    /* U+0058 "X" */
    0x44, 0xd0, 0xa0, 0x82, 0x89, 0xb1, 0x0,

    /* U+0059 "Y" */
    0x44, 0x88, 0xa1, 0x41, 0x2, 0x4, 0x0,

    /* U+005A "Z" */
    0xfc, 0x21, 0x8, 0x61, 0xf, 0xc0,

    /* U+005B "[" */
    0xea, 0xaa, 0xc0,

    /* U+005C "\\" */
    0x88, 0x84, 0x42, 0x22, 0x10,

    /* U+005D "]" */
    0xd5, 0x55, 0xc0,

    /* U+005E "^" */
    0x66, 0xa9,

    /* U+005F "_" */
    0xf8,

    /* U+0060 "`" */
    0x40,

    /* U+0061 "a" */
    0x70, 0x7f, 0x1f, 0x80,

    /* U+0062 "b" */
    0x82, 0xf, 0xa3, 0x86, 0x1f, 0x80,

    /* U+0063 "c" */
    0x74, 0x21, 0x7, 0x0,

    /* U+0064 "d" */
    0x8, 0x5f, 0x18, 0xc5, 0xe0,

    /* U+0065 "e" */
    0x72, 0x2f, 0xa0, 0x78,

    /* U+0066 "f" */
    0x74, 0xf4, 0x44, 0x40,

    /* U+0067 "g" */
    0x7e, 0x38, 0x63, 0x7c, 0x17, 0x80,

    /* U+0068 "h" */
    0x84, 0x3d, 0x18, 0xc6, 0x20,

    /* U+0069 "i" */
    0xbe,

    /* U+006A "j" */
    0x20, 0x92, 0x49, 0xe0,

    /* U+006B "k" */
    0x84, 0x27, 0x4e, 0x4a, 0x20,

    /* U+006C "l" */
    0xfe,

    /* U+006D "m" */
    0xf7, 0x44, 0x62, 0x31, 0x18, 0x88,

    /* U+006E "n" */
    0xf4, 0x63, 0x18, 0x80,

    /* U+006F "o" */
    0x7a, 0x18, 0x61, 0x78,

    /* U+0070 "p" */
    0xfa, 0x38, 0x61, 0xfa, 0x8, 0x0,

    /* U+0071 "q" */
    0x7c, 0x63, 0x17, 0x84, 0x20,

    /* U+0072 "r" */
    0xf2, 0x48,

    /* U+0073 "s" */
    0x74, 0x18, 0x2f, 0x0,

    /* U+0074 "t" */
    0x4f, 0x44, 0x47,

    /* U+0075 "u" */
    0x8c, 0x63, 0x17, 0x80,

    /* U+0076 "v" */
    0x89, 0x25, 0xc, 0x30,

    /* U+0077 "w" */
    0x88, 0xaa, 0x95, 0x4a, 0xa2, 0x20,

    /* U+0078 "x" */
    0x4b, 0x88, 0xa4, 0x80,

    /* U+0079 "y" */
    0x89, 0x25, 0xc, 0x30, 0x8c, 0x0,

    /* U+007A "z" */
    0xf8, 0x88, 0x8f, 0x80,

    /* U+007B "{" */
    0x69, 0x28, 0x92, 0x60,

    /* U+007C "|" */
    0xff, 0x80,

    /* U+007D "}" */
    0xc9, 0x26, 0x92, 0xc0,

    /* U+007E "~" */
    0xd5, 0x80
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 43, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 43, .box_w = 1, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2, .adv_w = 63, .box_w = 3, .box_h = 2, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 3, .adv_w = 112, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 10, .adv_w = 99, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 16, .adv_w = 135, .box_w = 8, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 23, .adv_w = 110, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 30, .adv_w = 34, .box_w = 1, .box_h = 2, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 31, .adv_w = 54, .box_w = 2, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 34, .adv_w = 54, .box_w = 2, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 37, .adv_w = 64, .box_w = 5, .box_h = 3, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 39, .adv_w = 93, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 43, .adv_w = 36, .box_w = 2, .box_h = 3, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 44, .adv_w = 61, .box_w = 2, .box_h = 1, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 45, .adv_w = 36, .box_w = 2, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 46, .adv_w = 56, .box_w = 4, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 51, .adv_w = 107, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 57, .adv_w = 59, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 60, .adv_w = 92, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 65, .adv_w = 92, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 70, .adv_w = 107, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 76, .adv_w = 92, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 81, .adv_w = 99, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 86, .adv_w = 96, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 92, .adv_w = 103, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 98, .adv_w = 99, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 103, .adv_w = 36, .box_w = 2, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 105, .adv_w = 36, .box_w = 2, .box_h = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 107, .adv_w = 93, .box_w = 5, .box_h = 4, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 110, .adv_w = 93, .box_w = 4, .box_h = 3, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 112, .adv_w = 93, .box_w = 5, .box_h = 4, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 115, .adv_w = 92, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 120, .adv_w = 165, .box_w = 10, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 132, .adv_w = 117, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 139, .adv_w = 121, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 145, .adv_w = 114, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 151, .adv_w = 132, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 158, .adv_w = 107, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 163, .adv_w = 102, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 168, .adv_w = 124, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 174, .adv_w = 130, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 180, .adv_w = 50, .box_w = 1, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 181, .adv_w = 82, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 185, .adv_w = 115, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 191, .adv_w = 95, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 196, .adv_w = 153, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 203, .adv_w = 130, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 209, .adv_w = 134, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 216, .adv_w = 116, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 222, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 229, .adv_w = 116, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 235, .adv_w = 99, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 240, .adv_w = 94, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 245, .adv_w = 127, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 251, .adv_w = 114, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 258, .adv_w = 180, .box_w = 11, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 268, .adv_w = 108, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 275, .adv_w = 104, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 282, .adv_w = 105, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 288, .adv_w = 53, .box_w = 2, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 291, .adv_w = 56, .box_w = 4, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 296, .adv_w = 53, .box_w = 2, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 299, .adv_w = 93, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 301, .adv_w = 80, .box_w = 5, .box_h = 1, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 302, .adv_w = 96, .box_w = 3, .box_h = 1, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 303, .adv_w = 96, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 307, .adv_w = 109, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 313, .adv_w = 91, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 317, .adv_w = 109, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 322, .adv_w = 98, .box_w = 6, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 326, .adv_w = 56, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 330, .adv_w = 110, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 336, .adv_w = 109, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 341, .adv_w = 45, .box_w = 1, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 342, .adv_w = 45, .box_w = 3, .box_h = 9, .ofs_x = -1, .ofs_y = -2},
    {.bitmap_index = 346, .adv_w = 98, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 351, .adv_w = 45, .box_w = 1, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 352, .adv_w = 169, .box_w = 9, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 358, .adv_w = 109, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 362, .adv_w = 102, .box_w = 6, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 366, .adv_w = 109, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 372, .adv_w = 109, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 377, .adv_w = 66, .box_w = 3, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 379, .adv_w = 80, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 383, .adv_w = 66, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 386, .adv_w = 108, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 390, .adv_w = 89, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 394, .adv_w = 144, .box_w = 9, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 400, .adv_w = 88, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 404, .adv_w = 89, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 410, .adv_w = 83, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 414, .adv_w = 56, .box_w = 3, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 418, .adv_w = 48, .box_w = 1, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 420, .adv_w = 56, .box_w = 3, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 424, .adv_w = 93, .box_w = 5, .box_h = 2, .ofs_x = 1, .ofs_y = 2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_MON10 = {
#else
lv_font_t ui_font_MON10 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 10,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_MON10*/

