#pragma once
#include <vector>
#include "Figure.h"

namespace ChessGame
{
	class Rook : public Figure
	{
	private:
		static const char ROOK_SYMBOL = '@';
	public:
		Rook(FigureColor color, FigurePosition position);

		std::vector<FigurePosition> getAvailableMoves(const std::vector<Figure*>& otherFigures);


	};
}

