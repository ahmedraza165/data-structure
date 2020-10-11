#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
class reverse1
{
	node* head;
	node* temp;
public:
	reverse1()
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
		cout << "\nReversed Element : \n";
		reverse_D(head);
	}
	void reverse_D(struct node* temp)
	{
		if (temp != NULL)
		{
			//recursive call to 
			reverse_D(temp->next);
			cout<< temp->data<<"  ";
		}
	}
};
int main()
{
	reverse1 obj;
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
	system("pause");
	return 0;
}

