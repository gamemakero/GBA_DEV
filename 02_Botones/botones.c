#include "toolbox.h"
#include "video.h"
#include "regs.h"
#include "keys.h"

int main()
{
    REG_DISPCNT = DCNT_MODE3 | DCNT_BG2;

    m3_plot(120, 80, RGB15(31, 0, 0)); // or CLR_RED
    m3_plot(136, 80, RGB15(0, 31, 0)); // or CLR_LIME
    m3_plot(120, 96, RGB15(0, 0, 31)); // or CLR_BLUE

    while (1)
    {
        key_poll();
        if (key_is_down(KEY_A) && key_was_up(KEY_A))
        {
            colorScreen(CLR_RED);
        }
        else if(key_is_down(KEY_B) && key_was_up(KEY_B))
        {
            colorScreen(CLR_BLUE);
        }
    }

    return 0;
}

void colorScreen(COLOR clr)
{
    int i, j;
    for (i = 0; i < SCREEN_WIDTH; i++)
    {
        for (j = 0; j < SCREEN_HEIGHT; j++)
        {
            m3_plot(i, j, clr);
        }
    }
}
