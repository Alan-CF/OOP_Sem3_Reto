#include "Serie.h"
#include <iostream>


Serie::Serie(std::string _id, std::string _nombre, std::string _genero, std::vector<Capitulo>& _capitulos)
{
	id = _id;
	nombre = _nombre;
	genero = _genero;
	capitulos = _capitulos;
	numCalifs = 0;
	calificacion = 0;
}

void Serie::reproducir()
{
	std::cout << "Reproduciendo Serie:\t" << nombre << std::endl;
	for (int i = 0; i < capitulos.size(); i++)
	{
		std::cout << "\t";
		capitulos[i].reproducir();
	}
}

std::string Serie::getId() {return id;}
std::string Serie::getNombre() {return nombre;}
std::string Serie::getGenero() { return genero; }

int Serie::getDuracion()
{
	float sum = 0;
	for (int i = 0; i < capitulos.size(); i++)
	{
		sum = sum + capitulos[i].getDuracion();
	}
	return sum;
}

float Serie::getCalificacion()
{
	int it;
	float sum = 0;
	for (it = 0; it < capitulos.size(); it++)
	{
		sum = sum + capitulos[it].getCalificacion();
	}
	return sum / it;
}

std::vector<Capitulo>& Serie::getCapitulosVector()
{
	return capitulos;
}
