#pragma once
#include <ostream>

namespace ChessGame
{
	class FigurePosition
	{
	private:
		size_t row;
		size_t col;
		
	public:
		FigurePosition(size_t row, size_t col);

		size_t getRow() const;
		void setRow(int row);

		size_t getCol() const;
		void setCol(int col);

		bool operator==(const FigurePosition& other);
		bool operator!=(const FigurePosition& other);

		friend std::ostream& operator<<(std::ostream& stream, const FigurePosition& position);

	private:
		static void checkCorrectRowCol(int row);
	};
}
