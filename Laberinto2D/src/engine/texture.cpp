#include <engine/texture.hpp>
#include <GLUT/glut.h>
#include <utils/stb_image.h>
Texture_t::Texture_t(const uint32_t *data,const uint32_t width,const uint32_t heigth):_data(data),_width(width),_heigth(heigth){
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width,_heigth, 0, GL_RGBA, GL_UNSIGNED_BYTE, _data);
}

Texture_t::Texture_t(unsigned char *data,const uint32_t width,const uint32_t heigth):_width(width),_heigth(heigth){
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width,_heigth, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    stbi_image_free(data);
}