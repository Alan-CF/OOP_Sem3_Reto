#pragma once
#include "Video.h"
class Pelicula :
    public Video
{
private:
    std::string genero;

public:
    Pelicula(std::string _id, std::string _nombre, int _duracion, std::string _genero, float _calificacion, int _numCalifs);

    void reproducir();
    void calificar();

    std::string getGenero();
};

