// WE ARE GIVEN 2 ARRAYS, AND WE HAVE TO PRINT THE INTERSECTION OF THE TWO ARRAYS
// WE ARE GOING TO SOLVE THIS PROBLEM BY 4 METHODS, BY EACH METHOD OUR TIME COMPLEXITY WILL BE BETTER

// ONLY FIRST METHOD IS DISCUSSED HERE , OTHERS ARE IN THE FOLLOWING FILES...

// METHOD-1 : WE PICK ONE ELEMENT FROM FIRST ARRAY, AND CHECK IF THE SAME ELEMENT IS PRESENT IN THE SECOND ARRAY OR NOT, IF IT IS PRESENT, THEN WE ADD THAT ELEMENT IN THE "INTERSECTION ARRAY", WHICH IS A THIRD EMPTY ARRAY

// NOTE: IN THIS METHOD YOU CAN TACKLE DUPLICATE ELEMENTS ALSO, (AN ELEMENT MUST BE PRESENT TWICE IN BOTH ARRAYS TO COME TWICE IN THE "INTERSECTION ARRAY")     HERE, ONCE AN ELEMENT IS TALLIED, WE WILL TURN THAT ELEMENT IN "ar2" to "-1" so that it cannot tally to a repitition of the same no. in "ar1"


// SINCE 2 nested for loops of size n1 and n2 are being used, TIME COMPLEXITY = O(n1*n2)

#include<iostream>
#include<cmath>
using namespace std;


int intersect1(int ar1[],int ar2[],int arr[], int n1, int n2)
{
    int k=0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if(ar1[i] == ar2[j])
            {
                arr[k]= ar1[i];
                k++;
                ar2[j] = -1;
            }
        }
    }
    return k;
}


int main(){
    int ar1[]= {1,3,6,9,12,15,18,21,24,27,30};
    int ar2[]= {1,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30};
    int n1= sizeof(ar1)/4;
    int n2= sizeof(ar2)/4;
    int arr[n1+n2];


    int count = intersect1(ar1,ar2,arr,n1,n2);      //Intersect1 has a time complexity  => O(n1 * n2) ...there are ways to code it with better time complexity below...(this is the most simple/lay man's code)
    for (int i = 0; i < count; i++)
    {
        cout<<arr[i]<<"  ";
    }
    

    return 0;
}