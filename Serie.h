#pragma once
#include <string>
#include <vector>
#include "Capitulo.h"
class Serie
{
private:
    std::string id;
    std::string nombre;
    std::string genero;
    std::vector<Capitulo> capitulos;
    float calificacion;
    int numCalifs;

public:
    Serie(std::string _id, std::string _nombre, std::string _genero, std::vector<Capitulo>& _capitulos);

    void reproducir();

    std::string getId();
    std::string getNombre();
    int getDuracion();
    std::string getGenero();
    float getCalificacion();
    std::vector<Capitulo>& getCapitulosVector();
};