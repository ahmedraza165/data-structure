#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next, * prev;
};
class double_link
{
	node* head;
	node* tail;
public:
	double_link()
	{
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
	};

	void delete_at(int value)
	{
		node* temp = head;
		if (head->data == value)
		{
			head = head->next;
			head->prev = NULL;
			delete temp;
			return;
		}
		else if (tail->data == value)
		{
			temp = tail;
			tail = tail->prev;
			tail->next = NULL;
			delete temp;
			return;
		}
		while (temp->data != value)
		{
			temp = temp->next;
			if (temp == NULL)
			{
				cout << "element not found" << endl;
				return;
			}
		}
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
		delete temp;
	};
	void delete_after(int value)
	{
		node* temp = head;
		while (temp != NULL)
		{
			if (temp->data == value)
			{
				node* newNode = new node;
				newNode->next = temp->next;
				temp->next = newNode;
				delete newNode;
				break;
			}
			else
			{
				temp = temp->next;
			}
		}
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
a:	cout << "press 1 to delete node at position \n";
	cout << "press 2 to delete node after\n";
	cout << "press 3 to exit\n";
	cin >> x;
	if (x == 1)
	{
		int  new_value;
		cout << "Enter value : \n";
		cin >> new_value;
		cout << "\n Data deleted from given position\n";
		obj.delete_at(new_value);
		obj.display();
		goto a;
	}
	if (x == 2)
	{
		int new_value;
		cout << "Enter value : \n";
		cin >> new_value;
		cout << "\nData Deleted After\n";
		obj.delete_after(new_value);
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