#pragma once
#include "interfaces/iScene.h"

namespace se
{
    class SceneManager
    {
    
    public://////////////////////////////////
        static SceneManager& GetInstance(){static SceneManager* m_instance = nullptr; if (m_instance) return *m_instance; m_instance = new SceneManager(); return *m_instance;}

        //////////////////////////////////////////////
    private:
        iScene* m_current_scene = nullptr;
        void sceneLoop();
    public:
        //////////////////////////////////////
        void changeScene(iScene* new_scene);
        void startSceneLoop(iScene* main_scene);
    
    
    };
}

