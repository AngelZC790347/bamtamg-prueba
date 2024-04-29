// #include <iostream>
// #include <ostream>
// struct Rect {
//     float x, y;
//     float width, height;
// };

// bool overlap(const Rect& rect1, const Rect& rect2) {
//     // Calcular las coordenadas de los bordes de cada rectángulo
//     float left1 = rect1.x;
//     float right1 = rect1.x + rect1.width;
//     float top1 = rect1.y;
//     float bottom1 = rect1.y + rect1.height;

//     float left2 = rect2.x;
//     float right2 = rect2.x + rect2.width;
//     float top2 = rect2.y;
//     float bottom2 = rect2.y + rect2.height;
//     if (left1 < right2 && right1 > left2 && top1 < bottom2 && bottom1 > top2) {
//         std::cout<<"left1: "<<left1<<std::endl;
//         std::cout<<"left2: "<<left2<<std::endl;
//         std::cout<<"right1: "<<right1<<std::endl;
//         std::cout<<"right2: "<<right2<<std::endl;
//         std::cout<<"top1: "<<top1<<std::endl;
//         std::cout<<"top2: "<<top2<<std::endl;
//         std::cout<<"bottom1: "<<bottom1<<std::endl;
//         std::cout<<"bottom2: "<<bottom2<<std::endl<<std::endl;
//         // Los rectángulos se superponen
//         return true;
//     }
//     // No hay superposición
//     return false;
// }