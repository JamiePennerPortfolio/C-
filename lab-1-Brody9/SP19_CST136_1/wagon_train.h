#ifndef WAGON_TRAIN_H
#define WAGON_TRAIN_H
#include <string>
#include <iomanip>


class Wagon
{
public:
	Wagon() {};
	Wagon(std::string name, int weight, std::string team_type, int num_animals) :f_name(name), lbs(weight), t_type(team_type), n_animals(num_animals) { ; }

	std::string get_name ()const { return f_name; }
	std::string get_type()const { return t_type; }
	int get_lbs()const { return lbs; }
	int get_animals()const { return n_animals; }

	void set_name(std::string nm) { f_name = nm; }
	void set_type(std::string ty) { t_type = ty; }
	void set_lbs(int lb) { lbs = lb; }
	void set_animals(int animal) { n_animals = animal; }

	void print() {
		std::cout << std::left << std::setw(18) << f_name << " " << std::setw(10) << lbs << " " << 
		 std::right << std::setw(10) << t_type << " " << std::right << std::setw(15) << n_animals << " " << std::endl;
	}
	
	Wagon *next;

private:
	std::string f_name, t_type;
	int lbs, n_animals;
};

typedef Wagon * list_ptr;

class List
{
public:

	List(void) : head(nullptr) {};
	
	~List();

	void audit();
	void delete_list();
	void read_file(std::ifstream& in_file, Wagon& w);
	void user_input(std::ifstream& in_file, Wagon& w);
	bool new_family(const std::string& name);
	void add_sorted(std::ifstream& in_file, Wagon& w, std::string& name, std::string& team_type, int weight, int num_animals);
	void print(void)const;
	
private:
	list_ptr head;

};

list_ptr create_node(const std::string & name,int weight, const std::string & team_type, int num_animals);

#endif//WAGON_TRAIN_H