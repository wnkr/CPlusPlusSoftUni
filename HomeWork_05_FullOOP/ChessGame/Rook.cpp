#include "Rook.h"

namespace ChessGame
{
	Rook::Rook(FigureColor color, FigurePosition position)
		: Figure(ROOK_SYMBOL, color, position)
	{
	}

	std::vector<FigurePosition> Rook::getAvailableMoves(const std::vector<Figure*>& otherFigures)
	{
		size_t figureRow = this->getPosition().getRow();
		size_t figureCol = this->getPosition().getCol();

		std::vector<FigurePosition> availablePositions;

		auto availableRowMoves = getAvailableRowMoves(otherFigures);
		availablePositions.insert(availablePositions.end(), availableRowMoves.begin(), availableRowMoves.end());
		auto availableColMoves = getAvailableColMoves(otherFigures);
		availablePositions.insert(availablePositions.end(), availableColMoves.begin(), availableColMoves.end());

		return availablePositions;
	}

}

