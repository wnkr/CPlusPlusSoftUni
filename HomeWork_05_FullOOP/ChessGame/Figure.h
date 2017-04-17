#pragma once
#include <vector>

#include "FigureColor.h"
#include "FigurePosition.h"

namespace ChessGame
{
	class Figure
	{
	protected:
		//static const size_t ROWS = 8;
		//static const size_t COLS = 8;

	private:
		char symbol;
		FigureColor color;
		FigurePosition position;

	public:
		Figure(char symbol, FigureColor color, FigurePosition position);
		virtual std::vector<FigurePosition> getAvailableMoves(const std::vector<Figure*>& otherFigures) = 0;
		bool move(const FigurePosition& position, const std::vector<Figure*>& otherFigures);

		FigurePosition getPosition() const;
		FigureColor getColor() const;

	protected:
		char getSymbol() const;
		void setColor(const FigureColor& color);
		void setPosition(const FigurePosition& position);

		static bool checkEmptyCell(const FigurePosition& position, const std::vector<Figure*>& otherFigures);
		bool checkTakenOppositeColorCell(const FigurePosition& position, const std::vector<Figure*>& otherFigures);

		std::vector<FigurePosition> getAvailableRowMoves(const std::vector<Figure*>& otherFigures);
		std::vector<FigurePosition> getAvailableColMoves(const std::vector<Figure*>& otherFigures);

	private:
		void getStartRowPositions(std::vector<FigurePosition>& availablePositions, const std::vector<Figure*>& otherFigures);
		void getEndRowPositions(std::vector<FigurePosition>& availablePositions, const std::vector<Figure*>& otherFigures);
		void getStartColPositions(std::vector<FigurePosition>& availablePositions, const std::vector<Figure*>& otherFigures);
		void getEndColPositions(std::vector<FigurePosition>& availablePositions, const std::vector<Figure*>& otherFigures);
	};
}
