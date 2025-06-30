//RIGHT TO LEFT FUNCTIONING FINDER,,, JUST LIKE IN PREVIOUS CN-26 ,,, IT'S JUST THAT WE ARE CLEARING THINGS FROM LEFT TO RIGHT ,,, BUT RETURNING THE RIGHT MOST OCCURENCE'S LOCATION

#include<iostream>
#include<cmath>
using namespace std;
int ans= -1;        //WE GAVE INITIAL VALUE "-1" SO THAT IF "ans" COULDN'T ACHIEVE ANY VALUE IN "finder",, it means that element is not there in array, so no index for that case therefore we return -1        //HERE WE USED GLOBAL VARIABLE TO STORE A VARIABLE WHOSE IDENTITY IS MAINTAINED EVEN IF IT GOES OUT OF FUNCTION OR MOVE INTO ANOTHER FUNCTION :)
int finder(int n, int arr[], int x,int adr=0){

    if(*arr == x){ans =adr;}
    if(n==0){return ans;}
    adr++;
    return finder(n-1, arr+1, x, adr);
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int x;
    cin>>x;
    cout<< finder(n,arr,x) <<endl;


    return 0;
}

