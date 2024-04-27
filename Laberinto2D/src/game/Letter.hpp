#pragma once
#include <cstdint>
#include <engine/texture.hpp>
#include <engine/sprite.hpp>
#include <utils/color.h>
struct Letter_A_t:public Sprite_t{
    Letter_A_t(float x,float y ,float width ,float heigth):Sprite_t(Texture_t{_sprite_A,7,7},x,y,width,heigth){}
private:
    static constexpr uint32_t _sprite_A[] ={
        FILL,FILL,FILL,FILL,FILL,FILL,FILL,
        FILL,FILL,BLUE,BLUE,BLUE,FILL,FILL,
        FILL,BLUE,FILL,FILL,FILL,BLUE,FILL,
        FILL,BLUE,FILL,FILL,FILL,BLUE,FILL,
        FILL,BLUE,FILL,FILL,FILL,BLUE,FILL,
        FILL,BLUE,BLUE,BLUE,BLUE,BLUE,FILL,
        FILL,BLUE,FILL,FILL,FILL,BLUE,FILL,
        FILL,BLUE,FILL,FILL,FILL,BLUE,FILL,
        FILL,FILL,FILL,FILL,FILL,FILL,FILL
    };
};
struct Letter_B_t:public Sprite_t{
    Letter_B_t(float x,float y ,float width ,float heigth):Sprite_t(Texture_t{_sprite_B,7,9},x,y,width,heigth){}
private:
    static constexpr uint32_t _sprite_B[] ={
        FILL,FILL, FILL, FILL, FILL, FILL,FILL,
        FILL,BLUE, BLUE, BLUE, BLUE, FILL,FILL,
        FILL,BLUE, FILL, FILL, FILL, BLUE,FILL,
        FILL,BLUE, FILL, FILL, FILL, BLUE,FILL,
        FILL,BLUE, BLUE, BLUE, BLUE, FILL,FILL,
        FILL,BLUE, FILL, FILL, FILL, BLUE,FILL,
        FILL,BLUE, FILL, FILL, FILL, BLUE,FILL,
        FILL,BLUE, BLUE, BLUE, BLUE, FILL,FILL,
        FILL,FILL, FILL, FILL, FILL, FILL,FILL
};
};