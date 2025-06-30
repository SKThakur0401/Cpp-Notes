// Chapter Assignment
// Problem Statement: Even after Odd LinkedList
// Problem Level: MEDIUM
// Problem Description:
// For a given singly linked list of integers, arrange the elements such that all the even numbers are placed after the odd numbers. The relative order of the odd and even terms should remain unchanged.
// So, all odd nos. with respect to each should remain in same order.... similarly, all even nos. with respect to each other should remain in same order

// Sample Input 2 :
// 1 11 3 6 8 0 9 -1
// 10 20 30 40 -1

// Sample Output 2 :
// 1 11 3 9 6 8 0
// 10 20 30 40

// Solution:

// Ohead == Odd-head (head of linked-list with odd elements)
// Ehead == Even-head (head of linked-list with even elements)....same nomenclature for tail
// TO SOLVE THIS... WE R CUSTOMIZING THE "takeInput" function... by using "Ohead, Otail , Ehead, Etail" insteand of just "head and tail" ...so that we can insert odd and even elements in 2 separate linked list in the required order... and then attaching the tail of odd to the head of even..giving us the answer :)

#include<iostream>
#include "Node.cpp"
using namespace std;

node* takeInput()
{
    int data; cin>>data;
    node* Ohead= NULL;
    node* Ehead= NULL;
    node* Otail= NULL;
    node* Etail= NULL;
    while(data != -1)
    {
        node* newNode = new node(data);
        if(newNode->data  %2 == 0)
        {
            if(Ehead== NULL){Ehead=newNode; Etail=newNode;}
            else
            {
                Etail->next= newNode;
                Etail= Etail->next;
            }
        }
        else
        {
            if(Ohead== NULL){Ohead=newNode; Otail=newNode;}
            else
            {
                Otail->next= newNode;
                Otail= Otail->next;
            }
        }
        cin>>data;
    }
    if(Otail != NULL)           // To handle the case where there is no "odd" elements in the LL
    {
        Otail->next= Ehead;     // this line would have given error in LL with no odd elements, but we
        return Ohead;           // handled it :)
    }
    else
    {
        return Ehead;           // since this is case with no odd elements...returning "Ehead" is answer
    }
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


int main(){

    node* head= takeInput();
    print(head);
    

    return 0;
}