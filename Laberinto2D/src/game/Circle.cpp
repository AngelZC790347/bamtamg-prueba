#include "game/Letter.hpp"
#include <GLUT/GLUT.h>
#include <algorithm>
#include <engine/render.hpp>
#include <utils/filter.hpp>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <engine/sprite.hpp>
#include <engine/texture.hpp>
#include <fstream>
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
#include <ostream>
#include <picoPNG/picopng.hpp>
#include <game/Circle.hpp>
#include <vector>
#include <cmath>
#include <utils/rect.hpp>
#define STB_IMAGE_IMPLEMENTATION
#include <utils/stb_image.h>
Texture_t Circle::getTextureFromFile(){
    std::vector<unsigned char>pixels{};
    int dw{} , dh{},chanels{};
    const char* fileName ="/Users/angelzuniga/Documents/bamtamg-prueba/Laberinto2D/assets/circulo2.jpeg";
    unsigned char* textureData = stbi_load(fileName, &dw, &dh, &chanels, STBI_rgb_alpha);
    return Texture_t{
        textureData,
        (uint32_t)dw,
        (uint32_t)dh
    };
}

void Circle::draw(){
    float width = ((float)_WIDTH/glutGet(GLUT_WINDOW_WIDTH))*2;
    float heigth = ((float)_HEIGTH/glutGet(GLUT_WINDOW_HEIGHT))*2;
    float resX = (float)glutGet(GLUT_WINDOW_WIDTH)/2;        
    float resY = (float)glutGet(GLUT_WINDOW_HEIGHT)/2;
    int numSegments = 50;
    float radius = std::min(width,heigth) * 0.5f;
    float cx = ((float)(_X-resX)/resX)+(width/2);
    float cy = ((float)(_Y-resY)/resY)+(heigth/2);
    glBindTexture(GL_TEXTURE_2D, _texture.getId());
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0.5f, 0.5f);
        glVertex2f(cx, cy);
        for (int i = 0; i <= numSegments; ++i) {
            float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
            float x = radius * cosf(theta);
            float y = radius * sinf(theta);
            glTexCoord2f(0.5f * (x / radius + 1), 0.5f * (y / radius + 1));
            glVertex2f(cx + x, cy + y);
        }
    glEnd();
    glEnd();   
}

void Circle::handleKeyboard(unsigned char keyboard){
    float step = 10;
    bool cantMoveUp=false,cantMoveDown=false,cantMoveLeft=false,cantMoveRight=false;
    auto sprites = RenderSystem::Shared().getSprites();
    auto spritesWithOuthPlayers = filter(sprites, [](auto sprite){
        return (typeid(*sprite) != typeid(Letter_A_t) && typeid(*sprite) != typeid(Letter_B_t) && typeid(*sprite) != typeid(Circle));
    });
    std::cout<<std::endl<<"Player "<<_id<<std::endl;
    std::cout<<"X,Y: "<<getX()<<" ,"<<getY()<<std::endl;
    std::cout<<"W,H: "<<getWidth()<<" ,"<<getHeigth()<<std::endl<<std::endl;
    for (auto sp : spritesWithOuthPlayers) {
        if (sp->getId() == _id)
        {
            std::cout<<"No funciona"<<std::endl;
        }
    }
    std::cout<<"Left"<<std::endl;
    cantMoveLeft =  std::none_of(spritesWithOuthPlayers.begin(), spritesWithOuthPlayers.end(), [&](Sprite_t* sp){
        return Rect{sp->getX(),sp->getY(),sp->getWidth(),sp->getHeigth()}.overlap(Rect{_X-step,_Y,_WIDTH,_HEIGTH});
    });
    std::cout<<"Up"<<std::endl;
    cantMoveUp =  std::none_of(spritesWithOuthPlayers.begin(), spritesWithOuthPlayers.end(), [&](Sprite_t* sp){
        return Rect{sp->getX(),sp->getY(),sp->getWidth(),sp->getHeigth()}.overlap(Rect{_X,_Y+step,_WIDTH,_HEIGTH});        
    });
    std::cout<<"Right"<<std::endl;
    cantMoveRight =  std::none_of(spritesWithOuthPlayers.begin(), spritesWithOuthPlayers.end(), [&](Sprite_t* sp){
        return Rect{sp->getX(),sp->getY(),sp->getWidth(),sp->getHeigth()}.overlap(Rect{_X+step,_Y,_WIDTH,_HEIGTH});
    });
    std::cout<<"Down"<<std::endl;
    cantMoveDown =  std::none_of(spritesWithOuthPlayers.begin(), spritesWithOuthPlayers.end(), [&](Sprite_t* sp){
        return Rect{sp->getX(),sp->getY(),sp->getWidth(),sp->getHeigth()}.overlap(Rect{_X,_Y-step,_WIDTH,_HEIGTH});        
    });
    switch (keyboard) {
        case 'w':
            if (cantMoveUp)
                _Y +=step;
            break;
        case 's':
            if (cantMoveDown)            
                _Y -=step;            
            break;
        case 'a':
            if(cantMoveLeft)
                _X -=step;
            break;
        case 'd':
            if(cantMoveRight)
                _X +=step;
            break;
    }
    glutPostRedisplay();
}
