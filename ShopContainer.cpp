#include <iostream>
#include "ShopContainerContents.h";
using namespace std;

Shop::Shop(const Shop& other) {
	if (other.start == nullptr) {
		start = nullptr;
		return;
	}
	bool check = true;
	Container* temp = other.start;
	start = new Container;
	start->containerno = other.start->containerno;
	start->link = nullptr;
	int length = 0;
	while (other.start->name[length] != '\0') {
		length++;
	}
	start->name = new char[length + 1];
	for (int i = 0; i < length; i++) {
		start->name[i] = other.start->name[i];
	}
	start->name[length] = '\0';
	length = 0;
	Container* New = start;
	while (temp->link != nullptr) {
		New->link = new Container;
		New = New->link;
		temp = temp->link;
		New->containerno = temp->containerno;
		while (temp->name[length] != '\0') {
			length++;
		}
		New->name = new char[length + 1];
		for (int i = 0; i < length; i++) {
			New->name[i] = temp->name[i];
		}
		New->name[length] = '\0';



		New->link = nullptr;
	}

}

void Shop::add_Container(char* name, int containerindex) {

	Container* c = new Container;
	c->name = new char[100];
	int i = 0;
	int j = 0;
	while (name[j] != '\0') {
		c->name[i++] = name[j++];
	}
	c->name[i] = '\0';
	c->containerno = containerindex;
	c->link = nullptr;

	if (start == NULL) {
		start = c;
	}
	else if (start != NULL) {
		Container* temp = start;
		while (temp->link != nullptr) {
			temp = temp->link;
		}
		temp->link = c;
	}
}
void Shop::print_Shop() {
	Container* temp = nullptr;
	temp = start;
	while (temp != nullptr) {
		cout << temp->name << '-' << temp->containerno << endl;
		temp = temp->link;
	}
}
void Shop::delete_Chain(int containerindex) {
	Container* Prev = nullptr;
	Container* Next = start;
	bool check;
	while (Next != nullptr) {
		check = Next->containerno == containerindex;
		if (check) {
			delete[] Next->name;
			if (Prev == nullptr) {
				start = start->link;
				delete Next;
				Next = start;
			}
			else {
				Prev->link = Next->link;
				delete Next;
				Next = Prev->link;
			}
		}
		else {
			Prev = Next;
			Next = Next->link;
		}
	}

}
void Shop::Sort_Chain() {

	Container* temp1 = start;
	Container* ptr1 = nullptr;
	ptr1 = start;

	bool check1;
	bool check2 = false;
	check1 = (start == nullptr);
	if (check1) {
		return;
	}
	check2 = (start->link == nullptr);
	if (check2) {
		return;
	}

	Container* ptr2 = nullptr;
	Container* temp2 = nullptr;

	for (int i = 0; i < 100; i++) {

		if (ptr2 != nullptr) {
		}
		check1 = ((ptr1->link) != nullptr);
		check2 = false;
		if (check1) {
			check2 = (ptr1->containerno) > (ptr1->link->containerno);
		}
		if (check1 && check2) {

			if (ptr1->link->link != nullptr) {

				if (ptr2 != nullptr) {

					temp1 = ptr1;
					ptr2->link = ptr1->link;
					temp2 = ptr2->link->link;
					ptr2->link->link = nullptr;
					ptr1->link = temp2;
					ptr2->link->link = temp1;
					ptr2 = ptr2->link;

					cout << endl;
				}
				else {
					temp1 = ptr1;
					start = ptr1->link;
					temp2 = start->link;
					start->link = nullptr;
					start->link = temp1;
					temp1->link = temp2;
					temp1 = nullptr;
					temp2 = nullptr;
				}
			}
			else {

				temp1 = ptr1;
				ptr2->link = ptr1->link;
				temp1->link = nullptr;
				ptr2->link->link = temp1;
				ptr1 = ptr2->link;
				temp1 = nullptr;
				temp2 = nullptr;
			}
			if (ptr2 != nullptr) {
				ptr2 = ptr2->link;
				ptr1 = ptr1->link;
			}
			else
				ptr2 = start;

		}
		else {

			if (!check1) {
				ptr1 = start;
				ptr2 = nullptr;
			}
			else {
				ptr2 = ptr1;
				ptr1 = ptr1->link;
			}

		}
	}



}
void Shop::update_name_at_containerNumber(int containerindex, char* name) {
	Container* current = start;
	int length = 0;
	int i = 0;

	while (current != nullptr) {
		if (current->containerno == containerindex) {
			delete[] current->name;
			while (name[i++] != '\0') {
				length++;
			}
			current->name = new char[length + 1];
			length = 0;
			i = 0;
			int j = 0;
			while (name[i] != '\0') {
				current->name[j++] = name[i++];
			}
			current->name[j] = '\0';
			j = 0;
		}
		current = current->link;
	}

}

void Shop::remove_Duplicate() {
	bool check1 = (start == nullptr);
	bool check2;
	if (check1) {
		return;
	}
	else if ((start->link == nullptr)) {
		return;
	}
	else if (!(check1 || (start->link == nullptr))) {
		Container* temp = start;
		Container* revolve;
		Container* Prevrevolve;
		while (temp != nullptr) {
			revolve = temp->link;
			Prevrevolve = temp;

			while (revolve != nullptr) {
				check1 = (temp->containerno == revolve->containerno);
				check2 = true;
				for (int i = 0; temp->name[i] != '\0' || revolve->name[i] != '\0'; i++) {
					if (temp->name[i] == revolve->name[i]) {
					}
					else {
						check2 = false;
						break;
					}
				}


				if (check1 && check2) {
					Container* temp1 = nullptr;
					temp1 = revolve;
					Prevrevolve->link = revolve->link;
					revolve = revolve->link;
					delete[] temp1->name;
					delete temp1;
				}
				else {
					Prevrevolve = revolve;
					revolve = revolve->link;
				}
			}
			temp = temp->link;

		}

	}
}

void Shop::findContainer(int containerindex) {
	Container* c = start;
	bool A = 1;
	while (A) {
		if (c == nullptr) {
			break;
		}
		if (c->containerno == containerindex) {
			cout << c->name << endl;
			break;
		}
		else {
			c = c->link;
		}
	}


}

void Shop::findContainer(int containerindex1, int containerindex2) {
	Shop::Sort_Chain();
	Container* temp = start;
	while (1) {
		if (start == nullptr) {
			break;
		}
		if (temp->containerno == containerindex1) {
			do {
				cout << temp->name << endl;
				temp = temp->link;
			} while (temp->containerno != containerindex2);
			cout << temp->name << endl;
			break;
		}
		else {
			temp = temp->link;
		}
	}
}


Shop::~Shop() {
	Container* current = nullptr;
	current = start;
	Container* temp = nullptr;
	if (current == nullptr) {
		return;
	}
	else {
		while (current != nullptr) {
			temp = current;
			current = current->link;
			delete[] temp->name;
			temp->link = nullptr;
			delete temp;
		}
		start = nullptr;
	}
}