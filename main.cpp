// Simple raylib example for PS2
// This file demonstrates basic raylib usage

#include "raylib.h"

int main(void)
{
    // PS2 standard resolution
    const int screenWidth = 640;
    const int screenHeight = 448;

    InitWindow(screenWidth, screenHeight, "Play2Launcher - Raylib Test");
    SetTargetFPS(60);

    Vector2 ballPosition = { (float)screenWidth / 2, (float)screenHeight / 2 };
    Vector2 ballSpeed = { 2.0f, 2.0f };
    float ballRadius = 20.0f;
    // Texture2D texture = LoadTexture("resources/afatso.png");

    int frameCounter = 0;

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        frameCounter++;
        
        ballPosition.x += ballSpeed.x;
        ballPosition.y += ballSpeed.y;

        // Check collision with screen borders
        if ((ballPosition.x >= (screenWidth - ballRadius)) || (ballPosition.x <= ballRadius))
            ballSpeed.x *= -1.0f;
        if ((ballPosition.y >= (screenHeight - ballRadius)) || (ballPosition.y <= ballRadius))
            ballSpeed.y *= -1.0f;

        // Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("Play2Launcher with Raylib!", 120, 20, 30, DARKGRAY);
            DrawText("PS2 OpenGL Rendering", 190, 60, 20, GRAY);
            // Show status for several gamepad buttons (pressed = RED, otherwise DARKGRAY)
            int baseY = 340;
            int lineH = 18;
            int col1 = 10;
            int col2 = 220;
            int col3 = 430;

            // Right face buttons (PS2: Cross, Circle, Square, Triangle)
            DrawText(IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN) ? "Right Face Down (X) - Down" : "Right Face Down (X) - Up", col1, baseY + 0 * lineH, 18, IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN) ? RED : DARKGRAY);
            DrawText(IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT) ? "Right Face Right (Circle) - Down" : "Right Face Right (Circle) - Up", col1, baseY + 1 * lineH, 18, IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT) ? RED : DARKGRAY);
            DrawText(IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_UP) ? "Right Face Up (Triangle) - Down" : "Right Face Up (Triangle) - Up", col1, baseY + 2 * lineH, 18, IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_UP) ? RED : DARKGRAY);
            DrawText(IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_LEFT) ? "Right Face Left (Square) - Down" : "Right Face Left (Square) - Up", col1, baseY + 3 * lineH, 18, IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_FACE_LEFT) ? RED : DARKGRAY);

            // D-Pad buttons
            DrawText(IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN) ? "D-Pad Down - Down" : "D-Pad Down - Up", col2, baseY + 0 * lineH, 18, IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN) ? RED : DARKGRAY);
            DrawText(IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT) ? "D-Pad Right - Down" : "D-Pad Right - Up", col2, baseY + 1 * lineH, 18, IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT) ? RED : DARKGRAY);
            DrawText(IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_UP) ? "D-Pad Up - Down" : "D-Pad Up - Up", col2, baseY + 2 * lineH, 18, IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_UP) ? RED : DARKGRAY);
            DrawText(IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT) ? "D-Pad Left - Down" : "D-Pad Left - Up", col2, baseY + 3 * lineH, 18, IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT) ? RED : DARKGRAY);

            // Shoulders / triggers / thumb buttons
            DrawText(IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_THUMB) ? "L3 (Left Stick) - Down" : "L3 (Left Stick) - Up", col3, baseY + 0 * lineH, 18, IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_THUMB) ? RED : DARKGRAY);
            DrawText(IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_THUMB) ? "R3 (Right Stick) - Down" : "R3 (Right Stick) - Up", col3, baseY + 1 * lineH, 18, IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_THUMB) ? RED : DARKGRAY);
            DrawText(IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_TRIGGER_1) ? "L1 - Down" : "L1 - Up", col3, baseY + 2 * lineH, 18, IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_TRIGGER_1) ? RED : DARKGRAY);
            DrawText(IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_TRIGGER_1) ? "R1 - Down" : "R1 - Up", col3, baseY + 3 * lineH, 18, IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_TRIGGER_1) ? RED : DARKGRAY);

            DrawCircleV(ballPosition, ballRadius, MAROON);
            // Draw texture centered on ballPosition
            // Vector2 texPos = { ballPosition.x - (float)texture.width * 0.5f,ballPosition.y - (float)texture.height * 0.5f };
            // DrawTextureV(texture, texPos, WHITE);

            DrawFPS(10, 10);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
