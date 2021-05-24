#include "console.h"

int kern_entry()
{
    console_clear();
    console_write_color("Hello,my name is May", rc_black, rc_green);
    console_write_dec(80, rc_light_red, rc_light_green);
    return 0;
}