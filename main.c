/*
 * PS2 Hello World Launcher
 * A simple .elf launcher for PlayStation 2
 */

#include <tamtypes.h>
#include <kernel.h>
#include <sifrpc.h>
#include <loadfile.h>
#include <stdio.h>
#include <iopcontrol.h>
#include <iopheap.h>
#include <debug.h>

int main(int argc, char *argv[])
{
    // Initialize debug screen
    init_scr();
    
    // Reset and initialize IOP (Input/Output Processor)
    SifInitRpc(0);
    
    // Clear the screen
    scr_printf("\n\n");
    scr_printf("========================================\n");
    scr_printf("     PS2 Hello World Launcher\n");
    scr_printf("========================================\n");

    // Infinite loop
    while (1) {
        asm("nop");
    }
    
    return 0;
}
