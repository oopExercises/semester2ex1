#include "Calculator.h"

void Calculator::printHelp() const
{
	cout << "The available commands are:\n"
		<< "* eval(uate) num x - compute the result of function #num on the\n"
		<< "following x string\n"
		<< "* substr(ing) num1 num2 - creates a substring starting from index\n"
		<< "num1 with the length of num2 characters\n"
		<< "* add(on) num1 num2 - Creates an operation that is the\n"
		<< "concatenation of operation #num1 and operation #num2\n"
		<< "* mul(tiply) n num - Creates an operation that is the multiply n \n"
		<< "of operation #num\n"
		<< "* comp(osite) num1 num2 - creates an operation that is the\n"
		<< "composition of operation #num1 and operation #num2\n"
		<< "* del(ete) num - delete operation #num from the operation list\n"
		<< "* help - print this command list\n"
		<< "* exit - exit the program\n";
}

void Calculator::printMenu() const
{
	cout << "List of available string operations:\n";

	for (int i = 0; i < m_operation.size(); i++)
		cout << i << ".    " << m_operation[i]->getName() << std::endl;

	cout << "\nEnter command ('help' for the list of available commands): ";
}

//check if the command exists, if not then return false
bool Calculator::checkCommand(const string command) const
{
	for (int i = 0; i < m_commands.size(); i++)
		if (command == m_commands[i])
			return true;
	return false;
}

//check if the operation exists, if not then return false
bool Calculator::checkOperation(const int operation) const
{
	if (operation >= 0 && operation < m_operation.size())
		return true;
	return false;
}

void Calculator::errorMsg(const int operation) const
{
	cout << "Operation number " << operation << " doesn't exist\n\n";
}

void Calculator::print(string str) const
{
    cout << str << endl << endl;
}

Calculator::Calculator()
{
    //filling the operation vector with the basic operations
	m_operation.push_back(make_shared<Id>());
	m_operation.push_back(make_shared<SwapCase>());
	m_operation.push_back(make_shared<Reverse>());
}

void Calculator::run()
{
    int op1 = 0, op2 = 0;
    int multiple = 0,startIndex = 0, length = 0;
    string command;

    while (command != "exit")
    {
        printMenu();

        cin >> command;
        if (!checkCommand(command))
        {
            cout << "Command not found\n\n";
            getline(cin, command); // clear the input buffer
            continue;
        }

        if (command == EVALUATE || command == DELETE)
        {
            cin >> op1;
            if (!checkOperation(op1))
            {
                errorMsg(op1);
                continue;
            }
        }
        else if (command == HELP)
        {
            printHelp();
        }
        else if (command == EXIT)
        {
            cout << "Goodbye" << endl;
            break;
        }
        else if (command == MULTIPLY)
        {
            cin >> multiple >> op1;
            if (!checkOperation(op1))
            {
                errorMsg(op1);
                getline(cin, command); // clear the input buffer
                continue;
            }
        }
        else if (command == SUBSTRING)
        {
            cin >> startIndex >> length;

            while (startIndex < 0 || length < 0)
            {
                cout << "please don't insert negative numbers!!, try again:\n";
                cin >> startIndex >> length;
            }
        }
        else
        {
            cin >> op1;
            if (!checkOperation(op1))
            {
                errorMsg(op1);
                getline(cin, command); // clear the input buffer
                continue;
            }
            cin >> op2;
            if (!checkOperation(op2))
            {
                errorMsg(op2);
                getline(cin, command); // clear the input buffer
                continue;
            }
        }

        if (command == EVALUATE)
        {
            

            string str;
            cin >> str;
            auto newStr = m_operation[op1]->calculate(str,1);
            print(newStr);
        }
        else if (command == MULTIPLY)
            m_operation.push_back(make_shared<Multiply>(multiple, m_operation[op1]));
        else if (command == ADD)
            m_operation.push_back(make_shared<Add>(m_operation[op1], m_operation[op2]));
        else if (command == SUBSTRING)
            m_operation.push_back(make_shared<Substring>(startIndex, length));
        else if (command == COMPOSITE)
            m_operation.push_back(make_shared<Composite>(m_operation[op1], m_operation[op2]));
        else if (command == DELETE)
            m_operation.erase(m_operation.begin() + op1);
    }
}
