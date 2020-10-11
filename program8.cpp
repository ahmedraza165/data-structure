//reverse the node program
#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
class reverse
{
	node* head;
	node* temp;
public:
	reverse()
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
		reverse_check(&head);
	}
	void reverse_check(struct node** head_rev)
	{
		struct node* temp = NULL;
		struct node* prev = NULL;
		struct node* current = (*head_rev);
		while (current != NULL)
		{
			temp = current->next;
			current->next = prev;
			prev = current;
			current = temp;
		}
		(*head_rev) = prev;
	}
};
int main()
{
	reverse obj;
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
	cout << "Reversed value (with node) : \n";
	obj.display();
	system("pause");
	return 0;
}

