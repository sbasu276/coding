/*	Middle of a Linked List

	Test cases: 
		0, 1, 2, 3, 4, 5 node(s)

Slow_ptr: Init at head. Moves one at a time.
Fast_ptr: Init at head->next. Moves two node at a time, till not null or not tail. while(Fast_ptr && Fast_ptr->next){...}
when loop stops, slow pointer is the middle.
*/

#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct node {
	int data;
	struct node *next;
}LL;

LL* push_back(LL* head, int val)
{
	LL *tmp = (LL*)malloc(sizeof(LL));
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
	LL *i;
	for(i=head;i->next;i=i->next);
	i->next = tmp;
	return head;
}


void middleNode(LL* head)
{
	if(head==NULL)
	{
		cout<<"Empty\n";
		return;
	}
	
	LL *fast_p,*slow_p;
	slow_p = head;
	fast_p = head->next;
	while(fast_p !=NULL && fast_p->next !=NULL)
	{
		fast_p = fast_p->next->next;
		slow_p = slow_p->next;
	}
	cout<< slow_p->data <<endl;
}

int main()
{
	LL* list = NULL;
	int limit;
	cin >> limit;
	for(int i=1;i<=limit;i++)
		list = push_back(list,(i*rand()%100));
	
	for(LL *i=list ; i ; i=i->next)
		cout<<i->data<<" ";
	cout <<"\n";
	
	middleNode(list);
	
return 0;
}
