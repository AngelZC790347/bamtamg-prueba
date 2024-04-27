#include <cstdlib>
#include<iostream>
#include <main.hpp>
using namespace std;

int main(int argc,char ** argv){
	srand ( time(NULL) );
	createMaze2D((rand()%20+6));
	return 0;
}