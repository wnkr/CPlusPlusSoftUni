#pragma once
#include <vector>
#include "FigurePosition.h"

namespace ChessGame
{
	class ChessUtils
	{
	public:
		static const size_t LOWER_BOUND = 1;
		static const size_t UPPER_BOUND = 8;

		static bool checkPositionInBounds(const FigurePosition& position);
		static bool checkPositionInBounds(const std::vector<FigurePosition>& positions);
	};
}
