/**
* Impl�mentation de la enum-class Color cr�e dans color.hpp
* \file   color.cpp
* \author Rayan Asma et Rosalie Lamoureux
* \date   3 mars 2024
* Cree le 8 avril 2024
*/

#include "color.hpp"

Color operator!(Color color) {
	return color == Color::Black ? Color::White : Color::Black;
}