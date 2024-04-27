#pragma once
#include <cstdint>
#include <vector>
#include <GLUT/glut.h>
#ifndef MAX_SPRITES
#define MAX_SPRITES 200
#endif
struct Sprite_t;
using  Sprites_Vect_t = std::vector<Sprite_t*>;
struct RenderSystem{
    RenderSystem(RenderSystem &other) = delete;
    void operator=(const RenderSystem &) = delete;
    static RenderSystem& Shared(){
        if (shared_ == nullptr)
        {
            shared_ = new RenderSystem();
        }
        return *shared_;
    }
    void update();
    Sprites_Vect_t getSprites();
    void insertSprite(Sprite_t* newSprite);
    const Sprites_Vect_t getSprites() const;
     ~RenderSystem();
private:
    explicit RenderSystem();
    inline static RenderSystem* shared_{nullptr};
    Sprites_Vect_t _sprites{};
};
// RenderSystem