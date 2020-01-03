// SP19_CST136_1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include "wagon_train.h"

using std::endl;
using std::cout;
using std::cin;
using std::ifstream;
using std::string;


bool open_file(ifstream & in_file, string & file_name);
void print_menu();

int main()
{
	bool cont = true;
	List l; Wagon w;
	ifstream in_file;
	string file_name;

	while (cont)
	{
		enum menu_item { input = 1, file = 2, print = 3, audit = 4, start_over = 5, quit = 6 };
		int menu_selection{};

		print_menu();

		cin >> menu_selection;

		switch (menu_selection)
		{
		case menu_item::input:
		{
			l.user_input(in_file, w);
		}
		break;
		case menu_item::file:
		{
			if (!open_file(in_file, file_name))
				cout << "Error opening file" << endl;
			else
			{
				while (!in_file.eof())
				{
					l.read_file(in_file, w);
				}
				l.print();
				in_file.close();
			}
		}
		break;
		case menu_item::print:
		{
			l.print();
		}
		break;
		case menu_item::audit:
		{
			l.audit();
		}
		break;
		case menu_item::start_over:
		{
			l.delete_list();
		}
		break;
		case menu_item::quit:
		{
			return 0;
		}
		break;
		default:
			std::cout << "Invalid selection. \n";
			break;
		}
	}
	
	return cont;
}


void print_menu(void)
{
	cout << "Please choose from one of the following menu items: " << endl;
	cout << endl;
	cout <<
		"(1) Enter New Wagon\n"
		"(2) File - Read Wagon Train File\n"
		"(3) Print Wagon Train\n"
		"(4) Audit Wagon Train for Errors\n"
		"(5) Start Over - Delete Current Wagon Train\n"
		"(6) Quit\n\n"
		"Enter Selection: ";
}


bool open_file(ifstream & in_file, string & file_name)
{
	cout << "Please enter the file name including the extension: ";
	cin >> file_name;
	cout << endl;

	in_file.open(file_name);

	return (!in_file.fail());
}