#pragma once
#include <engine/texture.hpp>
#include <cstdint>
#include <GLUT/glut.h>
struct Sprite_t{
    explicit Sprite_t():_id(++NextId){}
    explicit Sprite_t(Texture_t texture);
    explicit Sprite_t(Texture_t texture,float width ,float heigth);
    explicit Sprite_t(Texture_t texture,float x ,float y ,float width ,float heigth);
    const uint32_t getId() const{
        return _id;
    }
    uint32_t getId(){
        return _id;
    }
    virtual void draw();
    float getX() const{
        return _X;
    }
    float getY() const{
        return _Y;
    }
    float getWidth() const{
        return _WIDTH;
    }
    float getHeigth() const{
        return _HEIGTH;
    }
protected:
    Texture_t _texture{};
    float _X{0};
    float _Y{0};
    float _WIDTH{0};
    float _HEIGTH{0};
    inline static uint32_t NextId = 0;
    uint32_t _id{NextId};
};