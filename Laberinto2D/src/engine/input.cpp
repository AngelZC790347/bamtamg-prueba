#include <engine/input.hpp>
#include <engine/movable.hpp>
InputSystem::InputSystem(){
    _movs.reserve(100);
}
void InputSystem::update(unsigned char key){
    for (auto movil : _movs) {
        movil->handleKeyboard(key);
    }
}
void InputSystem::insertSprite(Movable_t *newSprite){
    _movs.push_back(newSprite);
}