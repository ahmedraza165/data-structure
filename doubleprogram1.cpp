#include<iostream>
using namespace std;
struct node
{
	int data;
	node* prev, * next;
};
class double_link
{
	int size;
	node* head;
	node* tail;
public:
	double_link()
	{
		size = 0;
		head = NULL;
	}
	void insert(int data)
	{
		node* temp = new node;
		temp->data = data;
		temp->prev = NULL;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			head->prev = temp;
			temp->next = head;
			head = temp;
		}

	};
	void del_element()
	{
		int num;
		bool found = false;
		node* temp = head;
		cout << "Enter the Number you want to delete \n";
		cin >> num;
		if (head == NULL)
		{
			cout << "link list is Empty\n";
		}
		if (head == tail)
		{
			tail = NULL;
		}
		while (temp != NULL)
		{
			if (num == temp->data)
			{
				temp = head->next;
				head->next = temp->next;
				found = true;
				cout << "Number has been delete \n";
				temp = NULL;
				delete(temp);
				break;
			}
			temp = temp->next;
		}
		if (found == false)
		{
			cout << "Number Not Found \n";
		}
		size--;
	};
	void is_empty()
	{
		if (head != NULL)
		{
			cout << "double link list is Not empty \n";
		}
		else
		{
			cout << "List Empty\n";
		}

	};
	void is_full()
	{
		cout << "LINK LIST Never full \n";
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
	double_link obj;
	int n;
a:	cout << "Press 1 To insert the data \n";
	cout << "Press 2 To delete the data \n";
	cout << "Press 3 To check if it is empty \n";
	cout << "Press 4 To check if it is full \n";
	cout << "Press 5 To Display \n";
	cout << "Press 6 To exit\n";
	cin >> n;
	if (n == 1)
	{
		int x;
		cout << "Enter the number of data you want to add \n";
		cin >> x;
		int data;
		cout << "Enter Data to insert\n";
		for (int i = 0; i < x; i++)
		{
			cin >> data;
			obj.insert(data);
		}
		goto a;
	}
	if (n == 2)
	{
		obj.del_element();
		goto a;
	}
	if (n == 3)
	{
		obj.is_empty();
		goto a;
	}
	if (n == 4)
	{
		obj.is_full();
		goto a;
	}
	if (n == 5)
	{
		obj.display();
		goto a;
	}
	if (n == 6)
	{
		exit;
	}
	if (n > 6 || n < 1)
	{
		cout << "\nWrong Input\n";
		goto a;
	}
	system("pause");
}
