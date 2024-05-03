/**
* Enum-class Color qui définie si une pièce/case est de couleur Noir ou Blanche
* \file   color.hpp
* \author Rayan Asma et Rosalie Lamoureux
* \date   3 mai 2024
* Cree le 8 avril 2024
*/

#ifndef COLOR_HPP
#define COLOR_HPP

enum class Color {
	White,
	Black
};

Color operator!(Color color);

#endif