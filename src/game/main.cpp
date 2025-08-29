
#include <iostream>
#include <raylib.h>

#include "SceneManager.h"
#include "math/rgb.h"
#include "scenes/SceneMain.h"
#include "consts.h"


int main()
	{

		
		InitWindow(screenWidth, screenHeight, "Pocket Monster");
		std::cout << "Started\n";
		se::SceneManager& scene_manager = se::SceneManager::GetInstance();
		SceneMain main_scene = SceneMain();
		scene_manager.setMainScene(main_scene);
		
		while (!WindowShouldClose())
		{
		
			
			BeginDrawing();
			ClearBackground(RGB(189, 250, 255).rayify());
			EndDrawing();


		}
	
		CloseWindow();
	
	}





