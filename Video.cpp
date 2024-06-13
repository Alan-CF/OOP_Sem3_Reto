#include "Video.h"

Video::Video(std::string _id, std::string _nombre, int _duracion, float _calificacion, int _numCalifs)
{
	id = _id;
	nombre = _nombre;
	duracion = _duracion;
	numCalifs = _numCalifs;
	calificacion = _calificacion;
}

void Video::reproducir()
{
	std::cout << "Reproduciendo video:\t" << nombre << std::endl;
}

std::string Video::getId() {return id;}
std::string Video::getNombre() {return nombre;}
int Video::getDuracion() {return duracion;}
float Video::getCalificacion() {return calificacion;}