#include "SceneManager.h"

#include <system_error>


void se::SceneManager::sceneLoop()
{
   m_current_scene->_sceneSetup();
   m_current_scene->nodesReady();
   while (!WindowShouldClose())
   {
      m_current_scene->nodesHandleInput();
      m_current_scene->nodesUpdate(GetFrameTime());
      BeginDrawing();
      ClearBackground(m_current_scene->m_scene_color.rayify());
      m_current_scene->nodesRender();
      EndDrawing();
   }
}

void se::SceneManager::changeScene(iScene* new_scene)
{
   if (new_scene && m_current_scene)
   {
      delete m_current_scene;
      m_current_scene = new_scene;
   }else
   {
      throw std::invalid_argument("Scene can't be a nullptr");
   }

}


void se::SceneManager::initSceneLoop(iScene* main_scene)
{
   if (main_scene)
   {
      m_current_scene = main_scene;
   }else
   {
      throw std::invalid_argument("Scene can't be a nullptr");
   }
   m_current_scene = main_scene;
   sceneLoop();
}

