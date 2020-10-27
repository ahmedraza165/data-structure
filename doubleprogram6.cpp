#include<iostream>
using namespace std;
struct node
{
	int data;
	node* prev, * next;
};
class sort
{
	node* head;
	node* tail;
public:
	sort()
	{
		tail = NULL;
		head = NULL;
	}
	void insert_sort(int data) //sort while insertion
	{
		node* temp = new node;
		temp->data = data;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
			head->prev = NULL;
			exit;
		}
		if (temp->data < head->data)
		{
			temp->prev = NULL;
			head->prev = temp;
			temp->next = head;
			head = temp;
			exit;
		}
		if (temp->data > tail->data)
		{
			temp->prev = tail;
			tail->next = temp;
			tail = temp;
			exit;
		}
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

};
int main()
{
	sort obj;
	int x;
	cout << "Enter the number of data you want to add \n";
	cin >> x;
	int data;
	cout << "Enter Data to insert\n";
	for (int i = 0; i < x; i++)
	{
		cin >> data;
		obj.insert_sort(data);
	}
	cout << "\n\n Sort while insertion : \n";
	obj.display();
	system("pause");
}
