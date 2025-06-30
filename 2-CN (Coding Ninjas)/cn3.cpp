#include<iostream>
#include<cmath>
using namespace std;


int main(){

    int arr[5]={23,5,6,4,35};
    
    cout<<arr<<endl; //THIS ACTUALLY GIVES --> ADDRESS OF 1st ELEMENT OF ARRAY :) ,,, SAME AS ---> &(arr[0]) ;;;; TO BE HONEST, WHEN WE TYPE "cout<<&(arr[0]);" THE COMPILER ACTUALLY DOES "cout<<arr;"
    cout<<&arr[1]<<endl;
    cout<<arr+1<<endl;          // when you type "&arr[1]" , the compiler actually does "arr+1", i.e. , the address next to address of arr or (&arr[0])
 
    //  &arr[i] = arr+i                     OR              //  arr[i] = *(arr+i)     ####THIS IS ALWAYS TRUE!!!!


    cout<< arr <<endl;
    cout<< &arr <<endl;         //VERY INTERESTING, "arr" and "&arr" gives the same result ,,,i.e. address of first term of array ....NOTE : sizeof(arr)=20   ,,,but   sizeof(&arr) = 8
    cout<<"Value of *(&arr) is : "<< *(&arr) <<endl;        // HERE, "*" AND "&"" ARE CROSS-CUTTING EACH OTHER GIVING A PROPER --> "arr" ,,, i.e. arr with size= 20 :)
    
    int* ptr = arr;
    cout<< ptr <<endl;          //THIS WILL GIVE SAME RESULT AS "arr"
    cout<< &ptr <<endl;         //BUT THIS WILL NOT GIVE SAME RESULT AS "&arr"..... "&ptr" will give u the address, where the pointer "ptr" is stored :)

    cout<< sizeof(arr) <<endl;     // 20
    cout<< sizeof(&arr)<<endl;     // 8
    cout<< sizeof(ptr)<<endl;      // 8
    cout<< sizeof(&ptr)<<endl;     // 8        SO YOU SEE, "arr" is a pointer pointing to the entire array,,, it has the size of entire array ; and "&arr" / "ptr" / "&ptr"  just like any other pointer are of 8-bits, bcoz they are simply pointing to the location of one integer or one pointer :)




//  arr=arr+2;  // arr++ (it is arr= arr +1)      //ILLEGAL MOVE, WILL THROW ERROR.... HOWEVER,,,THE CODE BELOW WILL NOT
    int* p=arr;
    p=p+2;
    cout<< p <<endl;    //result is exactly 8-bit ahead of address of "arr" , since we did "p=p+2;"

    return 0;
}

// So, an array pointer is not just any pointer...it has some of it's own properties....like its size = (no. of element) * sizeof(data-type of each element)

// int arr[5] = {1,2,3,4,5};      it has size= 20,  and doing "arr=arr+1" will throw error!!!...bcoz its not normal integer pointer

// Unlike normal pointers ...."&arr" will return the same answer/value as "arr" ...

// sizeof(arr) = 20 ,  but... sizeof(&arr) = 8... so they r not the same either!!!