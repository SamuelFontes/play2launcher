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
    int start;
    int select;
} GamepadState;

// Initialize gamepad system
void InitGamepad(int port, int slot);

// Update gamepad state from pad data
GamepadState GetGamepadState(int port, int slot);

