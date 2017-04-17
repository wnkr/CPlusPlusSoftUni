#pragma once
#include "Figure.h"

namespace ChessGame
{
	class Pawn : public Figure
	{
	private:
		static const char PAWN_SYMBOL = 'o';
	public:
		Pawn(FigureColor color, FigurePosition position);

		std::vector<FigurePosition> getAvailableMoves(const std::vector<Figure*>& otherFigures);
	};
}