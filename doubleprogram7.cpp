#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next,*prev;
};
class merge
{
	node* head;
public:
	merge()
	{
		head = NULL;
	}
	node * insert(int data)
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
			return head;
	};

	void display(node* head)
	{
		node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	node* merg1(node* root1, node* root2)  //merge and sort the two sorted list 
	{
		node* temp = NULL, * return_d = NULL;
		if (root1->data <= root2->data)
		{
			temp = root1;
			root1 = temp->next;
		}
		else
		{
			temp = root2;
			root2 = temp->next;
		}
		return_d = temp;
		while (root1 != NULL && root2 != NULL)
		{
			if (root1->data <= root2->data)
			{
				temp->next = root1;
				temp = root1;
				root1 = temp->next;
			}
			else
			{
				temp->next = root2;
				temp = root2;
				root2 = temp->next;
			}
		}
		if (root1 == NULL)
		{
			temp->next = root2;
		}
		if (root2 == NULL)
		{
			temp->next = root1;
		}
		return return_d;
	}

};
int main()
{
	merge obj1, obj2, obj3;
	node* ptr1 = NULL;
	node* ptr2 = NULL;
	int n, data;
	cout << "how many number you want to add in list 1\n";
	cin >> n;
	cout << "Enter the value : \n";
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		ptr1 = obj1.insert(data); //the data of list 1
	}
	cout << "The list 1 : " << endl;
	obj1.display(ptr1);
	cout << "\n";
	cout << endl;
	cout << "how many number you want to add in list 2 \n";
	cin >> n;
	cout << "Enter the value : \n";
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		ptr2 = obj2.insert(data); //the data of list 2
	}
	cout << endl;
	cout << "The list 2 : " << endl;
	obj2.display(ptr2);
	cout << endl;
	cout << "list after merge : " << endl;
	node* list = obj2.merg1(ptr1, ptr2); //store the merge  list
	obj2.display(list); //display merge list 
	cout << "\n";
	system("pause");
}
