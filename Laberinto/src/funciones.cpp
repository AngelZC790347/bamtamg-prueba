#include <algorithm>
#include <cstdint>
#include <funciones.hpp>
#include <iostream>
#include <ostream>
#include <vector>
#include <unistd.h>
std::vector<std::uint32_t> encontrarVectorMasGrande(const std::vector<std::vector<std::uint32_t>>& vectorDeVectores) {
    // Verificar si el vector de vectores está vacío
    // std::cout<<vectorDeVectores.size()<<std::endl;
    if (vectorDeVectores.empty()) {
        // Si está vacío, devolver un vector vacío
        return std::vector<std::uint32_t>();
    }

    // Inicializar el vector más grande con el primer vector del vector de vectores
    std::vector<std::uint32_t> vectorMasGrande = vectorDeVectores[0];

    // Iterar sobre los vectores restantes para encontrar el más grande
    for (const auto& vec : vectorDeVectores) {
        if (vec.size() > vectorMasGrande.size()) {
            vectorMasGrande = vec;
        }
    }
    // std::cout<<vectorMasGrande.size()<<std::endl;
    return vectorMasGrande;
}
bool is_passage(char laberinto[],uint32_t dim,uint32_t n){
    uint32_t numberOfVisitedN = 0;
    if (laberinto[n+dim] != '*')
    {
        numberOfVisitedN ++;
    }
    if (laberinto[n-dim] != '*')
    {
        numberOfVisitedN ++;
    }
    if (laberinto[n-1] != '*')
    {
        numberOfVisitedN ++;
    }
    if (laberinto[n+1] != '*')
    {
        numberOfVisitedN ++;
    }
    return numberOfVisitedN>1;
}
uint32_t get_RamdonValue(char laberinto[],uint32_t dim,uint32_t n){
    std::vector<uint32_t>aviable(4,n);
    for (int i = 0; i < 4; ++i)
    {
        uint32_t next;
        switch (i) {
            case DIRECTIONS::UP:
                next = n-dim;
                break;
            case DIRECTIONS::DOWN:
                next = n+dim; 
                break;
            case DIRECTIONS::LEFT:
                next = n-1;
                break;
            case DIRECTIONS::RIGHT:
                next = n+1;
                break;
        }
        if (laberinto[next]=='*' && !isWall(next, dim) && !is_passage(laberinto,dim,next))
        {
            aviable[i]=next;
        }
    }
    auto it = aviable.begin();
    do{
        it = std::find(aviable.begin(),aviable.end(),n);
        if (*it == n)
        {
            aviable.erase(it);
        }
    }while(it != aviable.end());
    // for (uint32_t i = 0; i <aviable.size(); ++i)
    // {
    //     std::cout<<aviable[i];
    // }
    // std::cout<<std::endl;
    // std::cout<<"size: "<<aviable.size()<<std::endl;
    if (aviable.size()==0)
    {
        return n;
    }
    return aviable[RandomValue(0, aviable.size()-1)];
}
std::vector<uint32_t> generate_new_road(char laberinto[],uint32_t dim,uint32_t current){
    std::vector<uint32_t> road;
    road.reserve(dim*dim);
    srand ( time(NULL) );
    uint32_t curr = current;
    uint32_t next = curr;
    bool terminado=false;
    while(!terminado){        
        next = get_RamdonValue(laberinto,dim,curr);
        // std::cout<<"next: "<<next<<std::endl;
        // std::cout<<"curr: "<<curr<<std::endl;
        if (next==curr || next == current)
        {
            terminado = true;
            // break;
        }
        road.push_back(next);
        laberinto[next]=' ';
        curr = next;
    }
    return  std::vector<uint32_t>(road.begin(),road.begin()+(road.size()-1));
}
void createMaze2D(std::uint32_t n){
    std::vector<std::vector<uint32_t>>roads{};
    roads.reserve((n*n)/3);
    char laberinto[n*n];
    // std::cout<<"Dimension: "<<n<<std::endl;
    for(uint32_t i=0;i<n*n;++i){
        laberinto[i]='*';
    } 
    uint32_t base = n+1;
    uint32_t attemps = 0;
    uint32_t umbral = 100;
    std::vector<uint32_t> vectorMasGrande{};
    while (umbral > attemps) {
        auto newRoad = generate_new_road(laberinto, n, base);        
        if (newRoad.size() == 0)
        {
            // std::cout<<"Esta vacio"<<std::endl;
            // std::cout<<"TERMINADO"<<std::endl;
            vectorMasGrande = encontrarVectorMasGrande(roads);
            if (base==n+1)
            {
                base = *(vectorMasGrande.begin()+1);
            }else{
                auto it = std::find(vectorMasGrande.begin(), vectorMasGrande.end(),base);
                if (it == vectorMasGrande.end()-1)
                {
                    break;
                }
                base =*(it+1);
            }
            // std::cout<<"base: "<<base<<std::endl;
            // continue;
        }
        newRoad.insert(newRoad.begin(),vectorMasGrande.begin(),vectorMasGrande.end());
        // for (uint32_t i = 0; i <newRoad.size(); ++i)
        // {
        //     std::cout<<newRoad[i]<<" ";
        // }
        // std::cout<<std::endl;
        // std::cout<<roads.size()<<std::endl;
        if (roads.size()>0)
        {
            auto it = std::find_if(roads.begin(), roads.end(), [&newRoad](auto& r){
                return r.size() == newRoad.size() && std::equal(r.begin(), r.end(), newRoad.begin());
            });
            if (it != roads.end())
            {
                attemps++;
                continue;
            }
        }
        roads.push_back(newRoad);
    }
   laberinto[n+1]='A';
   laberinto[vectorMasGrande.back()] = 'B';
    for (uint32_t i = 0; i < n*n; ++i)
    {
        std::cout<<laberinto[i];
        if ((i+1)%n==0)
        {
            std::cout<<std::endl;
        }
    }  
    
}