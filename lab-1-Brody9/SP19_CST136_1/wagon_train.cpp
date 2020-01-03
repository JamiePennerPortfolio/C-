#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include "wagon_train.h"

using std::endl;
using std::cout;
using std::cin;
using std::string;

List::~List()
{
	delete_list();
}


void List::delete_list()
{
		cout << "---------------------" << endl;
		cout << "~List" << endl;

		list_ptr temp;

		while (head != nullptr)
		{
			temp = head;
			cout << " " << temp->get_name() << endl;
			head = head->next;
			delete temp;
			temp = nullptr;
		}
		cout << "---------------------" << endl;
}


void List::read_file(std::ifstream& in_file, Wagon& w)
{
	
	string temp_;
	string name, team_type;
	int weight, num_animals;

	getline(in_file, name, '|');
	getline(in_file, temp_, '|');
	weight = atoi(temp_.c_str());
	getline(in_file, team_type, '|');
	getline(in_file, temp_, '\n');
	num_animals = atoi(temp_.c_str());

	if (new_family (name)== true)
	{
		add_sorted(in_file, w, name, team_type, weight, num_animals);
	}
}


void List::user_input (std::ifstream& in_file, Wagon& w)
{
	string name, team_type;
	int weight{ 0 }, num_animals;

	while (size(name) > 50 ||size(name) < 1)
	{
		cout << "Family name: "; cin >> name;
		if (size(name) > 50)
		{
			cout << " That name is either too long or too short. Please try again. " << endl;
		}
	}
	while (weight < 1)
	{
		cout << "Weight: "; cin >> weight;
		if (weight < 1)
		{
			cout << "Weight must be greater than 0. Please try again." << endl;
		}
	}

	while (team_type != "Oxen" && team_type != "Horse")
	{
		cout << "Team Type (Enter o for Oxen or h for Horse): "; cin >> team_type;
		if (team_type == "o" || team_type == "O")
		{
			team_type = "Oxen";
		}
		else if (team_type == "h" || team_type == "H")
		{
			team_type = "Horse";
		}
		else
			cout << "Invalid option. Please try again" << endl;
	}
	
	cout << "Number of Animals: "; cin >> num_animals;
	cout << endl;

	if (new_family(name) == true)
	{
		add_sorted(in_file, w, name, team_type, weight, num_animals);
	}
}


list_ptr create_node (const string & name, int weight, const std::string & team_type, int num_animals)
{
	list_ptr temp = new Wagon;

	temp->set_name(name);
	temp->set_lbs(weight);
	temp->set_type(team_type);
	temp->set_animals(num_animals);

	return (temp);
}


void List::add_sorted (std::ifstream& in_file, Wagon& w, string& name, string& team_type, int weight, int num_animals)
{
	list_ptr temp, previous, new_node;
	temp = head;
	previous = nullptr;

	new_node = create_node(name, weight, team_type, num_animals);

	while (temp != nullptr && temp->get_name() < name)
	{
		previous = temp;
		temp = temp->next;
	}
	if (head == nullptr)
		head = new_node;
	else if (previous == nullptr)
	{
		new_node->next = head;
		head = new_node;
	}
	else
	{
		previous->next = new_node;
		new_node->next = temp;
	}
}


bool List::new_family(const string& name)
{
	list_ptr temp{ nullptr }, previous{ nullptr };
	bool new_family = true;

	temp = head;

		while ((temp != nullptr) && (temp->get_name() < name))
		{
			previous = temp;
			temp = temp->next;

		}
		if (temp == nullptr || temp->get_name() > name)
			new_family = true;
		else if (temp == nullptr || temp->get_name() == name)
		{
			cout << name << " already exists." << endl; new_family = false;
		}
	return new_family;
}


void List:: audit()
{
	int total_wagons = 0, total_animals = 0;
	list_ptr temp = nullptr;

	temp = head;

	while (temp != nullptr)
	{
		total_wagons ++;
		total_animals += temp->get_animals();
		temp = temp->next;
	}

	if(total_animals > 30 )
	{
		cout << "Audit Failed: Wagon cannot have more than 30 animals." << endl;
	}
	if (total_wagons > 10)
	{
		cout << "Audit Failed: Wagon cannot have more than 10 wagons." << endl << endl;
	}
	else
		cout << "Audit Passed" << endl << endl;
}


void List::print(void) const
{
	cout << endl;
	cout << "Wagons: " << endl;
	cout << endl;

	std::cout << std::left << std::setw(18) << "Family Name" << std::setw(13) << "Weight" <<
		  std::right << std::setw(10) << "Type " << std::right << std::setw(25) << "Number of Animals \n" << 
		"----------------------------------------------------------------" << std::endl;

	int total_weight = 0, total_animals = 0;
	list_ptr temp = nullptr;

	if (head == nullptr)
		cout << "The list is empty." << endl;
	else
	{
		temp = head;
		while (temp != nullptr)
		{
			temp->print();
			total_weight += temp->get_lbs();
			total_animals += temp->get_animals();
			temp = temp->next;
		}
	}
	cout << endl;
	cout << "Total Weight: " << total_weight << endl;
	cout << "Total Animals: " << total_animals << endl;
}



