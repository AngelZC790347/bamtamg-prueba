//
//  rect.hpp
//  GeometryFunctions
//
//  Created by Angel Zuñiga on 27/04/24.
//

#ifndef rect_hpp
#define rect_hpp

#include <stdio.h>
struct Rect {
    float x{0},y{0},
    width{0},heigth{0};
    bool overlap(const Rect& other);
    
};


#endif /* rect_hpp */
