#include<iostream>
using namespace std;

int main(){
    int a=69;
    int* j;
    j= &a;      // "&a" gives address of a
            //NOTE: WE ARE MAKING A VARIABLE "k", that will store the "address" of a pointer,,.... to make a pointer, we --> (data type of object whose pointer it is)* (variable i.e. pointer) = (Address of variable towards which it is pointing);
                                                                                                                                        //      int                   *             j           =                   &a;
    

    int** k=&j;        //HERE, DATA TYPE TO WHICH it is pointing is itself a pointer, and pointer is represented by "int*" ,,, looking at the format given a line above,    int*    *   (variable name 'k') = &j;


 
    // * is called dereferencing operator ....if used on a pointer, will give value corresponding to that address.


    cout<<"The address of a is : " << *k <<endl;     //HERE "k" HAS ADDRESS OF "j"...so DEREFERENCING "k" will give VALUE OF "j"
    cout<<"The address of a is : " << j  <<endl;     //VALUE OF j = "address of a" 
    cout<<"The address of a is : " << &a <<endl;


    cout<<"The value of a is : " <<   **k <<endl;
    cout<<"The value of a is : " <<   *j <<endl;
    cout<<"The value of a is : " <<   a <<endl;
    return 0;
}

