#include <engine/input.hpp>
#include <cstring>
#include <game/Cell.hpp>
#include <game/Letter.hpp>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <engine/texture.hpp>
#include <engine/render.hpp>
#include<iostream>
#include <ostream>
#include<vector>
#include<GLUT/glut.h>
#include<OpenGL/OpenGL.h>
#include <game/Circle.hpp>

using namespace std;
void renderScene() {
    RenderSystem::Shared().update();
    glRasterPos2f(-0.5f, 0.0f);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'A');
}
void handleInput(unsigned char key, int x, int y){
    // std::cout<<"PResinado "<<key<<std::endl;
    InputSystem::Shared().update(key);
    glutPostRedisplay();
}
void init(){        
    char* labFile = "/Users/angelzuniga/Documents/bamtamg-prueba/Laberinto2D/output.txt";
    ifstream mapData(labFile);
    if (!mapData.is_open())
    {        
        cerr<<"Fail to pen file";
        exit(EXIT_FAILURE);
    }
    string line;
    vector<vector<bool>> map{};
    uint32_t mapDimensions = 0;
    uint32_t posXB = 0;
    uint32_t posYB = 0;
    uint32_t iB =0;
     while ( getline (mapData,line) )
    {
        if (mapDimensions == 0)
        {
            mapDimensions = line.size();
            map.reserve(mapDimensions); 

        }   
        for (int i = 0; i < line.size(); ++i)
        {
            if (line[i]=='B')
            {
                posXB = i;
                posYB = iB;
            }
        }
        vector<bool>cells;
        cells.resize(line.size());
        transform(line.begin(),line.end(),cells.begin(),[](char c){
            return ((c=='*')?true:false);
        });
        map.push_back(cells);
        iB++;
    }
    mapData.close();

    float cellHeigth = 50;
    float cellWidth = 50;
    struct{
        float width;
        float heigth;        
    }mapDim{cellWidth*mapDimensions,cellHeigth*mapDimensions};    
    float currentPosX = glutGet(GLUT_SCREEN_WIDTH)/2-(mapDim.width/2);
    float currentPosY = (glutGet(GLUT_SCREEN_HEIGHT) + mapDim.heigth)/2;
    for (auto cells: map) { 
        for (auto isBlock : cells) {
            if (isBlock)
            {
                RenderSystem::Shared().insertSprite(new Cell(currentPosX,currentPosY,cellWidth,cellHeigth));
            }
            currentPosX += cellWidth;
        }
        currentPosX = glutGet(GLUT_SCREEN_WIDTH)/2-(mapDim.width/2);
        currentPosY -= cellHeigth;
    }
    auto player = new Circle(currentPosX+cellWidth,((glutGet(GLUT_SCREEN_HEIGHT) + mapDim.heigth)/2)- cellHeigth,cellWidth,cellHeigth);
    RenderSystem::Shared().insertSprite(new Letter_B_t(currentPosX+(cellHeigth*posXB),((glutGet(GLUT_SCREEN_HEIGHT) + mapDim.heigth)/2)-(cellHeigth*posYB),cellWidth,cellHeigth));
    RenderSystem::Shared().insertSprite(new Letter_A_t(currentPosX+cellWidth,((glutGet(GLUT_SCREEN_HEIGHT) + mapDim.heigth)/2)- cellHeigth,cellWidth,cellHeigth));
    RenderSystem::Shared().insertSprite(player);
    InputSystem::Shared().insertSprite(player);
}
int main(int argc,char ** argv){
	glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow ("Laberinto 2D");
    // glutFullScreen();
    init();
    glutKeyboardFunc(handleInput);
	glutDisplayFunc(renderScene);
    glutMainLoop();
	return 0;
}
