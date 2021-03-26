#include <fstream>
#include <iostream>

#include "list2.h"
using namespace std;

bool fill_list(list2& list, const char* filename);
void show_list(const list2& list, bool reversed = false);

void main()
{
	setlocale(LC_ALL, "Rus");
	list2 list;
	if (!fill_list(list, "data.txt"))
	{
		cout << "Что-то пошло не так! :(";
		return;
	}
	show_list(list);
	show_list(list, true);
	auto val = get(list, 1);
	cout << (val ? *val : NAN) << endl;
	val = get(list, 109);
	cout << (val ? *val : NAN) << endl;
	remove(list, 1);
	show_list(list);
	remove(list, 0);
	show_list(list);
	remove(list, list.count-1);
	show_list(list);
	remove(list, list.count+10);
	show_list(list);
	clear(list);
	show_list(list);
	system("pause");
}

bool fill_list(list2& list, const char* filename)
{
	ifstream f(filename);
	if (f.is_open())
	{
		while (!f.eof())
		{
			double x;
			f >> x;
			if (f.fail())
			{
				clear(list);
				f.close();
				return false;
			}
			add(list, x);
		}
		f.close();
		return true;
	}
	return false;
}

void show_list(const list2& list, bool reversed)
{
	l2_elem* curr = reversed ? list.last : list.first;
	l2_elem* t = reversed ? list.first : list.last;
	if (!curr) cout << "Список пуст!\n";
	else while(curr)
	{
		cout << curr->x << ((curr==t)?"\n":" ");
		curr = reversed ? curr->prev : curr->next;
	}
}