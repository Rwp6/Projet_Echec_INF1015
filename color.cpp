#include "color.hpp"

Color operator!(Color color) {
	if (color == Color::Black)
		return Color::White;
	else
		return Color::Black;
}