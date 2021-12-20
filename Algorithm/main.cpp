#include <iostream>
#include "List.h"
using namespace std;


int main(void)
{
	List<int> a;

	a.push_back(1);
	a.push_back(2);
	a.push_front(12);
	a.remove_back();

	cout << a.peek_back() << endl;
	cout << a.peek_front() << endl;
	return 0;
}