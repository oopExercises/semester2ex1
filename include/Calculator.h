#pragma once

#include "Add.h"
#include "Composite.h"
#include "Id.h"
#include "Multiply.h"
#include "Operation.h"
#include "Reverse.h"
#include "Substring.h"
#include "SwapCase.h"
#include "io.h"


class Calculator
{
private:
	vector<shared_ptr<Operation>> m_operation;
	vector<string> m_commands ={EVALUATE ,
								ADD,
								ID,
								MULTIPLY,
								REVERSE,
								SUBSTRING,
								SWAPCASE,
								COMPOSITE ,
								DELETE ,
								HELP ,
								EXIT};

	
	void printHelp() const;
	void printMenu() const;
	bool checkCommand(const string) const;
	bool checkOperation(const int) const;
	void errorMsg(const int) const;
	void print(string) const;

public:
	Calculator();

	void run();
};