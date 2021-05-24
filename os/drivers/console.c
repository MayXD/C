#include "common.h"
#include "console.h"

static uint16_t *video_memory = (uint16_t *)0xB8000;

static uint8_t cursor_x = 0;
static uint8_t cursor_y = 0;

static void move_cursor()
{
    uint16_t cursorLocation = cursor_y * 80 + cursor_y;
    outb(0x3D4, 14);
    outb(0x3D5, cursorLocation >> 8);
    outb(0x3D4, 15);
    outb(0x3D5, cursorLocation);
}

void console_clear()
{
    uint8_t attribute_byte = (0 << 4) | (15 & 0x0F);
    uint16_t blank = 0x20 | (attribute_byte << 8);
    int i;
    for (i=1;i<80*25;i++) {
        video_memory[i] = blank;
    }
    cursor_x = 0;
    cursor_y = 0;
    move_cursor();
}

static void scroll(){
    uint8_t attribute_byte = (0 << 4) | (15 & 0x0F);
    uint16_t blank = 0x20 | (attribute_byte << 8);

    if (cursor_y >= 25){
        int i;
        for (i=0;i<24*80;i++){
            video_memory[i] = video_memory[i+80];
        }
        for (i=24*80;i<25*80;i++){
            video_memory[i] = blank;
        }
        cursor_y=24;
    }
}

void console_putc_color(char c, real_color_t back, real_color_t fore){
    uint8_t back_color = (uint8_t)back;
    uint8_t fore_color = (uint8_t)fore;

    uint8_t attribute_byte = (back_color << 4) | (fore_color & 0x0F);
    uint16_t attribute = attribute_byte << 8;

    // 0x08 是退格键的 ASCII 码
    // 0x09 是tab键的 ASCII 码
    if (c == 0x08 && cursor_x){
        cursor_x--;
    } else if (c == 0x09) {
    // tab键补全8位
        cursor_x = (cursor_x+8) & ~(8-1);
    } else if (c == '\r') {
        cursor_x = 0;
    } else if (c == '\n') {
        cursor_x = 0;
        cursor_y++;
    // 空格之后的字符都是常用的输入字符
    } else if (c >= ' ') {
        video_memory[cursor_y*80+cursor_x] = c | attribute; 
        cursor_x++;
    }

    if (cursor_x >= 80){
        cursor_x = 0;
        cursor_y ++;
    }

    scroll();
    move_cursor();
}

void console_write(char *cstr){
    while (*cstr){
        console_putc_color(*cstr++, rc_black, rc_white);
    }
}

void console_write_color(char *cstr, real_color_t back, real_color_t fore){
    while (*cstr){
        console_putc_color(*cstr++, back, fore);
    }
}

void console_write_hex(uint32_t n, real_color_t back, real_color_t fore){
    int tmp;
    char noZeros = 1;
    console_write_color("0x", back, fore);
    
    int i;
    for(i=28;i>=0;i-=4){
       tmp = (n >> i) & 0xF; 
       if (tmp == 0 && noZeros != 0){
           continue;
       }
       noZeros = 0;
       if (tmp >= 0xA){
           console_putc_color(tmp-0xA+'a', back, fore);
       } else{
           console_putc_color(tmp+'0', back, fore);
       }
    }
}

void console_write_dec(uint32_t n, real_color_t back, real_color_t fore){
    if (n == 0){
        console_putc_color('0', back, fore);
        return;
    }

    char c1[32];
    int i = 0;

    while (n > 0){
        c1[i] = '0' + n%10;
        n /= 10;
        i++;
    }
    c1[i] = 0;

    // c2是c1的逆序数组 
    char c2[32];
    c2[i--] = 0;
    int j = 0;

    while (i >= 0){
        c2[i--] = c1[j++];
    }
    console_write_color(c2, back, fore);
}