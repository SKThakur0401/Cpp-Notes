// HERE, I HAVE RE-WRITTEN CODES FOR ALL THE PROGRAM FROM "TAKE INPUT" FUNCTION TILL MERGE SORT..... SINCE THESE ARE WRITTEN AFTER COMPLETING "LL" SOME OF THESE CODES ARE BETTER THAN THEIR COUNTER-PARTS IN SEPARATE FILES...

#include<iostream>
#include "Node.cpp"
using namespace std;

class Pair
{
    public:
    node* head;
    node* tail;
    Pair(node* h, node* t)
    {
        head=h;tail=t;
    }
};

node* takeInput()
{
    int data; cin>>data;
    node* head = NULL;
    node* tail = NULL;
    while(data != -1)
    {
        node* newNode = new node(data);
        if(head== NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;;
            tail= newNode;
        }
        cin>>data;
    }
    return head;
}

void print (node* head)
{
    node* temp= head;
    while(temp != NULL)
    {
        cout<< temp->data <<"  ";
        temp= temp->next;
    }
    cout <<endl;
}

node* insert(int index,int element, node* head)
{
    if(index ==0)
    {
        node* newNode= new node(element);
        newNode->next= head;
        head= newNode;
        return head;
    }
    else
    {
        node* temp= head;
        int i=0;
        while(i < index-1   && temp != NULL)
        {
            temp=temp->next;
            i++;
        }
        if(temp != NULL)
        {
            node* newNode= new node(element);
            newNode->next= temp->next;
            temp->next = newNode;
            return head;
        }
    }
}

int len(node* head)
{
    if(head == NULL){return 0;}
    return 1 +len(head->next);
}

node* delRec(int index, node* head)
{
    if(index == 0)
    {
        node* a = head;
        head=head->next;
        delete [] a;
        return head;
    }
    else if(index== 1)               // 1 2 3 4 5 
    {
        node* a = head->next;
        head->next = head->next->next;
        delete [] a;
        return head;
    }

    head->next=delRec(index-1, head->next);
    return head;
}

node* dupify(node* head)
{
    node* temp= head;
    while(temp->next != NULL)
    {
        if(temp->data ==  temp->next->data)
        {
            node* a = temp->next;
            temp->next = temp->next->next;
            delete [] a;
        }
        else
        {
            temp=temp->next;
        }
    }
    return head;
}

node* reverse(node* head)
{
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    while(currptr != NULL)
    {
        nextptr= currptr->next;
        currptr->next= prevptr;
        prevptr= currptr;
        currptr=nextptr;
    }
    return prevptr;
}

node* rec_reverse(node* head)
{
    if(head == NULL || head->next == NULL){return head;}
    
    node* smallAns = rec_reverse(head->next);
    node* tail = smallAns;
    while(tail->next != NULL){tail= tail->next;}    //This line is making the TC= O(n^2) ...otherwise it could have been O(n) if we didn't had to put in efforts to find out tail
    tail->next = head;
    head->next = NULL;
    return smallAns;
}

Pair rec_reversePro(node* head)
{
    if(head== NULL || head->next == NULL){Pair ans(head,head); return ans;}

    Pair smallAns = rec_reversePro(head->next);
    smallAns.tail->next = head;
    head->next = NULL;
    smallAns.tail = smallAns.tail->next;

    return smallAns;
}

node* rec_reversePro_nodified(node* head)
{
    return rec_reversePro(head).head ;
}

node* rec_reverseProMax(node* head)
{
    if(head == NULL || head->next == NULL){return head;}
    
    node* smallAns = rec_reverse(head->next);
    node* tail = head->next;
    tail->next = head;
    head->next = NULL;
    return smallAns;
}

bool chk_pal(node* head)   // returns "1" for palindrones
{
    int l2 = len(head);
    int l = ( l2 -1)/2;
    node* temp = head;
    for (int i = 0; i < l; i++)
    {
        temp=temp->next;
    }
    node* h2= temp->next;
    temp->next = NULL;
    h2= rec_reverseProMax(h2);
    while(head->next != NULL && h2->next !=NULL)
    {
        if(head->data != h2->data){return false;}
        head=head->next; h2= h2->next;
    }
    return true;
}

node* merger(node*h1, node* h2)     
{
    node* head= new node(69);
    node* tail= head;
    while(h1 != NULL && h2 != NULL)
    {
        if(h1->data < h2->data)
        {
            node* newNode = new node(h1->data);
            tail->next= newNode;
            tail=tail->next;
            h1=h1->next;
        }

        else if(h1->data > h2->data)
        {
            node* newNode = new node(h2->data);
            tail->next= newNode;
            tail=tail->next;
            h2=h2->next;
        }
        else if(h1->data == h2->data)
        {
            node* newNode = new node(h2->data);
            tail->next= newNode;
            tail=tail->next;
            h2=h2->next;

            newNode = new node(h1->data);
            tail->next= newNode;
            tail=tail->next;
            h1=h1->next;
        }
    }
    while(h1 != NULL)
    {
        node* newNode = new node(h1->data);
        tail->next= newNode;
        tail=tail->next;
        h1=h1->next;
    }
    while(h2 != NULL)
    {
        node* newNode = new node(h2->data);
        tail->next= newNode;
        tail=tail->next;
        h2=h2->next; 
    }
    node* a= head;
    head= head->next;
    delete [] a;
    return head;
}

void merge_with_Return_type_void_storing_merged_LL_in_h1(node* &h1, node* h2)
{
    node* head= new node(69);
    node* tail= head ;

    while(h1 != NULL && h2 != NULL)
    {
        if(h1->data < h2->data)
        {
            node* newNode = new node(h1->data);
            tail->next= newNode;
            tail=tail->next;
            h1=h1->next;
        }

        else if(h1->data > h2->data)
        {
            node* newNode = new node(h2->data);
            tail->next= newNode;
            tail=tail->next;
            h2=h2->next;
        }
        else if(h1->data == h2->data)
        {
            node* newNode = new node(h2->data);
            tail->next= newNode;
            tail=tail->next;
            h2=h2->next;

            newNode = new node(h1->data);
            tail->next= newNode;
            tail=tail->next;
            h1=h1->next;
        }
    }
    while(h1 != NULL)
    {
        node* newNode = new node(h1->data);
        tail->next= newNode;
        tail=tail->next;
        h1=h1->next;
    }
    while(h2 != NULL)
    {
        node* newNode = new node(h2->data);
        tail->next= newNode;
        tail=tail->next;
        h2=h2->next; 
    }
    node* a= head;
    head= head->next;
    delete [] a;
    h1= head;
}

void Msort(node* &head)
{
    if(head->next == NULL){return;}
    else
    {
        int l = len(head);
        node* temp = head;
        for (int i = 0; i < (l-1)/2; i++)
        {
            temp=temp->next;
        }
        node* head2 = temp->next;
        temp->next =NULL;
        Msort(head);
        Msort(head2);
        merge_with_Return_type_void_storing_merged_LL_in_h1(head,head2);
    }
    
}

int main()
{
    node* head= takeInput();
    Msort(head);
    print(head);

    return 0;
}