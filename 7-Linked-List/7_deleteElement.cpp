// WE CREATED A PROGRAM "del" which deletes the particular index elements that the user demands...however when called for index-0...it deleted index-1                & when given an index that does not even exist... it gave "segmentation fault" error

// SO WE MADE "del_Pro" which does not have these problems..
// ITS SAME AS "INSERT ELEMENT" AND "INSERT ELEMENT PRO" ... JUST TRY TO DO IT URSELF
 

#include<iostream>
#include "Node.cpp"

using namespace std;


node* takeInput()
{
    int data;
    cin>>data;
    node* head= NULL;
    node* tail= NULL;
    while(data != -1)
    {
        node *newNode = new node(data);
        if(head == NULL){head = newNode; tail= newNode;}
        else
        {
            tail->next=newNode;
            tail= newNode;
        }
        cin>>data;
    }
    return head;
}

void print(node * head)
{
    node* temp= head;
    while(temp != NULL)
    {
    cout<< temp->data <<" ";
    temp=temp->next;
    }
    cout <<endl;
}


void del(int index, node* head)
{
    node* temp = head;
    for (int i = 0; i < index-1; i++)
    {
        temp=temp->next;
    }
    node* a = temp->next;
    temp->next = (temp->next)->next;
    delete [] a;
}

node* del_Pro(int index,node*head)      // NOTE: AFTER WE LEARN TO CREATE DESTRUCTORS, WE WILL NEED TO MAKE SOME SMALL CHANGES IN THIS ALSO... (TRY FIGURING URSELF... . ANSWER: WE WILL NEED TO SET "element->next= NULL" before         "delete element; " the "del_future" has it covered)
{
    if(index == 0)
    {
        node* a = head;
        head= head->next;
        delete [] a;            //TO DELETE THE ELEMENT WE HAVE "OUTCASTED" FROM THE HEAP-MEMORY..WE DONT 
                                // WANT IT TO HOLD UNNECESSARY DATA
        return head;
    }
    else
    {
        node* temp=head;
        int i=0;
        while(i < index-1       &&      temp != NULL)
        {
            temp=temp->next;
            i++;
        }
        if(temp != NULL)
        {
            node* a= temp->next;
            temp->next = (temp->next)->next ;
            delete [] a;                        // DELETING FROM HEAP MEMORY                  
            return head;
        }
    }
}



node* del_future(int ind, node* head)
{
    if(ind==0)
    {
        node* temp = head->next;
        head->next= NULL;
        delete head;

        return temp;
    }

    else
    {
        int i=0; node* temp= head;
        while(i < ind-1 && temp != NULL)
        {
            temp=temp->next;
            i++;
        }

        if(!temp) return head;
        node* fk = temp->next;
        temp->next = fk->next;
        fk->next= NULL;
        delete fk;

        return head;
    }
}



int main(){

    node * head= takeInput();
    print(head);

    head = del_Pro(2,head);
    head = del_Pro(0,head);
    head = del_Pro(3,head);         //NOTE: THIS "INDEX-3" WILL BE REMOVED FROM THE ARRAY OBTAINED AFTER 
                                    // REMOVING INDEX-0  & INDEX-1

    head = del_Pro(21,head);        // IT SUCCESSFULLY IGNORED THIS COMMAND!! WHEN I ENTERED INDEX=21 , 
                                    // FOR A "LL" OF 6 ELEMENTS :)
    // del(2,head);
    // del(0,head);
    // del(10,head);                // THIS GAVE SEGMENTATION FAULT ERROR :( ... OBVIOUSLY WE DID NOT 
                                    // HANDLE THE EXTREME CASES OF "INDEX-0"  AND AN INDEX GREATER THAN THE NUMBER OF ELEMENTS....THAT IS ILLOGICAL INDEX



    print(head);

    return 0;
}
