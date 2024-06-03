#pragma once
#include "Video.h"
class Capitulo :
    public Video
{
private:

public:
    Capitulo(std::string _id, std::string _nombre, int _duracion);
    
    void reproducir();
    void calificar();

};