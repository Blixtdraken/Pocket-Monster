#pragma once
#include "interfaces/iScene.h"


class SceneMain: public se::iScene
{
    void _sceneSetup() override;
    
public:
    int num = 0;
};