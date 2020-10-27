#include<iostream>
using namespace std;
struct node
{
	int data;
	node* prev, * next;
};
class dublicate
{
	node* head;
public:
	dublicate()
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
	void remove_dup()
	{
		  node* temp=head;
		  node* temp1;
	
		  if (temp == NULL)
		  {
			  return;
		  }
			while (temp->next != NULL)
			{
				if (temp->data == temp->next->data)
				{
					temp1 = temp->next->next;
					free(temp->next);
					temp->next = temp1;
				}
				else
				{
					temp = temp->next;
				}
	
			}
	}
};
int main()
{
	   dublicate obj;
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
		cout << "\nList before removing dublicate\n";
		obj.display();
		cout << endl;
		obj.remove_dup();
		cout << "\nlist After removing duplicate\n";
		obj.display();
		cout << endl;
}
