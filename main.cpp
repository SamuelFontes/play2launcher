
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

    // Clear the screen
    scr_printf("\n\n");
    scr_printf("========================================\n");
    scr_printf("     PS2 Controller Test\n");
    scr_printf("========================================\n");
    scr_printf("\n");

    // Initialize gamepad
    InitGamepad(0,0);

    scr_printf("\nPress buttons to see input:\n\n");

    // Main loop - read and display controller input
    while (1)
    {

        // Update gamepad state
        GamepadState gamepad = GetGamepadState(0,0);

        // Display pressed buttons
        scr_printf("\r"); // Carriage return to overwrite line

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
        if (gamepad.start)
            scr_printf("START ");
        if (gamepad.select)
            scr_printf("SELECT ");

        // Clear rest of line
        scr_printf("                    ");
    }

    return 0;
}
