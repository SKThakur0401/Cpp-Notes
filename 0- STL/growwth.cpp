#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class myClass{
    public:

    node* head;
    node* tail;

    unordered_map<int, node*> um;

    void insert(pair<int, int> pi){

        if(head == null){
            head = new node
            head->data = pi;
            tail = head;
            um[pi.first] = NULL;
            return;
        }
        
        node* prev = tail;
        tail->next = new node;
        tail->next->data = pi;
        tail = tail->next;
        um[tail->data.first] = prev;
    }

    void delete(int key){
        node* prevNode = um[key];

        if(prevNode == NULL){
            node* temp = head;
            head = head->next;
            delete [] temp;
            // if(head->next) head->next = head->next->next;
            
            um[key];
        }

        else{
            node* to_delete = prevNode->next;
            prevNode->next = prevNode->next->next;
            delete [] to_delete;
        }
    }

    void print(int key){
        
        node* temp = head;
        while(temp){
            cout<< temp->data.first<< " - "<< temp->data.second <<endl;
            temp=temp->next;
        }
    }
}

class node{
    public:
    pair<int, int> data;
    node* next;
};

// 2 -> 3 -> 4 -> 5 -> 2 -> 3 -> NULL

// um[3] =

// um[key -> what you want to delete] ---- > node* (address of the previous node)

int main(){

    node* head = new node;

    head->data = 1;
    tail->next = new node;
    tail->next->data = 2;
    tail = tail->next
    

    return 0;
}

