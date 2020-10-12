#include<iostream>
using namespace std;
struct node
{
	int data;
	node* NEXT;
};
class palidrome
{
	int size;
	node* heading;
	node* tail;
public:
	palidrome()
	{
		tail = NULL;
		size = 0;
		heading = NULL;
	}
	void push1(int data)
	{
		node* temp = new node;
		temp->data = data;
		temp->NEXT = NULL;
		if (heading == NULL)
		{
			heading = temp;
		}
		else
		{
			temp->NEXT = heading;
			heading = temp;
		}
	};
	int pop1()
	{
	
	 int p = heading->data;
	 node* pop = heading;
	 heading = heading->NEXT;
	 delete pop;
		return heading->data;
	};
	void  push2(int data)
	{
		node *temp = new node;
		temp->data = data;
		temp->NEXT = NULL;
		if (heading == NULL)
		{
			tail = temp;
			heading = temp;
		}
		else
		{
			tail->NEXT = temp;
			tail = temp;
		}
	};
	int pop2()
	{
		int del;
		node* ptr = heading;
		del = ptr->data;
		heading = heading->NEXT;
		delete (ptr);
		return  heading->data;
	}
		void check_palidrome(palidrome obj1,palidrome obj2)
		{
			if (obj1.pop1() != obj2.pop2())
			{
				cout << "it is not palidrome \n";
			}
			else
			{
				cout << "it is palidrome \n";
			}
			

		}
};
	int main()
	{
		palidrome obj, obj1,obj2;
		int data, n;
		cout << "Enter the number of data you want to add \n";
		cin >> n;
		cout << "Enter the data to check if it is palidrome or not \n";
		for (int i = 0; i < n; i++)
		{
			cin >> data;
			obj.push1(data);
			obj1.push2(data);
		}
		obj2.check_palidrome(obj,obj1);
		return 0;
	}