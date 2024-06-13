#include "Pelicula.h"
#include <iostream>

Pelicula::Pelicula(std::string _id, std::string _nombre, int _duracion, std::string _genero, float _calificacion, int _numCalifs) : Video(_id, _nombre, _duracion, _calificacion, _numCalifs)
{
	genero = _genero;
}

void Pelicula::reproducir()
{
	std::cout << "Reproduciendo pelicula:\t" << nombre << std::endl;
}

void Pelicula::calificar()
{
	float _calificacion;

	std::cout << "Que te parecio la pelicula? Califica del 1 al 10." << std::endl;
	std::cin >> _calificacion;

	calificacion = (calificacion * numCalifs + _calificacion) / (numCalifs + 1);
	numCalifs++;
}

std::string Pelicula::getGenero() {return genero;}


