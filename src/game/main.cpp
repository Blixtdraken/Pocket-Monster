
#include <iostream>
#include <raylib.h>

#include "SceneManager.h"
#include "math/rgb.h"
#include "scenes/SceneMain.h"
#include "consts.h"


int main()
	{

		
		InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pocket Monster");
		SetWindowIcon(LoadImage("assets/sprites/gumboo-1.png"));
		std::cout << "Started\n";
		se::SceneManager& scene_manager = se::SceneManager::GetInstance();
		SceneMain* main_scene = new SceneMain();
		
		scene_manager.initSceneLoop(main_scene);
	
		CloseWindow();
	}





