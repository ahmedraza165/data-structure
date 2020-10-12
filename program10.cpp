#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
class merge
{
	node* head;
public:
	merge()
	{
		head = NULL;

	}
	node* insert(int val)
	{
		node *temp = new node;
		temp->data = val;
		temp->next = head;
		head = temp;
		return head;
	}
	void display()
	{
		node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}


	void merg1(node* root1, node* root2)
	{
		int val;
		node* temp1 = root1;
		node* temp2 = root2;
		while (temp1 != NULL && temp2 != NULL)
		{
			if (temp1->data > temp2->data)
			{
				val = temp2->data;
				temp2 = temp2->next;
			}
			else
			{
				val = temp1->data;
				temp1 = temp1->next;
			}
			 insert(val);
		}
		while (temp1 != NULL)
		{
			insert(temp1->data);
			temp1 = temp1->next;
		}
		while (temp2 != NULL)
		{
			insert(temp2->data);
			temp2 = temp2->next;
		}
		display();
	}
};
int main()
{
	merge obj1, obj2;
	node* ptr1 = NULL;
	node* ptr2 = NULL;
	int n, data;
	cout << "how many number you want to add in list 1\n";
	cin >> n;
	cout << "Enter the value :  \n";
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		ptr1=obj1.insert(data);
	}
	cout << "The  list 1 :  " << endl;
	obj1.display();
	cout << endl;
	cout << "how many number you want to add in list 2 \n";
	cin >> n;
	cout << "Enter the value :  \n";
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		ptr2=obj2.insert(data);
	}
	cout << endl;
	cout << "The  list 2 :  " << endl;
	obj2.display();
	cout << endl;
	cout << "list after merge in assending order : " << endl;
	obj2.merg1(ptr1,ptr2);
}

