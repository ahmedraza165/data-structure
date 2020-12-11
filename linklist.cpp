//priority queue implementation
#include<iostream>
using namespace std;
struct node
{
	int p;
	int data;
	node* NEXT;
}*heading;
class queue
{
	int size;
	node* temp;
	node* tail;
public:
	queue()
	{
		heading = NULL;
		tail = NULL;
		size = 0;
	}
	~queue() {}
	bool isempty()
	{
		if (heading == NULL)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	void  enqueue(int p, int data) //priority Queue
	{
		node* t, * q;
		t = new node;
		t->data = data;
		t->p = p;
		if (heading == NULL || p < heading->p)
		{
			t->NEXT = heading;
			heading = t;
		}
		else 
		{
			q = heading;
			while (q->NEXT != NULL && q->NEXT->p <= p)
			{
				q = q->NEXT;
			}
			t->NEXT = q->NEXT;
			q->NEXT = t;
		}
	}
	void dequeue()
	{
		node* t;
		if (heading == NULL)
			cout << "Queue Underflow\n";
		else {
			t = heading;
			cout << "Deleted item is: " << t->data << endl;
			heading = heading->NEXT;
			free(t);
		}

	}
	void display()
	{
		if (heading == NULL)
		{
			cout << "Queue is empty \n";
		}
		else
		{

			node* ptr;
			ptr = heading;
			if (ptr == NULL)
				cout << "Queue is empty\n";
			else {
				cout << "Priority Queue Items \n";
				while (ptr != NULL) {
					cout << ptr->p << " " << ptr->data << endl;
					ptr = ptr->NEXT;
				}
			}
		}
		cout << endl;
	}
};
int main()
{
	int n;
	queue access;
	cout << "WELCOME TO QUEUE" << endl;
a:	cout << " 1.Check if queue is empty.\n 2. Enter data in queue \n 3. Dequeue data  \n 4. Display the data \n 5. to exit \n";
	cin >> n;
	if (n == 1)
	{
		if (access.isempty()) {
			cout << "Queue is empty" << endl;
		}
		else {
			cout << "Queue is not empty" << endl;
			access.display();
		}
		goto a;
	}
	if (n == 2)
	{

		int data, n, p;
		cout << "Enter the number of element you add in queue" << endl;
		cin >> n;
		cout << "ENTER THE DATA YOU WANT TO ADD & Priority IN QUEUE \n";
		for (int i = 0; i < n; i++)
		{
			cout << "Data:";
			cin >> data;
			cout << endl;
			cout << "Priority:";
			cin >> p;
			access.enqueue(p, data);
		}
		goto a;
	}
	if (n == 3)
	{
		int n;
		cout << "Enter the number of element you want to dequeue" << endl;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			access.dequeue();
		}
		goto a;
	}
	if (n == 4)
	{
		access.display();
		goto a;
	}
	if (n == 5)
	{
		exit;
	}
	else
	{
		cout << "WRONG INPUT \n";
		goto a;
	}
	system("pause");
	return 0;
}