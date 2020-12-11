//LINK LIST IMPLEMENTATION OF QUEUE
#include<iostream>
using namespace std;
struct node
{
	int data;
	node* NEXT;
};
class queue
{
	int size;
	node* temp;
	node* tail;
	node* heading;
public:
	queue()
	{
		heading = NULL;
		tail = NULL;
		size = 0;
	}
	void  enqueue(int data)
	{
		if (!is_full())
		{
			temp = new node;
			temp->data = data;
			temp->NEXT = NULL;
			if (heading == NULL)//for first time
			{
				tail = temp;
				heading = temp;
			}
			else
			{
				tail->NEXT = temp;
				tail = temp;
			}
			size++; //getting the size
		}
		else
		{
			cout<<"Queue is full \n"
		}
		
	};
	void dequeue()
	{
		int del;
		if (heading == NULL)
		{
			cout << "Queue is empty \n";
		}
		else
		{
			node* ptr = heading;
			del = ptr->data;
			heading = heading->NEXT;
			delete (ptr);
			cout << "dequeue Successfully \n";
			size--;
		}
	};
	void display()
	{
		if (heading == NULL)
		{
			cout << "Queue is empty \n";
		}
		else
		{

			node* ptr = heading;
			cout << "Queue elements are: ";

			while (ptr != NULL)
			{
				cout << ptr->data << " ";
				ptr = ptr->NEXT;
			}
			cout << endl;

		}
	};
	bool is_empty()//return flase if queue is not full
	{
			if (heading == NULL)
			{
				return true;
			}
			else
			{
				return false;
			}
	};
	bool is_full()//return true if queue is full
	{
			if (size > 5) //constant size
			{
				return true;
			}
			else
			{
				return false;
			}
	};
};

int main()
{
	int n;


	queue access;
a:	cout << "\n\nWELCOME TO MY QUEUE" << endl;
	cout << "PRESS-1 FOR ENQUEUE" << endl;
	cout << "PRESS-2 FOR DEQUEUE" << endl;
	cout << "PRESS-3 TO  CHECK EMPTY" << endl;
	cout << "PRESS-4 TO  CHECK FULL" << endl;
	cout << "PRESS-5 FOR DISPLAY" << endl;
	cout << "PRESS-6 FOR EXIT" << endl;
	cin >> n;
	if (n == 1)
	{
		int data, n;
		cout << "Enter the number of element you add in queue" << endl;
		cin >> n;
		cout << "ENTER THE DATA You WANT TO ADD IN QUEUE \n";
		for (int i = 0; i < n; i++)
		{
			cin >> data;
			access.enqueue(data);
		}
		goto a;
	}
	if (n == 2)
	{
		access.dequeue();
		goto a;
	}
	if (n == 3)
	{
		if (access.is_empty())
		{
			cout << "Queue is empty \n";
		}
		else
		{
			cout<<"Queue is not empty \n"
		}
		goto a;
		
	}
	if (n == 4)
	{

		if (access.is_full())
		{
			cout << "Queue is full \n";
		}
		else
		{
			cout << "Queue is not full \n";
		}
		goto a;
	}
	if (n == 5)
	{
		access.display();
		goto a;
	}
	if (n == 6)
	{
		exit;
	}
	if (n > 6 && n < 1)
	{
		cout << "WRONG INPUT \n";
		goto a;
	}
	system("pause");
	return 0;
}
