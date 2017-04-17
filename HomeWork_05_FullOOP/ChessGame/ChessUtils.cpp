#include "ChessUtils.h"

namespace ChessGame
{
	bool ChessUtils::checkPositionInBounds(const FigurePosition& position)
	{
		size_t row = position.getRow();
		size_t col = position.getCol();

		bool inBounds = row >= LOWER_BOUND && row <= UPPER_BOUND && col >= LOWER_BOUND && col <= UPPER_BOUND;
		
		return inBounds;
	}

	bool ChessUtils::checkPositionInBounds(const std::vector<FigurePosition>& positions)
	{
		for (const auto& position : positions)
		{
			if (!checkPositionInBounds(position))
			{
				return false;
			}
		}

		return true;
	}

}
