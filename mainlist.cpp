#include <iostream>
#include <string>
#include <clocale>
#include "lists.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "");
	List<string> lst;
	lst.Add("Hello");
	lst.Add("Push");
	lst.Add("Item");

	for (int i = 0; i < lst.Count(); i++)
	{
		cout << lst[i] << endl;
	}
	lst.AddAt(2, "Jack");
	cout << endl << "Add one item" << endl << endl;
	for (int i = 0; i < lst.Count(); i++)
	{
		cout << lst[i] << endl;
	}
	return (0);
}
