#include "FigurePosition.h"

namespace ChessGame
{
	FigurePosition::FigurePosition(size_t row, size_t col)
		: row(row), col(col)
	{
	}

	size_t FigurePosition::getRow() const
	{
		return this->row;
	}

	void FigurePosition::setRow(int row)
	{
		checkCorrectRowCol(row);
		this->row = row;
	}

	size_t FigurePosition::getCol() const
	{
		return this->col;
	}

	void FigurePosition::setCol(int col)
	{
		checkCorrectRowCol(col);
		this->col = col;
	}

	bool FigurePosition::operator==(const FigurePosition & other)
	{
		bool equalRows = this->row == other.row;
		bool equalCols = this->col == other.col;

		return equalRows && equalCols;
	}

	bool FigurePosition::operator!=(const FigurePosition & other)
	{
		return !(*this == other);
	}

	void FigurePosition::checkCorrectRowCol(int row)
	{
		if (row < 0 || row > 8)
		{
			throw "row must be between 1 and 8.";
		}
	}
	std::ostream & operator<<(std::ostream & stream, const FigurePosition & position)
	{
		stream << "(" << (char)(position.col + 64) << position.row << ")";

		return stream;
	}
}

