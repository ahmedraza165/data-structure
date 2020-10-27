#include<iostream>
using namespace std;
struct node
{
	int data;
	node* prev, * next;
};
class reverse
{
	node* head;
public:
	reverse()
	{
		head = NULL;
	}
	void insert(int data)
	{
		node* temp = new node;
		temp->data = data;
		temp->prev = NULL;
		temp->next = head;
		if (head != NULL)
		{
			head->prev = temp;
		}
		head = temp;

	};
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
	void rever()
	{
		node* temp = NULL;
		node* curr = head;
		while (curr != NULL)
		{
			temp = curr->prev;
			curr->prev = curr->next;
			curr->next = temp;
			curr = curr->prev;
		}
		if (temp != NULL)
		{
			head = temp->prev;
		}
		cout << "\n Reverse data and nodes is : \n";
		display();

	}

};
int main()
{
	reverse obj;
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
	cout << "Data you Entered \n";
	obj.display();
	obj.rever();
	system("pause");
}
