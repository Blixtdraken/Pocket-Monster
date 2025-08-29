#include "SceneManager.h"

#include <system_error>



void se::SceneManager::changeScene(iScene& new_scene)
{
   if (m_current_scene)
   {
      delete m_current_scene;
      m_current_scene =&new_scene;
   }else
   {
      throw 404;
   }

}


void se::SceneManager::setMainScene(iScene& new_scene)
{
   m_current_scene = &new_scene;
}
