#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
#include <cassert>

#include "Town.h"
#include "Vector2D.h"

using namespace std;

vector<Town> readTownsFromConsole(int N)
{
	vector<Town> towns;

	while (N)
	{
		std::string line;
		std::getline(std::cin, line);
		std::istringstream inputStream(line);

		string name;
		double x, y;
		inputStream >> name >> x >> y;

		Vector2D position(x, y);
		Town town(name, position);
		towns.push_back(town);

		N--;
	}

	return towns;
}

vector<Town> findClosestTowns(const vector<Town>& towns)
{
	vector<Town> closestTowns;

	double minDistance = std::numeric_limits<double>::max();
	for (size_t i = 0; i < towns.size(); i++)
	{
		for (size_t j = i + 1; j < towns.size(); j++)
		{
			Vector2D distance = towns[i].getPosition() - towns[j].getPosition();

			if (distance.getLength() < minDistance)
			{
				closestTowns.clear();
				minDistance = distance.getLength();
				closestTowns.push_back(towns[i]);
				closestTowns.push_back(towns[j]);
			}
		}
	}

	return closestTowns;
}

void printClosestTowns(const vector<Town>& closestTowns)
{
	assert(closestTowns.size() == 2);
	cout << closestTowns[0].getName() << "-" << closestTowns[1].getName() << endl;

}

int main()
{
	int N;
	cin >> N;
	cin.ignore();

	auto towns = readTownsFromConsole(N);
	auto closestTowns = findClosestTowns(towns);
	printClosestTowns(closestTowns);

	return 0;
}