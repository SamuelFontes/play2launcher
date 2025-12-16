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
