#include "Figure.h"
#include "ChessUtils.h"

namespace ChessGame
{
	Figure::Figure(char symbol, FigureColor color, FigurePosition position)
		: symbol(symbol), color(color), position(position)
	{
	}

	bool Figure::move(const FigurePosition& position, const std::vector<Figure*>& otherFigures)
	{
		auto availableMoves = this->getAvailableMoves(otherFigures);

		for (auto& move : availableMoves)
		{
			if (move == position)
			{
				return true;
			}
		}

		return false;
	}

	char Figure::getSymbol() const
	{
		return this->symbol;
	}

	FigureColor Figure::getColor() const
	{
		return this->color;
	}

	void Figure::setColor(const FigureColor & color)
	{
		this->color = color;
	}

	FigurePosition Figure::getPosition() const
	{
		return this->position;
	}

	void Figure::setPosition(const FigurePosition & position)
	{
		this->position = position;
	}

	bool Figure::checkEmptyCell(const FigurePosition& position, const std::vector<Figure*>& otherFigures)
	{
		for (size_t i = 0; i < otherFigures.size(); i++)
		{
			if (otherFigures[i]->getPosition().getRow() == position.getRow()
				&& otherFigures[i]->getPosition().getCol() == position.getCol())
			{
				return false;
			}
		}

		return true;
	}

	bool Figure::checkTakenOppositeColorCell(const FigurePosition & position, const std::vector<Figure*>& otherFigures)
	{
		for (size_t i = 0; i < otherFigures.size(); i++)
		{
			if (otherFigures[i]->getColor() != this->getColor()
				&& otherFigures[i]->getPosition().getRow() == position.getRow()
				&& otherFigures[i]->getPosition().getCol() == position.getCol())
			{
				return true;
			}
		}

		return false;
	}

	std::vector<FigurePosition> Figure::getAvailableRowMoves(const std::vector<Figure*>& otherFigures)
	{
		std::vector<FigurePosition> availablePositions;

		getStartRowPositions(availablePositions, otherFigures);
		getEndRowPositions(availablePositions, otherFigures);

		return availablePositions;
	}

	std::vector<FigurePosition> Figure::getAvailableColMoves(const std::vector<Figure*>& otherFigures)
	{
		std::vector<FigurePosition> availablePositions;

		getStartColPositions(availablePositions, otherFigures);
		getEndColPositions(availablePositions, otherFigures);

		return availablePositions;
	}

	void Figure::getStartRowPositions(std::vector<FigurePosition>& availablePositions, const std::vector<Figure*>& otherFigures)
	{
		for (size_t col = this->position.getCol() - 1; col >= ChessUtils::LOWER_BOUND; col--)
		{
			FigurePosition currentPosition(this->position.getRow(), col);

			if (checkEmptyCell(currentPosition, otherFigures) && ChessUtils::checkPositionInBounds(currentPosition))
			{
				availablePositions.push_back(currentPosition);
				continue;
			}
			else if (checkTakenOppositeColorCell(currentPosition, otherFigures) && ChessUtils::checkPositionInBounds(currentPosition))
			{
				availablePositions.push_back(currentPosition);
				break;
			}
			break;
		}
	}

	void Figure::getEndRowPositions(std::vector<FigurePosition>& availablePositions, const std::vector<Figure*>& otherFigures)
	{
		for (size_t col = this->position.getCol() + 1; col <= ChessUtils::UPPER_BOUND; col++)
		{
			FigurePosition currentPosition(this->position.getRow(), col);

			if (checkEmptyCell(currentPosition, otherFigures) && ChessUtils::checkPositionInBounds(currentPosition))
			{
				availablePositions.push_back(currentPosition);
				continue;
			}
			else if (checkTakenOppositeColorCell(currentPosition, otherFigures) && ChessUtils::checkPositionInBounds(currentPosition))
			{
				availablePositions.push_back(currentPosition);
				break;
			}
			break;
		}
	}

	void Figure::getStartColPositions(std::vector<FigurePosition>& availablePositions, const std::vector<Figure*>& otherFigures)
	{
		for (size_t row = this->position.getRow() - 1; row >= ChessUtils::LOWER_BOUND; row--)
		{
			FigurePosition currentPosition(row, this->position.getCol());

			if (checkEmptyCell(currentPosition, otherFigures) && ChessUtils::checkPositionInBounds(currentPosition))
			{
				availablePositions.push_back(currentPosition);
				continue;
			}
			else if (checkTakenOppositeColorCell(currentPosition, otherFigures) && ChessUtils::checkPositionInBounds(currentPosition))
			{
				availablePositions.push_back(currentPosition);
				break;
			}
			break;
		}
	}

	void Figure::getEndColPositions(std::vector<FigurePosition>& availablePositions, const std::vector<Figure*>& otherFigures)
	{
		for (size_t row = this->position.getRow() + 1; row <= ChessUtils::UPPER_BOUND; row++)
		{
			FigurePosition currentPosition(row, this->position.getCol());

			if (checkEmptyCell(currentPosition, otherFigures) && ChessUtils::checkPositionInBounds(currentPosition))
			{
				availablePositions.push_back(currentPosition);
				continue;
			}
			else if (checkTakenOppositeColorCell(currentPosition, otherFigures) && ChessUtils::checkPositionInBounds(currentPosition))
			{
				availablePositions.push_back(currentPosition);
				break;
			}
			break;
		}
	}

}
