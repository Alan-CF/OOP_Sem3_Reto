#include "Capitulo.h"


Capitulo::Capitulo(std::string _id, std::string _nombre, int _duracion) : Video(_id, _nombre, _duracion) {}

void Capitulo::reproducir()
{
	std::cout << "Reproduciendo Capitulo:\t" << nombre << std::endl;
}

void Capitulo::calificar()
{
	float _calificacion;

	std::cout << "Que te parecio el Capitulo? Califica del 1 al 10." << std::endl;
	std::cin >> _calificacion;

	calificacion = (calificacion * numCalifs + _calificacion) / (numCalifs + 1);
	numCalifs++;
}
