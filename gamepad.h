#pragma once

#include <tamtypes.h>

// Gamepad state structure
typedef struct
{
    u16 raw_buttons; // Raw button data
    int left;
    int right;
    int up;
    int down;
    int cross;
    int circle;
    int square;
    int triangle;
    int l1;
    int l2;
    int r1;
    int r2;
    int l3;
    int r3;
    int start;
    int select;
    // Analog stick values (0-255, centered at 128)
    u8 right_stick_x;
    u8 right_stick_y;
    u8 left_stick_x;
    u8 left_stick_y;
} GamepadState;

// Initialize gamepad system
void InitGamepad(int port, int slot);

// Update gamepad state from pad data
GamepadState GetGamepadState(int port, int slot);

