//MERGING SORTED ARRAYS:    TWO SORTED ARRAYS "ar1" and "ar2"  ARE TO BE MERGED IN "ar3" ARRAY ;;; SUCH THAT "ar3"  IS ALSO A SORTED ARRAY :)

 

#include<iostream>
#include<cmath>
using namespace std;

void Merge(int ar1[],int ar2[], int n1 , int n2, int arr[])
{
    int i=0, j=0,k=0;
    while(i<n1 && j< n2)
    {
        if(ar1[i]< ar2[j]){arr[k]=ar1[i]; k++; i++;}
        else if(ar1[i]> ar2[j]){arr[k]=ar2[j]; k++; j++;}
        else if(ar1[i] == ar2[j]){arr[k]=ar1[i];k++; i++; arr[k]=ar2[j]; k++; j++;}
    }

                            //LOOK AT THE WHILE LOOP ABOVE,,, THAT WILL ONLY TERMINATE IF EITHER ONE OF THE ARRAYS IS "EMPTIED" SO AFTER THAT EITHER "i" or "j" will be surviving candidates SO EITHER ONE OF THE LOOPS BELOW WILL COME INTO ACTION    

    while(i<n1) 
    {
        arr[k]=ar1[i]; k++; i++;
    }
        while(j<n2)
    {
        arr[k]=ar2[j]; k++; j++;
    }
}


int main(){
    int ar1[]={0,2,4,6,8,10,12,13,14,15,16};
    int ar2[]={1,3,5,7,9,11,13,15,17};
    int n1 = sizeof(ar1)/4;
    int n2 = sizeof(ar2)/4;
    int arr[n1+n2];             //THE ARRAY IN WHICH WE MERGE THE TWO ARRAYS :) OFCOURSE, IT'S SIZE WILL BE SUM OF SIZES OF ar1 and ar2
    Merge( ar1 , ar2, n1, n2, arr );

    for (int i = 0; i < n1+n2; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}




//A LESSER ORGANISED CODE FOR SAME IS WRITTEN BELOW....


// #include<iostream>
// #include<cmath>
// using namespace std;

// void sort(int ar1[],int ar2[], int ar3[], int n1, int n2, int n3)
// {
//     int i=0;
//     int j=0;
//     int k=0;
//     for (int k = 0; k < n3; k++)
//     {
//         if(i== n1){ar3[k]=ar2[j]; j++;}
//         else if(j== n2){ar3[k]=ar1[i]; i++;}
//         else if(ar1[i]< ar2[j]  && i< n1  && j< n2)
//         {
//             ar3[k]=ar1[i];
//             i++;
//         }
//         else if(ar1[i]> ar2[j]  && i< n1  && j< n2)
//         {
//             ar3[k]=ar2[j];
//             j++;
//         }
//     }
// }
// int main(){
//     int n1,n2,n3;
//     int ar1[]={1,9,10,12,43,44,45,47,48};
//     n1= (sizeof(ar1))/4;
//     int ar2[]={2,6,15,20,40,41,42,46,49};
//     n2= (sizeof(ar2))/4;
//     int ar3[n1+n2];
//     n3= n1+n2;
//     sort(ar1,ar2, ar3,n1,n2,n3);
//     for (int i = 0; i < n3; i++)
//     {
//         cout<<ar3[i]<<" ";
//     }
//     return 0;
// }