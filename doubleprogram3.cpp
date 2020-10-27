#include<iostream>
using namespace std;
struct node
{
	int data;
	node* prev, * next;
};
class dublicate
{
	node* head;
public:
	dublicate()
	{
		head = NULL;
	}
	void insert(int data)
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
	int prime_check(int num) //function to check prime number 
	{
		if (num == 0 || num == 1)
		{
			return false;
		}
		else
		{
			for (int i = 2; i <= num / 2; i++)
			{
				if (num % i == 0)
				{
					return false;
					break;
				}
				else
				{
					return true;
				}

			}
		}
		
	}
	int product()
	{
		int prime=1;
		node* temp = head;
		while (temp != NULL)
		{
			if (prime_check(temp->data))
			{
				prime = prime * temp->data;
			}
			temp = temp->next;
		}
		return prime;
    }
};
int main()
{
	dublicate obj;
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
	cout << "Number you Entered \n";
	obj.display();
	int prod = obj.product();
	cout << "\nproduct of prime number nodes  : " << prod<<"\n\n";
	system("pause");
}
