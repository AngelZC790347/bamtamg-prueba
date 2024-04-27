#pragma once
#include <vector>
// #include <engine/movable.hpp>
struct Movable_t;
using  Movable_Vect_t = std::vector<Movable_t*>;
struct InputSystem{
    InputSystem(InputSystem &other) = delete;
    void operator=(const InputSystem &) = delete;
    static InputSystem& Shared(){
        if (shared_ == nullptr)
        {
            shared_ = new InputSystem();
        }
        return *shared_;
    }
    void update(unsigned char key);
    Movable_Vect_t getSprites(){return _movs;}
    void insertSprite(Movable_t* newSprite);
    const Movable_Vect_t getSprites() const{
        return  _movs;
    }
    ~InputSystem();
private:
    explicit InputSystem();
    inline static InputSystem* shared_{nullptr};
    Movable_Vect_t _movs{};
};