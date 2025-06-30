// NOW, WE ARE GOING TO WRITE A BETTER CODE FOR THE SAME THING...

// IT COULD HAVE BEEN "O(n)" if we could have avoided the use of "while loop" .... well we have faced a similar problem earlier....while creating the "takeInput" function.... we avoided the use of while loop by using a tail pointer which "remembered" where next elemented should be connected.. instead of running the loop from begining again and again everytime...we can use "tail" :)

// HOWEVER THE RECURSIVE CALL RETURNED ONLY ONE "NODE" WHICH HAS TO BE HEAD... AND THERE IS NO FUNCTION IN THE WORLD WHICH RETURNS "TWO OBJECTS" SO THERE WAS NO WAY TO RETURN "TWO NODE POINTERS" .... 

// SO WE DID A SMART THING... WE CREATED A NEW DATA TYPE... CALLED THE "Pair" ...which held two node pointers... "head" and "tail" .... and we made the return type of "reversePro" function as "Pair"!!! so now we can get both head and tail as return value at the same time!!!!
 
#include<iostream>
#include "Node.cpp"
using namespace std;

class Pair          //Note: "pair" is a keyword..will give error, so use "Pair"
{
    public:
    node* head;
    node* tail;
    Pair(node*head, node*tail): head(head), tail(tail){}    // our constructor which takes two arguments 
                                                            // head and tail
    Pair(){}
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

int len(node* head)
{
    node* tail = head;
    int len=1;
    while (tail->next != NULL)
    {
        tail= tail->next;
        len++;
    }
    return len;
}


Pair reversePro(node* head)
{
    if(head ==NULL || head->next == NULL ){ Pair ans(head,head); return ans; }

    Pair smallAns= reversePro(head->next);

    smallAns.tail->next=head;
    head->next = NULL;
    smallAns.tail= head;

    return smallAns;
}

// However, the return type of "reversePro" is "Pair" ,,, and main function is asking for a "node" only......(a node pointing to the head of the linked-list)
// so, we can simply create a function which returns the "head" value of the output of "reversePro" and ignore the tail...(thats simple)

node* reversePro_nodifier(node*head)        //here "nodifier" is added coz it returns a node (head (to be specific))...which it extracts from a "Pair"
{
    return reversePro(head).head;
}

int main(){

    node* head= takeInput();

    head= reversePro_nodifier(head);
    print(head);

    return 0;
}