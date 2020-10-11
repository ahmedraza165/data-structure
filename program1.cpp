//deleteing the element from single link list who's sum is equal to zero
#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};
class del_element
{
	node *temp;
	node* head;
public:
	del_element()
	{
		temp = NULL;
		head = NULL;
	}
	void push(int data)
	{
		temp = new node;
		temp->data = data;
		temp->next = head;
		head = temp;
	}
	void delete_element()
	{
        node* check1 = head;
        node* check2;

        while (check1 != NULL)
        {
            bool MODE = false;
            int sum = 0;
            check2 = check1;
            while (check2 != NULL)
            {
                sum = sum + check2->data;
                if (sum == 0)
                {
                    check1 = check2;
                    MODE = true;
                    break;
                }
                else
                {
                    check2 = check2->next;
                } 
            }
            if (MODE == false)
            {
     
                cout<<"\n"<<"the element remmaining (sum is not zero)  : "<<check1->data;
            }
       
            check1 = check1->next;
        }

	}
};
int main()
{
    del_element obj;
    int data,n;
    cout << "Enter the number of element you want to add in link list \n";
    cin >> n;
    cout << "Enter the element : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        obj.push(data);
    }
    obj.delete_element();
    cout << endl;

    system("pause");
    return 0;
}

