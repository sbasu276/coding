/*	Given only a pointer to a node, delete it

	Test cases: 
		3 nodes 
		ptr=head / ptr=head->next / ptr=head->next->next(tail)
		ptr=NULL(uninitialized list)
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

// Called with reference. Else this solution won't work for ptr=tail.
void deleteNode(LL* &ptr)
{
	if(ptr==NULL || ptr->next==NULL) /*ptr points to empty list or the last node*/
	{
		ptr=NULL;
		return;
	}
	//copy data value of next node and delete the next node
	LL* temp=ptr->next;
	ptr->data=temp->data;
	ptr->next=temp->next;
	free(temp);
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
	
	deleteNode(list);
	//deleteNode(list->next->next); //last node
	//deleteNode(list->next);	// middle node
	
	for(LL *i=list ; i ; i=i->next)
		cout<<i->data<<" ";
		//cout<< "("<<i<<"," << i->next <<")" <<" ";
	cout <<"\n";
	
return 0;
}
