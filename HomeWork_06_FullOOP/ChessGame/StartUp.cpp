#include <iostream>
#include <vector>

#include "Pawn.h"
#include "Rook.h"

using namespace std;
using namespace ChessGame;

int main()
{
	// Currently only works for Pawns and Rooks... and no test function, only this manual tests (no time :))

	FigurePosition pos1(2, 2);
	Figure* p1 = new Rook(FigureColor::White, pos1);

	FigurePosition pos2(3, 2);
	Figure* p2 = new Pawn(FigureColor::White, pos2);

	FigurePosition pos3(1, 2);
	Figure* p3 = new Pawn(FigureColor::White, pos3);

	FigurePosition pos4(2, 5);
	Figure* p4 = new Pawn(FigureColor::Black, pos4);

	vector<Figure*> otherFigures;
	otherFigures.push_back(p2);
	otherFigures.push_back(p3);
	otherFigures.push_back(p4);

	auto availablePositions = p1->getAvailableMoves(otherFigures);

	for (const auto& position : availablePositions)
	{
		cout << position << endl;
	}

	cout << p1->move(FigurePosition(2, 5), otherFigures) << endl;

	return 0;
}