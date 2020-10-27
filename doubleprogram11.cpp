#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
	node* prev;
};
class CircularDouble
{
	node* head;
public:
	CircularDouble()
	{
		head = NULL;
	}
	void insert(int val)
	{
		node* temp = new node;
		temp->data = val;
		if (head == NULL)
		{
			temp->prev = temp;
			head = temp;
			temp->next = head;
		}
		else
		{
			node* newnode = head->prev;
			head->prev = temp;
			temp->prev = newnode;
			temp->next = head;
			newnode->next = temp;
		}
	}
	void del_element(int val)
	{
		node* temp = head;
		if (head->data == val)
		{
			head = head->next;
			head->prev = NULL;
			delete temp;
			return;
		}
		while (temp->data != val)
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

	}
	void search(int x)
	{
		node* temp = head;
		int found = 0;

		do
		{
			if (temp->data == x)
			{
				cout << "\nFound\n";
				found = 1;
				break;
			}
			temp = temp->next;
		} while (temp != head);

		if (found == 0)
		{
			cout << "\nNot Found\n";
		}
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
	void is_empty()
	{
		if (head == NULL)
		{
			cout << "Empty\n";
		}
		else
		{
			cout << "Not Empty\n";
		}
	}
};
int main()
{
	CircularDouble obj;
	int n;
a:	cout << "Press 1 To insert the data \n";
	cout << "Press 2 To delete the data \n";
	cout << "Press 3 To check if it is empty \n";
	cout << "Press 4 To search the data \n";
	cout << "Press 5 To Display \n";
	cout << "Press 6 To exit\n";
	cin >> n;
	if (n == 1)
	{
		int x;
		cout << "Enter the number of data you want to add \n";
		cin >> x;
		int data;
		cout << "Enter Data to insert\n";
		for (int i = 0; i < x; i++)
		{
			cin >> data;
			obj.insert(data);
		}
		goto a;
	}
	if (n == 2)
	{
		obj.display();
		int x;
		cout << "Enter Element to delete : \n";
		cin >> x;
		obj.del_element(x);
		goto a;
	}
	if (n == 3)
	{
		obj.is_empty();
		goto a;
	}
	if (n == 4)
	{
		int x;
		cout << "Enter the Number to Search : \n";
		cin >> x;
		obj.search(x);
		goto a;
	}
	if (n == 5)
	{
		obj.display();
		goto a;
	}
	if (n == 6)
	{
		exit;
	}
	if (n > 6 || n < 1)
	{
		cout << "\nWrong Input\n";
		goto a;
	}
	system("pause");

}
