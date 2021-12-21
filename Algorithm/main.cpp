#include <iostream>
#include "List.h"
#include "stack.h"
#include "queue.h"
using namespace std;


int main(void)
{
	Queue<int> q;

	for (int i = 0; i < 10; i++)
		q.enqueue(i);

	while (!q.empty())
	{
		cout << q.dequeue() << endl;
	}

	cout << "end" << endl;
	return 0;
}