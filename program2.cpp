//bubble sort and selection sort using link list
#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
class sorting
{
	node* temp;
	node* head;
	int size;
public:
	sorting()
	{
		size = 0;
		temp = NULL;
		head = NULL;
	}
	void insert(int data)
	{
		temp = new node;
		temp->data = data;
		temp->next = head;
		head = temp;
		size++;
	}
	void display()
	{
		node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "    ";
			temp = temp->next;
		}
	}
	void swap(node* node1, node* node2)
	{
		int temp = node1->data;
		node1->data = node2->data;
		node2->data = temp;
	}
	void bubblesort()
	{
		int swapped;
		node* first;
		node* Last = NULL;
		do
		{
			swapped = 0;
			first = head;
			while (first->next != Last)
			{
				if (first->data > first->next->data)
				{
					swap(first, first->next); //swap the data
					swapped = 1;
				}
				first = first->next;
			}
			Last = first;
		} while (swapped);
	}

	void selectionsort()
	{
		node* check = head;
		while (check != 0)
		{
			node* minimun = check;
			node* x = check->next;
			while (x != NULL)
			{
				if (minimun->data > x->data)
				{
					minimun = x;
				}
				else
				{
					x = x->next;
				}
			}
			// Swap Data
			int z = check->data;
			check->data = minimun->data;
			minimun->data = z;
			cout << "    " << check->data;
			check = check->next;
		}
	}
};
int main()
{
	sorting obj;
	int n, data;
	cout << "Enter the number of data you want to add in link list: \n" << endl;
	cin >> n;
	cout << "Enter Data : \n";
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		obj.insert(data);
	}
	obj.display();
a:  cout << endl;
	cout << "Press 1 for selection sort \n";
	cout << "Press 2 for bubble sort \n";
	cout << "Press 3 for exit \n";
	cin >> n;
	if (n == 1)
	{
		obj.selectionsort();
		goto a;
	}
	if (n == 2)
	{
		obj.bubblesort();
		obj.display();
		goto a;
	}
	if (n == 3)
	{
		exit;
	}
	system("pause");
	return 0;
}
