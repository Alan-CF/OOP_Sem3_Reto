// AppReto.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Capitulo.h"
#include "Serie.h"
#include "Pelicula.h"

void cargarPeliculas(std::vector<Pelicula>& peliculas); // se pasa apuntador de vector de peliculas, lee los archivos de las peliculas.
void cargarSeries(std::vector<Serie>& series); // se pasa apuntador de vector de series, lee los archivos de las series.
void getVideos(std::vector<Video*>& videos, std::vector<Pelicula>& peliculas, std::vector<Serie>& series); // Pone todos los videos en un vector.

int main()
{
	bool loop = true;
	while (loop == true) {

		//Input seguro menu 1
		int menu1;
		bool validInput1 = false;
		do {
			std::cout << "Plataforma de Streaming" << std::endl;
			std::cout << "\t1. Ver Pelicula" << std::endl;
			std::cout << "\t2. Ver Serie" << std::endl;
			std::cout << "\t3. Ver Video" << std::endl;
			std::cout << "\t4. Salir" << std::endl;
			std::cout << "Selecion: ";
			std::cin >> menu1;

			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "caracter invalido.\n" << std::endl;
			}
			else if (menu1 != 1 && menu1 != 2 && menu1 != 3 && menu1 != 4) {
				std::cout << "Opcion invalida.\n" << std::endl;
			}
			else {
				validInput1 = true;
			}
		} while (!validInput1);

		std::vector<Pelicula> peliculas;
		std::vector<Serie> series;

		if (menu1 == 1) {

			cargarPeliculas(peliculas);

			for (int i = 0; i < peliculas.size(); i++) {
				//Se suma 1 a i por claridad, lista para vista de usuario debe de empezar en 1
				std::cout << "\t" << i + 1 << ". " << peliculas[i].getNombre() << "\tCalificacion: " << peliculas[i].getCalificacion() << std::endl;
			}

			//Input seguro menu 1.2
			int menu1_2;
			bool validInput1_2 = false;
			do {
				std::cout << "Que opcion deseas reproducir?" << std::endl << "Selecion: ";
				std::cin >> menu1_2;

				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "caracter invalido.\n" << std::endl;
				}
				else if (menu1_2 < 1 || menu1_2 > peliculas.size()) {
					std::cout << "Opcion invalida.\n" << std::endl;
				}
				else {
					validInput1_2 = true;
				}
			} while (!validInput1_2);

			peliculas[menu1_2 - 1].reproducir();
			peliculas[menu1_2 - 1].calificar();

		}
		else if (menu1 == 2) {

			cargarSeries(series);

			for (int i = 0; i < series.size(); i++) {
				//Se suma 1 a i por claridad, lista para vista de usuario debe de empezar en 1
				std::cout << "\t" << i + 1 << ". " << series[i].getNombre() << "\tCalificacion: " << series[i].getCalificacion() << std::endl;
			}

			//Input seguro menu 1.2
			int menu2_2;
			bool validInput2_2 = false;
			do {
				std::cout << "Que opcion deseas reproducir?" << std::endl << "Selecion: ";
				std::cin >> menu2_2;

				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "caracter invalido.\n" << std::endl;
				}
				else if (menu2_2 < 1 || menu2_2 > series.size()) {
					std::cout << "Opcion invalida.\n" << std::endl;
				}
				else {
					validInput2_2 = true;
				}
			} while (!validInput2_2);

			for (int i = 0; i < series[menu2_2 - 1].getCapitulosVector().size(); i++)
			{
				series[menu2_2 - 1].getCapitulosVector()[i].reproducir();
				series[menu2_2 - 1].getCapitulosVector()[i].calificar();
			}
		}
		else if (menu1 == 3) {
			cargarPeliculas(peliculas);
			cargarSeries(series);
			std::vector<Video*> videos;
			getVideos(videos, peliculas, series);

			for (int i = 0; i < videos.size(); i++) {
				//Se suma 1 a i por claridad, lista para vista de usuario debe de empezar en 1
				std::cout << "\t" << i + 1 << ". " << videos[i]->getNombre() << "\tCalificacion: " << videos[i]->getCalificacion() << std::endl;
			}

			//Input seguro menu 3.1
			int menu3_1;
			bool validInput3_1 = false;
			do {
				std::cout << "Que opcion deseas reproducir?" << std::endl << "Selecion: ";
				std::cin >> menu3_1;

				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "caracter invalido.\n" << std::endl;
				}
				else if (menu3_1 < 1 || menu3_1 > videos.size()) {
					std::cout << "Opcion invalida.\n" << std::endl;
				}
				else {
					validInput3_1 = true;
				}
			} while (!validInput3_1);
			videos[menu3_1 - 1]->reproducir();
		}
		else if (menu1 == 4) {
			loop = false;
		}
	}
}

void cargarPeliculas(std::vector<Pelicula>& peliculas) {
	// Futura implementacion leerá archivos
	peliculas.push_back(Pelicula("1", "Coraline", 120, "Suspenso", 9.5, 3));
	peliculas.push_back(Pelicula("2", "Baby Driver", 160, "Accion", 8.1, 9));
}

void cargarSeries(std::vector<Serie>& series) {
	// Futura implementacion leerá archivos
	std::vector<Capitulo> BreakingBad;
	BreakingBad.push_back(Capitulo("3.1", "Better call Saul", 50, 9.2, 2));
	BreakingBad.push_back(Capitulo("3.2", "Fly", 55, 3.2, 4));
	series.push_back(Serie("3", "Breaking Bad", "Drama", BreakingBad));

	std::vector<Capitulo> RickAndMorty;
	RickAndMorty.push_back(Capitulo("3.3", "Get Schwifty", 50, 6.6, 11));
	RickAndMorty.push_back(Capitulo("3.4", "Pickle Rick", 52, 9.2, 19));
	series.push_back(Serie("4", "Rick and Morty", "Drama", RickAndMorty));
}

//El peak de mi carrera
void getVideos(std::vector<Video*>& videos, std::vector<Pelicula>& peliculas, std::vector<Serie>& series)
{
	for (auto& pelicula : peliculas) {
		videos.push_back(&pelicula);
	}

	for (auto& serie : series) {
		for (auto& capitulo : serie.getCapitulosVector()) {
			videos.push_back(&capitulo);
		}
	}
}