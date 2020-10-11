//point last node to front
#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
class move_last
{
	node* head;
	node* temp;
public:
	move_last()
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
	void display()
	{
		node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "  ";
			temp = temp->next;
		}
	}
	void MoveLastNodeToFront()
	{
		struct node* check, * temp;
		check = head;
		if (check->next == NULL)
		{
			cout << " 1st node is last node \n";
		}
		else
		{
			while (check->next->next)
			{
				check = check->next;
			}
			temp = check->next;
			check->next = NULL;
			temp->next = head;
			head = temp;
		}
	}
};
int main()
{
	move_last obj;
	int n, data;
	cout << "how many number you want to add \n";
	cin >> n;
	cout << "Enter the value you want to insert\n";
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		obj.insert(data);
	}
	cout << "Entered Value : \n";
	obj.display();
	cout << endl;
	obj.MoveLastNodeToFront();
	cout << "After Rearrange : \n";
	obj.display();
	cout << endl;
	system("pause");
	return 0;
}
