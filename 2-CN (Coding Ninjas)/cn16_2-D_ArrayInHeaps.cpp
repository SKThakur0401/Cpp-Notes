// ---CREATING 2D ARRAY IN HEAP---

#include<iostream>
#include<cmath>
using namespace std;

  
int main(){

    // int a=1,b=2,c=3,d=4,e=5,f=6;     //JUST LIKE AN ARRAY OF INTEGER OR CHAR ,,, IT IS AN ARRAY OF POINTERS
    // int *arr[6]={&a,&b,&c,&d,&e};

    // cout<< **(arr +2)<<endl;         //RETURNS ---> 3


    int **p= new int*[10];

    for (int i = 0; i < 10; i++)
    {
        *(p+i) = new int[20];
    }
    //HOWEVER, WE USE HEAPS SO THAT WE CAN TAKE ARRAY SIZE AS INPUT FROM USER IN RUNTIME :)


    int m,n;
    cout<< "Enter number of rows and column in your 2-D Array : " <<endl;
    cin>>m>>n;
    int **pt=new int*[m];
    for (int i = 0; i < m; i++)
    {
        pt[i]=new int[n];
    }
    //WE CREATED A USER ENTERED 2-D ARRAY OF "m X n" numbers.   NOW,,, IT'S VERY IMPORTANT TO DELETE THIS ARRAY, BCOZ U KNOW, EVEN IF WE COME OUT OF LOOP THIS ARRAY WILL STILL USE UP MEMORY IN THE HEAP
    
    // delete [] pt;    //THIS WOULDN'T HELP!! IT WILL SIMPLY DELETE pt, which is an array of addresses ,,, we first have to delete the "elements" in those addresses
    
    for (int i = 0; i < m; i++)
    {
        delete [] p[i];
    }

    delete [] p;        //NOW AFTER DELETING ALL THE ELEMENTS IN THE ADDRESSES STORED WITHIN "p" , WE CAN HAPPILY DELETE "p" also :)
    return 0;
}

