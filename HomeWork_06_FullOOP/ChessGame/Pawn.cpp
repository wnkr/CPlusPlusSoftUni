#include "Pawn.h"
#include "ChessUtils.h"

namespace ChessGame
{
	Pawn::Pawn(FigureColor color, FigurePosition position)
		: Figure(PAWN_SYMBOL, color, position)
	{
	}

	std::vector<FigurePosition> Pawn::getAvailableMoves(const std::vector<Figure*> &otherFigures)
	{
		size_t figureRow = this->getPosition().getRow();
		size_t figureCol = this->getPosition().getCol();

		std::vector<FigurePosition> availablePositions;

		FigurePosition aheadPosition(figureRow + 1, figureCol);

		if (figureRow != 2)
		{
			if (checkEmptyCell(aheadPosition, otherFigures) && ChessUtils::checkPositionInBounds(aheadPosition))
			{
				availablePositions.push_back(aheadPosition);
			}
		}
		else
		{
			FigurePosition aheadDoblePosition(figureRow + 2, figureCol);
			if (checkEmptyCell(aheadPosition, otherFigures)
				&& checkEmptyCell(aheadDoblePosition, otherFigures)
				&& ChessUtils::checkPositionInBounds(std::vector<FigurePosition>{aheadPosition, aheadDoblePosition}))
			{
				availablePositions.push_back(aheadPosition);
				availablePositions.push_back(aheadDoblePosition);
			}
		}

		FigurePosition leftUpperPosition(figureRow - 1, figureCol + 1);
		if (checkTakenOppositeColorCell(leftUpperPosition, otherFigures) && ChessUtils::checkPositionInBounds(leftUpperPosition))
		{
			availablePositions.push_back(leftUpperPosition);
		}

		FigurePosition rightUpperPosition(figureRow + 1, figureCol + 1);
		if (checkTakenOppositeColorCell(rightUpperPosition, otherFigures) && ChessUtils::checkPositionInBounds(rightUpperPosition))
		{
			availablePositions.push_back(rightUpperPosition);
		}

		return availablePositions;
	}

}

