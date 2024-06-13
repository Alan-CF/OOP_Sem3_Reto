#pragma once
#include <string>
#include <iostream>
class Video
{
protected:
    std::string id;
    std::string nombre;
    int duracion;
    float calificacion;
    int numCalifs;

public:
    Video(std::string _id, std::string _nombre, int _duracion, float calificacion, int numCalifs);

    virtual void reproducir();
    virtual void calificar() = 0;

    std::string getId();
    std::string getNombre();
    int getDuracion();
    float getCalificacion();

};

