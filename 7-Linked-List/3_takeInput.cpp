// THIS CODE HELPS US TO TAKE INPUT ELEMENTS OR THE ELEMENTS IN A LINKED LIST IN A VERY EASY WAY...JUST LIKE WE DID IN ARRAY :)      ( SPACE SEPARATED INTEGERS)

// "node* takeInput()"  is an interesting function which helps us take input... here we fill the 


#include<iostream>
#include "Node.cpp"         //Node.cpp is my previously coded file which contains the class "node"
                            // U CAN CALL THIS TO SAVE TIME OR U CAN SIMPLY WRITE THE CODE OF "Node.cpp" each time u want to use it

using namespace std;

node* takeInput()
{
    cout<< "Enter data : ";
    int data;
    cin>>data;
    node * head= NULL;
    while(data != -1)
    {
        node* newNode = new node(data);         //WE HAVE MADE THIS "newNode" dynamically so that the 
                                                // so that the previously created node continues to exist even after coming out of this while loop :)
        if(head == NULL)
        {
            head = newNode;
        }

        else
        {
            node* temp= head;// HERE, WE R GOING TO NEED TO USE "head" ...but we are not going to use it....(bcoz we don't want to lose our head....or don't want the head variable to point somewhere else...so we r going to use a copy of the head variable called "temp" which will traverse in the linked list)

            while(temp->next != NULL){temp= temp->next;}
            temp->next = newNode;
        }
        cin>>data;
        
    }

    return head;
}

void print(node *head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout<< temp->data <<endl;
        temp= temp->next;
    }
} 



int main(){
    node * head = takeInput();
    print(head);

    return 0;
}