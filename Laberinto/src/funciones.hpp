#pragma  once
#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>
#ifndef RandomValue
#define RandomValue(a,b)  (rand() % (b - a + 1) + a)
#endif
#ifndef isWall
#define isWall(i,n) (i<n || i%n==0 || i>(n*n)-n||(i+1)%n==0)
#endif
enum DIRECTIONS{UP,DOWN,RIGHT,LEFT};
bool is_passage(char laberinto[],uint32_t dim,uint32_t n);
uint32_t get_RamdonValue(char laberinto[],uint32_t dim,uint32_t n);
std::vector<uint32_t> generate_new_road(char laberinto[],uint32_t dim,uint32_t current);
void createMaze2D(std::uint32_t n);