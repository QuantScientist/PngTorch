/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "../include/utils/vision_utils.hpp"
#include <torch/script.h>

int main(int argc, char* argv[])
{
    VisionUtils VU = VisionUtils();
    torch::Device device = VU.getDevice();
    torch::Tensor tensor = torch::rand(1).to(device);
    auto randValueTorch= (tensor.data().detach().item().toFloat());
    std::cout<<tensor<<std::endl;
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 600;

    const char message[128] = "This example allocates a PyTorch tensor on the\nGPU/CPU (c++17), and then displayes its content in ray.";
    int framesCounter = 0;

    InitWindow(screenWidth, screenHeight, "TorchRayLib: Allocate a PyTorch tensor on the GPU/CPU (c++17)");

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();
        framesCounter++;

        ClearBackground(RAYWHITE);
//        DrawText("Allocated a PyTorch tensor on the GPU (c++17)", 10, 200, 30, ORANGE);
        DrawText(TextSubtext(message, 0, framesCounter/10), 10, 100, 30, ORANGE);
        std::stringstream sstm;
        auto gpuCount=(int)torch::cuda::device_count();
        sstm << tensor.toString() << ": " << randValueTorch<<", GPU count:"<<gpuCount<<std::endl;
        DrawText(sstm.str().c_str(), 40, 290, 40, DARKPURPLE);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}