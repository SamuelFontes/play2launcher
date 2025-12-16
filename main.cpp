
#include <tamtypes.h>
#include <kernel.h>
#include <sifrpc.h>
#include <stdio.h>
#include <debug.h>
#include "gamepad.h"


int main(int argc, char *argv[])
{
  

    // Initialize debug screen
    init_scr();

    // Reset and initialize IOP (Input/Output Processor)
    SifInitRpc(0);

    // Initialize gamepad
    InitGamepad(0,0);

    scr_printf("\nPress buttons to see input:\n\n");
    GamepadState lastGamepadState = {};
    lastGamepadState.circle = 1; // Ensure first read is different

    // Main loop - read and display controller input
    while (1)
    {
        // Update gamepad state
        GamepadState gamepad = GetGamepadState(0,0);
        if(lastGamepadState == gamepad)
        {
            continue;
        }
        // Clear the screen every frame
        scr_clear();

        // Redraw UI
        scr_printf("========================================\n");
        scr_printf("     PS2 Controller Test\n");
        scr_printf("========================================\n");
        scr_printf("\n");
        scr_printf("Press buttons to see input:\n\n");

        // Display pressed buttons
        scr_printf("Buttons: ");
        if (gamepad.left)
            scr_printf("LEFT ");
        if (gamepad.right)
            scr_printf("RIGHT ");
        if (gamepad.up)
            scr_printf("UP ");
        if (gamepad.down)
            scr_printf("DOWN ");
        if (gamepad.cross)
            scr_printf("X ");
        if (gamepad.circle)
            scr_printf("O ");
        if (gamepad.square)
            scr_printf("[] ");
        if (gamepad.triangle)
            scr_printf("/\\ ");
        if (gamepad.l1)
            scr_printf("L1 ");
        if (gamepad.l2)
            scr_printf("L2 ");
        if (gamepad.r1)
            scr_printf("R1 ");
        if (gamepad.r2)
            scr_printf("R2 ");
        if (gamepad.l3)
            scr_printf("L3 ");
        if (gamepad.r3)
            scr_printf("R3 ");
        if (gamepad.start)
            scr_printf("START ");
        if (gamepad.select)
            scr_printf("SELECT ");

        scr_printf("\n");
        // Display analog stick values
        scr_printf("Left Stick : (%3d, %3d)\n", gamepad.left_stick_x, gamepad.left_stick_y);
        scr_printf("Right Stick: (%3d, %3d)\n", gamepad.right_stick_x, gamepad.right_stick_y);

        lastGamepadState = gamepad;
    }

    return 0;
}
