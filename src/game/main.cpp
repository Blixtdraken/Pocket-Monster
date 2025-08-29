
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
		SceneMain* main_scene = new SceneMain();
		
		scene_manager.startSceneLoop(main_scene);
	
		CloseWindow();
	}





