#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next, * prev;
};
class double_link
{
	int size;
	node* head;
	node* tail;
public:
	double_link()
	{
		size = 0;
		head = NULL;
		tail = NULL;
	}
	void display()
	{
		node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "  ";
			temp = temp->next;
		}
		cout << endl;
	}

	void insert(int data)
	{
		node* temp = new node;
		temp->data = data;
		temp->prev = NULL;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			head->prev = temp;
			temp->next = head;
			head = temp;
		}
		size++;

	};
	void insert_at(int index,int value)
	{
		node* temp = head;
		node* new_node = new node;
		while (index--)
		{
			if (index==0)
			{
				node * check= new node;
				check->data = value;
				check->next = NULL;
				check->next = temp;
				temp = check;

			}
			else
			{
				temp = temp->next;
			}
		}
	 
	
	};
	void insert_after(int required,int new_value)
	{
		node* temp=new node;
		node* temp1;
		temp1 = head;
		if (head == NULL)
		{
			cout << "could not insert" << endl;
			return;
		}
		if (head == tail)
		{
			if (head->data != required)
			{
				cout << "could not insert" << endl;
				return;
			}
			temp->data = new_value;
			head->next = temp;
			temp->next = NULL;
			head->prev = NULL;
			temp->prev = head;
			tail = temp;
			return;
		}
		if (tail->data == new_value)
		{
			temp->next = NULL;
			temp->prev = tail;
			tail->next = temp;
			tail = temp;
			return;
		}
		while (temp1->data != required)
		{
			temp1 = temp1->next;
			if (temp1 == NULL)
			{
				cout << "Could not insert" << endl;
				cout << "element not found" << endl;
				return;
			}
		}

		temp->next = temp1->next;
		temp->prev = temp1;
		temp->data = new_value;
		temp1->next->prev = temp;
		temp1->next = temp;
	
	};

};
int main()
{
	double_link obj;
	for (int i = 1; i < 6; i++)
	{
		obj.insert(i);
	}
	obj.display();
	int x;
a:	cout << "press 1 to insert node at position \n";
	cout << "press 2 to insert node at after\n";
	cout << "press 3 to exit\n";
	cin >> x;
	if (x == 1)
	{
		int index, new_value;
		cout << "Enter index value : \n";
		cin >> index;
		cout << "Enter new value : \n";
		cin >> new_value;
		cout << "\n Data inserted at given position\n";
		obj.insert_at(index,new_value);
		goto a;
	}
	if (x == 2)
	{
		int reqired, new_value;
		cout << "Enter required value : \n";
		cin >> reqired;
		cout << "Enter new value : \n";
		cin >> new_value;
		cout << "\nData Inserted After\n";
		obj.insert_after(reqired,new_value);
		obj.display();
		goto a;
	}
	if (x == 3)
	{
		exit;
	}
	if (x > 3 || x < 1)
	{
		cout << "Wrong input\n";
		goto a;
	}
	system("pause");
}
