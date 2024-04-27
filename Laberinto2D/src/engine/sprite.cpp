#include <engine/texture.hpp>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <engine/sprite.hpp>
#include <GLUT/glut.h>
Sprite_t::Sprite_t(Texture_t texture):_texture(texture),_id(++NextId){
}
Sprite_t::Sprite_t(Texture_t texture,float width ,float heigth):
        _texture(texture),
        _WIDTH(width),
        _HEIGTH(heigth),
        _id(++NextId){
        }
Sprite_t::Sprite_t(Texture_t texture,float x ,float y ,float width ,float heigth):
        _texture(texture),
        _WIDTH(width),
        _HEIGTH(heigth),
        _X(x),
        _Y(y),
        _id(++NextId){
        }
void Sprite_t::draw(){
        // std::cout<<"window: "<<glutGet(GLUT_WINDOW_WIDTH)<<" "<<glutGet(GLUT_WINDOW_HEIGHT)<<std::endl;
        float width = ((float)_WIDTH/glutGet(GLUT_WINDOW_WIDTH))*2;
        float heigth = ((float)_HEIGTH/glutGet(GLUT_WINDOW_HEIGHT))*2;
        float resX = (float)glutGet(GLUT_WINDOW_WIDTH)/2;        
        float resY = (float)glutGet(GLUT_WINDOW_HEIGHT)/2;
        // std::cout<<"Resol: "<<resX<<" "<<resY<<std::endl;
        float x = (float)(_X-resX)/resX;
        float y = (float)(_Y-resY)/resY;
        // std::cout<<"************************"<<std::endl;
        // std::cout<<"Sprite: "<<_id<<std::endl;
        // std::cout<<"Size Sprite: "<<width<<" "<<heigth<<std::endl;
        // std::cout<<"Size Pos: "<<x<<" "<<y<<std::endl;
        // std::cout<<"************************"<<std::endl<<std::endl;
        glBindTexture(GL_TEXTURE_2D, _texture.getId());
        glBegin(GL_QUADS);
                glTexCoord2f(0.0f, 1.0f); glVertex2f(x,y); 
                glTexCoord2f(1.0f, 1.0f); glVertex2f(x+width,y);  
                glTexCoord2f(1.0f, 0.0f); glVertex2f(x+width, y+heigth);   
                glTexCoord2f(0.0f, 0.0f); glVertex2f(x,y+heigth);
        glEnd();
}