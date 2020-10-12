#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
class check_palidrome
{
	node* head;
	node* temp;
public:
	check_palidrome()
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
	}
	bool palindrome()
	{
		node* last = head->next->next;  //last gets this value so we can enter the 
		node* first = head;
		while (first->next != last && first != last)
		{
			last = first;
			while (last->next != NULL)
			{
				last = last->next;
			}
			if (last->data != first->data)
			{
				return false;
			}
			else
			{
				node* first_del = first;
				first = first_del->next;
				delete first_del;


				node* del = last;
				last = NULL;
				delete del;

			}

		}
		if (first->next == last && first->next->data == last->data)
		{
			return true;
		}
		else if (first == last)
		{
			return true;
		}
	}
};
int main()
{
	check_palidrome obj;
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
	if (obj.palindrome() == true)
	{
		cout << "this series is palidrome \n";
	}
	else
	{
		cout << "this series is not palidrome \n";
	}
	system("pause");
	return 0;
}

