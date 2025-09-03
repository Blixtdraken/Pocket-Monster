#pragma once
#include "math/vector2.h"

//Raylib
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;


//Screen Positions
const se::Vec2 FRIEND_MON_POS = se::Vec2(380,554);
const se::Vec2 ENEMEY_MON_POS = se::Vec2(840,364);

//Animations
const float ANIMATION_TIME = 1.0f;


//Element multiplier   Layout [Attacker][Defender]
const float ELEMENT_TABLE[6][6] = {                //Attacking side
    {   1.00f,  1.00f,  1.00f,  1.00f,  1.00f,  1.00f   }, // NORMAL
    {   1.00f,  0.80f,  0.80f,  1.20f,  1.00f,  1.20f   }, // FIRE
    {   1.00f,  1.20f,  1.00f,  0.80f,  1.20f,  0.80f   }, // WATER
    {   1.00f,  0.80f,  1.20f,  1.00f,  1.20f,  0.80f   }, // GRASS
    {   1.00f,  0.80f,  1.20f,  1.00f,  1.00f,  1.20f   }, // ELECTRIC
    {   1.00f,  0.80f,  1.00f,  1.00f,  0.80f,  1.20f   }, // STEEL
 //          N       F       W       G       E       S 
 //Defending Side
};