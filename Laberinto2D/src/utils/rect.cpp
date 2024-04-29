//
//  rect.cpp
//  GeometryFunctions
//
//  Created by Angel Zuñiga on 27/04/24.
//

#include "rect.hpp"
#include <iostream>
#include <ostream>

bool Rect::overlap(const Rect &other){
    if (y == other.y && y+heigth == other.y+other.heigth && x< other.x+other.width && x + width > other.x) {
        std::cout<<"x1 , x2: "<<x<<" "<<other.x<<std::endl;
        return true;
    }
    if (x == other.x && x+width == other.x+other.width && y< other.y+other.heigth && y + heigth > other.y) {
        std::cout<<"y1 , y2: "<<y<<" "<<other.y<<std::endl;
        return true;
    }
    if ( x < other.x+other.width && x+width > other.x && y < other.y+other.heigth && y+heigth >other.y) {
        std::cout<<"x1 , x2: "<<x<<" "<<other.x<<std::endl;
        std::cout<<"y1 , y2: "<<y<<" "<<other.y<<std::endl;
        return true;
    }
    return false;
}
