// AppReto.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <unordered_map>

#include "Capitulo.h"
#include "Serie.h"
#include "Pelicula.h"


void cargarSeries(std::vector<Serie>& series); // se pasa apuntador de vector de series, lee los archivos de las series.
void getVideos(std::vector<Video*>& videos, std::vector<Pelicula>& peliculas, std::vector<Serie>& series); // Pone todos los videos en un vector.
std::vector<Pelicula> readPeliculasCSV();
std::vector<Serie> readSeriesCSV();

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

			//cargarPeliculas(peliculas);
			peliculas = readPeliculasCSV();

			for (int i = 0; i < peliculas.size(); i++) {
				//Se suma 1 a i por claridad, lista para vista de usuario debe de empezar en 1
				std::cout << "\t" << i + 1 << ". " << peliculas[i].getNombre() << "\tGenero:" << peliculas[i].getGenero() << "\tCalificacion: " << peliculas[i].getCalificacion() << std::endl;
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

			series = readSeriesCSV();

			for (int i = 0; i < series.size(); i++) {
				//Se suma 1 a i por claridad, lista para vista de usuario debe de empezar en 1
				std::cout << "\t" << i + 1 << ". " << series[i].getNombre() << "\tGenero:" << series[i].getGenero() << "\tCalificacion: " << series[i].getCalificacion() << std::endl;
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
			peliculas = readPeliculasCSV();
			series = readSeriesCSV();
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
			videos[menu3_1 - 1]->calificar();
		}
		else if (menu1 == 4) {
			loop = false;
		}
	}
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

std::vector<Pelicula> readPeliculasCSV() {
	std::string archivo = "Peliculas.csv";
	std::vector<Pelicula> peliculas;
	std::ifstream file(archivo);

	if (!file.is_open()) {
		std::cerr << "Error opening file: " << archivo << std::endl;
		return peliculas;
	}

	std::string line, word;
	// Se salta la primera linea
	std::getline(file, line);

	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string id, nombre, genero;
		int duracion, numCalifs;
		float calificacion;

		std::getline(ss, id, ',');
		std::getline(ss, nombre, ',');
		std::getline(ss, word, ',');
		duracion = std::stoi(word);
		std::getline(ss, genero, ',');
		std::getline(ss, word, ',');
		calificacion = std::stof(word);
		std::getline(ss, word, ',');
		numCalifs = std::stoi(word);

		peliculas.emplace_back(id, nombre, duracion, genero, calificacion, numCalifs);
	}

	file.close();
	return peliculas;
}

std::vector<Serie> readSeriesCSV() {
	std::string archivo = "Series.csv";
	std::vector<Serie> series;
	std::ifstream file(archivo);

	if (!file.is_open()) { //lanza error si el archivo no abre
		std::cerr << "Error opening file: " << archivo << std::endl;
		return series;
	}

	std::string line;
	// salta titulos
	std::getline(file, line);

	// Mapa temporal para guardar los episodios
	std::unordered_map<std::string, Serie*> seriesMap;

	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string tipo, id, nombre, genero, word;
		int duracion = 0, numCalifs = 0;
		float calificacion = 0.0;

		std::getline(ss, tipo, ',');
		std::getline(ss, id, ',');
		std::getline(ss, nombre, ',');
		std::getline(ss, genero, ',');

		if (tipo == "serie") {
			// Crea una nueva serie
			std::vector<Capitulo> capitulos;
			Serie serie(id, nombre, genero, capitulos);
			series.push_back(serie);
			seriesMap[id] = &series.back();

		}
		else if (tipo == "capitulo") {
			// lee los datos de un capitulo
			std::getline(ss, word, ',');
			duracion = std::stoi(word);
			std::getline(ss, word, ',');
			calificacion = std::stof(word);
			std::getline(ss, word, ',');
			numCalifs = std::stoi(word);

			// Create a new episode and add it to the corresponding series
			Capitulo episodio(id, nombre, duracion, calificacion, numCalifs);
			std::string serieId = id.substr(0, id.find_last_of('.')); // Encuentra el id de la serie
			if (seriesMap.find(serieId) != seriesMap.end()) {
				seriesMap[serieId]->getCapitulosVector().push_back(episodio);
			}
		}
	}

	file.close();
	return series;
}
