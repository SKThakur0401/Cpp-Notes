//BUBBLE SORTING : (THE ONE I NORMALLY DO) TAKE TO CONSECUTIVE ELEMENTS AND COMPARE ,,, IF THE FORMER IS BIGGER THAN THE LATTER, SWAP THEM

#include<iostream>
#include<cmath>
using namespace std;
 
void bubblesort(int arr[], int n)
{
    for (int i = n-1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if(arr[j]>arr[j+1]){
                int temp= arr[j];
                arr[j]= arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
 

int main(){


    int n=6;
    int arr[6]={10,1,7,9,4,5};
    bubblesort(arr,n);
    for (int i = 0; i < 6; i++)
    {
        cout<< arr[i] <<"  ";
    }
    

    return 0;
}