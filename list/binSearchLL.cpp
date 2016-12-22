/* Binary search in Linked List */
#include<iostream>
#include<cstdlib>
using namespace std;


typedef struct ll {
	int data;
	struct ll* next;
}node;

node * middleNode(node * head, node *tail)
{
	if(head==NULL)
	{
		return NULL;
	}

	node *fast_p,*slow_p;
	slow_p = head;
	fast_p = head->next;
	while(fast_p !=tail)
	{
		fast_p = fast_p->next;
		if(fast_p !=tail)
		{
			fast_p = fast_p->next;
			slow_p = slow_p->next;
		}
	}
return slow_p;
}

node * binSearch(node * head, int key )
{
	node *start = head;
	node *end = NULL;

	do
	{
		node *middle = middleNode(start,end);

		if( middle == NULL )
		{
			return NULL;
		}

		if( middle->data == key )
		{
			return middle;
		}
		else if ( middle->data < key )
		{
			start = middle->next; 
		}
		else
		{
			end = middle;   
		}

	}while( end == NULL || end != start );

	if(start->data == key)
		return start;
// data not present
return NULL;
}


node * push_back( node * head, int val)
{
	node *tmp = (node*)malloc(sizeof(node));
	if(tmp==NULL)
	{
		cout<<"Error creating node";
		return head;
	}
	tmp->data = val;
	tmp->next = NULL;
	if(head==NULL)
	{
		head = tmp;
		return head;
	}
	node *i;
	for(i=head;i->next;i=i->next);
		i->next = tmp;
	return head;
}



// driver main
int main()
{
	node * head = NULL;
	// create list
	int size;
	cin >> size;
	for(int i=1;i<=size;i++)
		head = push_back(head,(i*10));

	for(node*i=head ; i ; i=i->next)
		cout<<i->data<<" ";
	cout<<"\n";
	int key;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> key;
		node *res = binSearch(head,key);
		if(res)
			cout << key <<" FOUND" <<endl;
		else
			cout << key << " NOT FOUND" <<endl;
	}
return 0;
}

/*
Test Cases:
----------
Input Format:
First Line: Number of elements in list	(N)
Second Line: Number of Queries		(K)
Third Line: Keys to be searched


1)	3
	7
	8 10 13 20 26 30 90

2)	2
	5
	-1 10 11 20 67

3)	1
	3
	3 10 18

4)	0
	2
	-10 8

*/

