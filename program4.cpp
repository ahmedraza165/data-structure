//find the number from link list
#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
class find_number
{
	node* head;
	node* temp;
public:
	find_number()
	{
		head = NULL;
		temp = NULL;
	}
	void insert(int data)
	{
		temp = new node;
		temp->data = data;
		temp->next = head;
		head = temp;
	}
	void check_number(int number)
	{
		bool x = false;
		node* ptr = head;
		while (ptr != NULL)
		{
			if (number == ptr->data)
			{
				cout << "Number Found \n";
				x = true;
			}
			ptr = ptr->next;
		}
		if (x == false)
		{
			cout << "Number not Found \n";
		}

	}
	void display()
	{
		node* ptr = head;
		while (ptr != NULL)
		{
			cout << "   " << ptr->data;
			ptr = ptr->next;
		}
		cout << "\n";
	}
};
int main()
{
	find_number obj;
	int n, data;
	cout << "How many number you want to enter \n";
	cin >> n;
	cout << "Enter the values \n";
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		obj.insert(data);
	}
	cout << "The Element is : \n";
	obj.display();
a :	cout << "Enter the number you want to find : \n";
	cin >> n;
	obj.check_number(n);
	int x;
	cout << "do you find another number press 1  \n";
	cin >> x;
	if (x == 1)
	{
		goto a;
	}
	system("pause");
	return 0;
}

