#include <engine/sprite.hpp>
#include <cstdint>
#include <engine/render.hpp>
#include <GLUT/glut.h>
RenderSystem::RenderSystem(){
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    _sprites.reserve(MAX_SPRITES);
}
void RenderSystem::update(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_TEXTURE_2D);
    for (auto sprite : _sprites) {
        sprite->draw();    
    }
    glutSwapBuffers();
}
Sprites_Vect_t RenderSystem::getSprites(){
    return  _sprites;
}
const Sprites_Vect_t RenderSystem::getSprites() const{
    return  _sprites;
}
void RenderSystem::insertSprite(Sprite_t *newSprite){
    _sprites.push_back(newSprite);
}