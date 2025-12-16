
#include <tamtypes.h>
#include <kernel.h>
#include <sifrpc.h>
#include <loadfile.h>
#include <stdio.h>
#include <iopcontrol.h>
#include <iopheap.h>
#include <debug.h>
#include <libpad.h>

#define PAD_PORT 0
#define PAD_SLOT 0

int main(int argc, char *argv[])
{
    char padBuf[256] __attribute__((aligned(64)));
    struct padButtonStatus buttons;
    int ret;
    int port = PAD_PORT;
    int slot = PAD_SLOT;

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

    // Load pad modules
    scr_printf("Loading pad modules...\n");
    SifLoadModule("rom0:SIO2MAN", 0, NULL);
    SifLoadModule("rom0:PADMAN", 0, NULL);

    // Initialize pad library
    padInit(0);

    // Open pad port
    scr_printf("Opening pad port...\n");
    if ((ret = padPortOpen(port, slot, padBuf)) == 0)
    {
        scr_printf("ERROR: padPortOpen failed\n");
        while (1)
        {
            asm("nop");
        }
    }

    // Wait for pad to be ready
    scr_printf("Waiting for controller...\n");
    int state = padGetState(port, slot);
    while ((state != PAD_STATE_STABLE) && (state != PAD_STATE_FINDCTP1))
    {
        state = padGetState(port, slot);
    }

    scr_printf("Controller ready!\n");
    scr_printf("\nPress buttons to see input:\n\n");

    // Main loop - read and display controller input
    while (1)
    {
        ret = padRead(port, slot, &buttons);

        if (ret != 0)
        {
            int pad_data = 0xffff ^ buttons.btns;

            scr_printf("\r"); // Carriage return to overwrite line

            if (pad_data & PAD_LEFT)
            {
                scr_printf("LEFT ");
            }
            if (pad_data & PAD_RIGHT)
                scr_printf("RIGHT ");
            if (pad_data & PAD_UP)
                scr_printf("UP ");
            if (pad_data & PAD_DOWN)
                scr_printf("DOWN ");
            if (pad_data & PAD_CROSS)
                scr_printf("X ");
            if (pad_data & PAD_CIRCLE)
                scr_printf("O ");
            if (pad_data & PAD_SQUARE)
                scr_printf("[] ");
            if (pad_data & PAD_TRIANGLE)
                scr_printf("/\\ ");
            if (pad_data & PAD_L1)
                scr_printf("L1 ");
            if (pad_data & PAD_L2)
                scr_printf("L2 ");
            if (pad_data & PAD_R1)
                scr_printf("R1 ");
            if (pad_data & PAD_R2)
                scr_printf("R2 ");
            if (pad_data & PAD_START)
                scr_printf("START ");
            if (pad_data & PAD_SELECT)
                scr_printf("SELECT ");

            // Clear rest of line
            scr_printf("                    ");
        }
    }

    return 0;
}
