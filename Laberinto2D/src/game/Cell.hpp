#pragma once
#include <cstdint>
#include <engine/texture.hpp>
#include <engine/sprite.hpp>
#include <utils/color.h>
struct Cell:public Sprite_t{
    Cell(float x,float y ,float width ,float heigth):Sprite_t(Texture_t{_sprite,2,2},x,y,width,heigth){}
private:
    static constexpr uint32_t _sprite[] ={
        COLOR::ORANGE,COLOR::ORANGE,
        COLOR::ORANGE,COLOR::ORANGE,
    };
};