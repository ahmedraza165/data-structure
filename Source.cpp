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
public:
	sorting()
	{
		temp = NULL;
		HEAD = NULL;
	}
	void insert(int data)
	{
		head = new node;
		head->data = data;
		head->next = temp;
		temp = head;
	}
	void bubblesort
	{
    while (head != NULL)
	  {
		node* minimun = head;
		node* x = head->next;
		if (min->data > r->data)
		{
				min = r;
		}
		else
		{
				r = r->next;
		}
		// Swap Data 
		int z = head->data;
		head->data = min->data;
		min->data = z;
		head = head->next;
	   }
	}
	void selectionsort
	{
	while (head != NULL)
	{
		node* minimun = head;
		node* x = head->next;
		while (r != NULL)
		{
			if (min->data > r->data)
			{
				min = r;
			}
			else
			{
				r = r->next;
			}
		}
		// Swap Data 
		int z = head->data;
		head->data = min->data;
		min->data = z;
		head = head->next;
	  }
	}
};
int main()
{
	sorting obj;
	int n, data;
	cout << "Enter the number of data you want to add in stack : \n" << endl;
	cin >> n;
	cout << "Enter Data : \n";
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		insert(data);
	}
a:	cout << "Press 1 for selection sort \n";
	cout << "Press 2 for bubble sort \n";
	cin >> n;
	if (n == 1)
	{
		obj.selectionsort()
	}
	if (n == 2)
	{
		obj.bubblesort()
	}

}