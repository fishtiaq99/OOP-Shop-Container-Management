#pragma once
struct Container
{
	char* name;
	int containerno;
	Container* link;
};

class Shop {
public:
	Container* start;
	Shop() { start = NULL; }
	Shop(const Shop& other);

	void add_Container(char* name, int containerindex);
	void print_Shop();
	void delete_Chain(int containerindex);
	void Sort_Chain();
	void update_name_at_containerNumber(int, char*);
	void remove_Duplicate();
	void findContainer(int containerindex);
	void findContainer(int containerindex1, int containerindex2);
	~Shop();

};
