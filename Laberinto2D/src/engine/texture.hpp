#pragma once
#include <cstdint>
struct Texture_t{
    explicit Texture_t() = default;
    explicit Texture_t(const uint32_t *data,const uint32_t width,const uint32_t heigth);
    explicit Texture_t(unsigned char *data,const uint32_t width,const uint32_t heigth);
    const  uint32_t * getData(){
        return _data;
    };
    const uint32_t getId(){
        return textureId;
    }
private:
    uint32_t textureId{0};
    const uint32_t * _data{nullptr};
    const uint32_t _heigth{};
    const uint32_t _width{};
};