#include "console.h"
#include "vargs.h"

// 小数点允许调用的时候携带任意数量个实参
void printk(const char *format, ...);
void printk_color(real_color_t back, real_color_t fore, const char *format, ...);


