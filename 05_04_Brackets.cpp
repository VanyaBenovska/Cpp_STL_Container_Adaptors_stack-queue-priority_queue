// 05_04_Brackets.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <string>
#include<sstream>
#include<stack>   
#include<iomanip>     
#include<cctype>      //char toupper, tolower                  
using namespace std;

int CountOfBrackets(const string & line)
{
	return line.size();
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	stack<char> dataStack;
	string line;
	cin >> line;
	if (CountOfBrackets(line) % 2 != 0)
	{
		cout << "invalid" << endl;
		return 0;
	}
	istringstream iss(line);
	char ch;
	while (iss >> ch)
	{
		if (!dataStack.empty())
		{
			char previousChar = dataStack.top();

			if ((previousChar == '(' && ch == ')') ||
				(previousChar == '[' && ch == ']') ||
				(previousChar == '{' && ch == '}') )
			{
				dataStack.pop();
				continue;
			}

			if (ch == '(')
			{
				if (!(previousChar == '(' || previousChar == '[' || previousChar == '{')) 
				{
					cout << "invalid" << endl;
					return 0;
				}

				dataStack.push(ch);
			}
			else if (ch == '[')
			{
				if (!(previousChar == '[' || previousChar == '{'))
				{
					cout << "invalid" << endl;
					return 0;
				}
				dataStack.push(ch);

			}
			else if (ch == '{')
			{
				if (!(previousChar == '{'))
				{
					cout << "invalid" << endl;
					return 0;
				}
				dataStack.push(ch);
			}
		}
		else
		{
			if (!(ch == '(' || ch == '[' || ch == '{'))
			{
				cout << "invalid" << endl;
				return 0;
			}
			dataStack.push(ch);
		}
	}

	if (dataStack.empty())
	{
		cout << "valid" << endl;
	}
	else
	{
		cout << "invalid" << endl;
	}
	return 0;
}

