#include <iostream>

#include "SequenceGenerator.h"
#include "FibonacciGenerator.h"
#include "SqrtGenerator.h"

#include "SequencePrinter.h"
#include "SequencePrinterToString.h"
#include "SequencePrinterToConsole.h"
#include "SequencePrinterToFile.h"

using namespace std;
using namespace SequenceGenerators;
using namespace SequencePrinters;

SequencePrinter* getPrinter(string& str)
{

	// return new SequencePrinterToFile("output.txt");
	// return new SequencePrinterToConsole();
	return new SequencePrinterToString(str);
}

int main()
{
	typedef SequenceGenerator* generatorPtr;

	generatorPtr generatorsArr[2]
	{
		new SqrtGenerator(4, 10),
		new FibonacciGenerator(3, 6)
	};

	try
	{
		string str = "text\n";
		SequencePrinter* printer = getPrinter(str);
		
		{
			*printer << *generatorsArr[0] << *generatorsArr[1];
		}
		// or...
		{
			//printer->setSequence(*generatorsArr[0]);
			//printer->print();

			//printer->setSequence(*generatorsArr[1]);
			//printer->print();
		}

		cout << str;
	}
	catch (const std::string& ex)
	{
		cerr << ex << endl;
	}

	for (size_t i = 0; i < 2; i++)
	{
		delete generatorsArr[i];
	}

	return 0;
}