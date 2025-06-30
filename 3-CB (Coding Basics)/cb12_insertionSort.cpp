//INSERTION SORT: HERE WE FIRST IGNORE THE FIRST ELEMENT ;; THEN COMPARE SECOND ELEMENT WITH 1-ST AND INSERT THE SECOND ELEMENT IN THE RIGHTFUL POSITION THEN WE PICK THE 3-RD ELEMENT AND PLACE IT IN THE RIGHTFUL POSITION (AFTER COMPARING IT WTIH THE FIRST TWO ELEMENTS :)

#include<iostream>
#include<cmath>
using namespace std;
void Isort(int arr[],int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        for (int j = i-1; j >=0; j--)
        {
            if(current<arr[j])
            {
                arr[j+1]= arr[j];
                arr[j]=current;
            }
        }
    }
}


int main(){

    int n=8;
    int arr[8]={10,5,3,15,2,7,11,99};
    Isort(arr,n);
    for (int i = 0; i < 8; i++)
    {
        cout<< arr[i] <<" ";
    }
    return 0;
}