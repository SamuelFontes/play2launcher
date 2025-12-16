#include "gamepad.h"
#include <libpad.h>
#include <sifrpc.h>
#include <loadfile.h>
#include <debug.h>

// Initialize gamepad system
void InitGamepad(int port, int slot)
{
    int ret;
    char padBuf[256] __attribute__((aligned(64)));
    // Load pad modules
    scr_printf("Loading pad modules...\n");
    SifLoadModule("rom0:SIO2MAN", 0, (const char*)NULL);
    SifLoadModule("rom0:PADMAN", 0, (const char*)NULL);

    // Initialize pad library
    padInit(0);

    // Open pad port
    scr_printf("Opening pad port...\n");
    if ((ret = padPortOpen(port, slot, padBuf)) == 0)
    {
        scr_printf("ERROR: padPortOpen failed\n");
    }

    // Wait for pad to be ready
    scr_printf("Waiting for controller...\n");
    int state = padGetState(port, slot);
    while ((state != PAD_STATE_STABLE) && (state != PAD_STATE_FINDCTP1))
    {
        state = padGetState(port, slot);
    }

    scr_printf("Controller ready!\n");
}

// Update gamepad state from pad data
GamepadState GetGamepadState(int port, int slot)
{
    GamepadState state = {};
    struct padButtonStatus buttons;
    int ret = padRead(port, slot, &buttons);

    if (ret != 0)
    {
        state.raw_buttons = 0xffff ^ buttons.btns;
        
        state.left = (state.raw_buttons & PAD_LEFT) ? 1 : 0;
        state.right = (state.raw_buttons & PAD_RIGHT) ? 1 : 0;
        state.up = (state.raw_buttons & PAD_UP) ? 1 : 0;
        state.down = (state.raw_buttons & PAD_DOWN) ? 1 : 0;
        state.cross = (state.raw_buttons & PAD_CROSS) ? 1 : 0;
        state.circle = (state.raw_buttons & PAD_CIRCLE) ? 1 : 0;
        state.square = (state.raw_buttons & PAD_SQUARE) ? 1 : 0;
        state.triangle = (state.raw_buttons & PAD_TRIANGLE) ? 1 : 0;
        state.l1 = (state.raw_buttons & PAD_L1) ? 1 : 0;
        state.l2 = (state.raw_buttons & PAD_L2) ? 1 : 0;
        state.r1 = (state.raw_buttons & PAD_R1) ? 1 : 0;
        state.r2 = (state.raw_buttons & PAD_R2) ? 1 : 0;
        state.l3 = (state.raw_buttons & PAD_L3) ? 1 : 0;
        state.r3 = (state.raw_buttons & PAD_R3) ? 1 : 0;
        state.start = (state.raw_buttons & PAD_START) ? 1 : 0;
        state.select = (state.raw_buttons & PAD_SELECT) ? 1 : 0;
        
        // Read analog stick values
        state.right_stick_x = buttons.rjoy_h;
        state.right_stick_y = buttons.rjoy_v;
        state.left_stick_x = buttons.ljoy_h;
        state.left_stick_y = buttons.ljoy_v;
    }
    return state;
}
