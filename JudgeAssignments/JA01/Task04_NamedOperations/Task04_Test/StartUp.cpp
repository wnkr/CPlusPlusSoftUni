#include <cmath>
#include <gtest\gtest.h>
#include "../Task04_NamedOperations/Utils.h"

TEST(ExecuteOperation_should_return, proper_result)
{
	// Arrange
	vector<int> array = { 18, 1 };

	string command = "sum 0 2";
	vector<vector<string>> operations(4);
	operations[0].push_back("sum");
	operations[1].push_back("avg");
	operations[2].push_back("min");
	operations[3].push_back("max");
	PopulatePointerOperations();

	string expectedValue = "sum(0,2)=19";

	// Act
	auto result = ExecuteOperation(command, operations, array);

	// Assert
	EXPECT_STREQ(expectedValue.c_str(), result.c_str());
}

TEST(PrintOperations_should_return, proper_result)
{
	// Arrange
	const int numberOfOperations = 6;
	vector<int> array = { 5, 4, 3, 2, 1};

	vector<vector<string>> operations(4);
	operations[0].push_back("sum");
	operations[1].push_back("avg");
	operations[2].push_back("min");
	operations[3].push_back("max");

	PopulatePointerOperations();

	vector<string> outputOperations;
	vector<string> commands = {
		"max 0 5",
		"sum 0 5",
		"sum 0 1",
		"min 0 5",
		"avg 0 2",
		"sum 0 5"
	};

	for (const auto& command : commands)
	{
		outputOperations.push_back(ExecuteOperation(command, operations, array));
	}


	string expectedValue = "[6]{max(0,5)=5,sum(0,5)=15,sum(0,1)=5,min(0,5)=1,avg(0,2)=4,sum(0,5)=15}";

	// Act
	string result = PrintOperations(numberOfOperations, outputOperations);

	// Assert
	EXPECT_STREQ(expectedValue.c_str(), result.c_str());
}

int main(int ac, char* av[])
{
	testing::InitGoogleTest(&ac, av);
	return RUN_ALL_TESTS();
}