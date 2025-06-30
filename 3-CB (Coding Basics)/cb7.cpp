#include<iostream>
#include<cmath>
using namespace std;
 
int func_for_array_size(int arr[])      //THIS WILL GIVE A WARNING BCOZ WE DIDN'T TELL THE SIZE OF ARRAY, WE SHOULD TELL THE SIZE OF ARRAY BY USING A SECOND PARAMETER "n" WHICH TELLS THE SIZE OF INTEGER
{
    return sizeof(arr);         //THIS HOWEVER DOES NOT RETURN "400" BUT IT RETURNS "8" BCOZ THE SIZE OF ANY ADDRESS OR POINTER IS "8-BYTES"
                                //SO, WE CANNOT USE "sizeof" TO FIGURE OUT THE SIZE OF THE ARRAY
}
 

int main(){

    int arr[100];
    cout<< sizeof(arr) <<endl;      // THIS WILL RETURN "400" COZ, 100 X 4 = 400 ;
    cout<< func_for_array_size(arr) <<endl;

    return 0;
}