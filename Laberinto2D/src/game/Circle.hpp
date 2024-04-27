#include "engine/movable.hpp"
#include "engine/texture.hpp"
#include <engine/sprite.hpp>
struct Circle:public Sprite_t ,public Movable_t{
    Circle(float x,float y ,float width ,float heigth):Sprite_t(Circle::getTextureFromFile(),x,y,width,heigth){}
    static Texture_t getTextureFromFile();
    virtual void handleKeyboard(unsigned char keyboard) override;
    virtual void draw() override;
};