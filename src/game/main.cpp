
#include <iostream>
#include <raylib.h>

#include "SceneManager.h"
#include "math/rgb.h"
#include "scenes/BattleScene.h"
#include "consts.h"


int main()
	{
		SetRandomSeed(time(NULL));
		InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pocket Monster");
		SetWindowIcon(LoadImage("assets/sprites/gumboo-1.png"));
		SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));
		std::cout << "Started\n";
		se::SceneManager& scene_manager = se::SceneManager::GetInstance();
		BattleScene* main_scene = new BattleScene();
		
		scene_manager.initSceneLoop(main_scene);
	
		CloseWindow();
	}





