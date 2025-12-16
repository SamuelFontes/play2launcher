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

// Equality operator for GamepadState so we can compare previous and current states.
// Compares all known fields explicitly.
static bool operator==(const GamepadState& a, const GamepadState& b)
{
    return a.left == b.left &&
           a.right == b.right &&
           a.up == b.up &&
           a.down == b.down &&
           a.cross == b.cross &&
           a.circle == b.circle &&
           a.square == b.square &&
           a.triangle == b.triangle &&
           a.l1 == b.l1 &&
           a.l2 == b.l2 &&
           a.r1 == b.r1 &&
           a.r2 == b.r2 &&
           a.l3 == b.l3 &&
           a.r3 == b.r3 &&
           a.start == b.start &&
           a.select == b.select &&
           a.left_stick_x == b.left_stick_x &&
           a.left_stick_y == b.left_stick_y &&
           a.right_stick_x == b.right_stick_x &&
           a.right_stick_y == b.right_stick_y;
}
// Initialize gamepad system
void InitGamepad(int port, int slot);

// Update gamepad state from pad data
GamepadState GetGamepadState(int port, int slot);

