#include<iostream>
using namespace std;

class node
{
    public:
    node* prev;
    int data;
    node* next;
    node(int data): data(data){};
};

node* takeInput()
{
    int data;
    cin>>data;
    node* head=NULL;
    node* tail=NULL;
    while(data != -1)
    {
        node* newNode = new node(data);
        if(head==NULL)
        {
            head= newNode;
            tail= newNode;
        }
        else
        {
            tail->next= newNode;
            newNode->prev=tail;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}

void print(node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout<< temp->data <<" ";
        temp=temp->next;
    }
    cout <<endl;
}

void printrev(node* head)
{
    node* tail= head;
    while(tail->next != NULL){tail=tail->next;}

    while(tail != NULL)
    {
        cout<< tail->data <<" ";
        tail=tail->prev;
    }
    cout <<endl;
}

node* reverse(node* head)
{
	if(head==NULL || head->next==NULL) return head;

	node* sA= reverse(head->next);
	node* tail= head->next;
	tail->next=head;
	head->prev=tail;
	head->next=NULL;
	sA->prev= NULL;
	return sA;
}

node* reversek(node* head, int k)
{
	if(head==NULL || head->next==NULL) return head;
	node* temp= head;
	int i=1;
	while(i<k && temp!=NULL && temp->next !=NULL)
	{
		temp=temp->next;
		i++;
	}

	if(temp==NULL || temp->next==NULL)
	{
		head=reverse(head);

		return head;
	}

	node* h2=temp->next;
	temp->next=NULL;
	h2->prev=NULL;
	node* h1= reverse(head);

	node* smallAns =reversek(h2,k);

	head->next= smallAns;
	smallAns->prev= head;

	return h1;
}

int main()
{
	node* head= takeInput();
	head= reversek(head,3);

	print(head);
	printrev(head);

	return 0;
}