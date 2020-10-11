//combine group of odd number 
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
	void display(node *Node)
	{

		while (Node != NULL)
		{
			cout << Node->data << " -> ";
			ptr = Node->next;
		}
		cout << "\n";
	}
	node* rearrangeEvenOdd()
	{
		node* odd = head;
		node* even = head->next;  
		node* evenFirst = even;

		while (1)
		{
	
			if (!odd || !even || !(even->next))
			{
				odd->next = evenFirst;
				break;
			}

			// Connecting odd nodes  
			odd->next = even->next;
			odd = even->next;

			// If there are NO more even nodes after  
			// current odd.  
			if (odd->next == NULL)
			{
				even->next = NULL;
				odd->next = evenFirst;
				break;
			}

			// Connecting even nodes  
			even->next = odd->next;
			even = odd->next;
		}

		return head;
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

	node head = obj.rearrangeEvenOdd();
	cout << "The Sorted list = " << endl;
	obj.display(head);

	return 0;
}
