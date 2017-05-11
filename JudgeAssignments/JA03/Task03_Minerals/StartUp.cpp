#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <set>

// #include "Point.h" // not needed

using namespace std;

int main()
{
	int M;
	cin >> M;

	int commandCenterX;
	int commandCenterY;
	cin >> commandCenterX >> commandCenterY;

	// Point commandCenterPosition{ commandCenterX, commandCenterY };

	int N;
	cin >> N;

	map<int, int> minerals;

	for (size_t i = 0; i < N; i++)
	{
		string inputLine;
		getline(cin, inputLine);

		int posX;
		int posY;
		cin >> posX >> posY;

		// Point mineralPosition{ posX, posY };

		int t = abs(commandCenterX - posX) + abs(commandCenterY - posY);
		minerals[t]++;
	}

	int times = 0;
	int wannabeM = 0;
	for (const auto& mineral : minerals)
	{
		for (size_t i = 0; i < mineral.second; i++)
		{
			if (wannabeM == M)
			{
				break;
			}

			times += mineral.first;
			wannabeM++;
		}
	}

	//for (const auto& mineral : minerals)
	//{
	//	cout << mineral.first << ": " << mineral.second << endl;
	//}

	cout << times * 2 << endl;

	return 0;
}