//swap the nodes of the link list 
#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
class swapping
{
	node* head;
	node* temp;
public:
	swapping()
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
	void swap(node* node1, node* node2)
	{
		int temp = node1->data;
		node1->data = node2->data;
		node2->data = temp;
	}
	void display()
	{
		node* ptr = head;

		while (ptr != NULL)
		{
			cout << ptr->data << " -> ";
			ptr = ptr->next;
		}
		cout << "\n";
	}
	void sort()
	{
		node* temp = head;
		while (temp != NULL && temp->next != NULL)
		{
			swap(temp,temp->next);
			// Move temp by 2 for the next pair
			temp = temp->next->next;
		}
	}
};
int main()
{
	swapping obj;
	int n, data;
	cout << "how many number you want to add \n";
	cin >> n;
	cout << "ENTER THE VALUE YOU WANT TO INSERT \n";
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		obj.insert(data);
	}
	cout << "The original list = " << endl;
	obj.display();


	obj.sort();

	cout << "The Sorted list = " << endl;
	obj.display();

	return 0;
}