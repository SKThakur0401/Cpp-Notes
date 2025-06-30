// QUESTION: FIND THE ELEMENT AT THE MID-POINT OF A LINKED LIST ....(IF THE LINKED LIST IS EVEN..THEN THERE ARE 2 MIDDLE ELEMENT...RETURN THE FIRST ONE)

// FIRST TRY TO SOLVE UR-SELF...ITS AN EASY ONE




// SOLUTION:

// METHOD 1: CALCULATE THE LENGTH OF THE "LINKED LIST", NOW DIVIDE IT BY 2 (FOR ODD NO. OF ELEMENTS, SUBTRACT "1" AFTER DIVIDING BY 2)  AND RUN THE LOOP THAT MANY TIMES TO MOVE AHEAD IN "LL" THEN RETURN THE DATA

// METHOD 2: #BETTER METHOD (always prefer this method coz its time complexity is lesser, some questions will give TLE with method-1 !!)
// WHICH WE R GOING TO CODE HERE.... TAKE 2 POINTERS SLOW(POINTING AT "HEAD") AND FAST(POINTING AT "HEAD->NEXT")  JUMP "SLOW BY 1" AND "FAST BY 2" EACH TIME...TILL THE TIME "fast->next != NULL" (if it gets null...we will get segmentation error... bcoz in each step we will do "fast = (fast->next)->next"  and we know "we can't use this arrow -> on a null object.. it will give error ".  This method is also known as "hare and tortoise" method (tortoise is slow ptr) and (hare is fast ptr).

// remember "arrow" on a null object is a no-no!




#include<iostream>
#include "Node.cpp"
using namespace std;


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

int mid(node* head)
{
    node* slow = head;
    node* fast = head->next;
    while(fast->next->next != NULL)
    {
        slow= slow->next;
        fast= fast->next->next;
    }
    return slow->next->data;
}

int main(){

    node* head= takeInput();
    cout<< mid(head) <<endl;

    return 0;
}