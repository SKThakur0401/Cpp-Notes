#include<iostream>
#include<cmath>
using namespace std;
 
void rement(int j, int ar[], int n)
{
    //HERE "sizeof(ar)" will return "8-bytes" bcoz it doesn't actually take the entire array but the address of the first element :)
    cout<< "Size of ar is : "<<sizeof(ar) <<endl;   // INTERESTINGLY, THIS LINE WILL GIVE THE WARNING AS THE THING WRITTEN ABOVE :)
    j++;
    (ar[0])++;
    (ar[1])++;      //COMPILER WILL READ IT AS "  *(ar+1)  "   i.e. VALUE OF THE ADDRESS WHICH IS 4-BYTES AHEAD OF THE ADDRESS OF "ar"
}




int main(){
    int a[20];                  //ALL ELEMENTS OF THIS ARRAY WILL BE GARBAGE VALUE.... U CAN REPLACE IT LATER THOUGH

    int arr[20]={1,2,3};        //NOTE: THIS ARRAY HAS IT'S FIRST THREE ELEMENTS AS "1,2,3" , BUT AFTER THAT ALL IT'S 17 LEFT ELEMENTS WILL BE  "0" 
                                //THIS IS AN IMPORTANT KNOWLEDGE TO CREATE AN ARRAY WITH ALL IT'S ELEMENTS EQUAL TO "0" ,,, U CAN SIMPLY DO "arr[20] ={0};" ....ALL 20 ELEMENTS WILL BE "0"
                                
                                //IF U WANT AN ARRAY WITH ALL IT'S VALUES EQUAL TO "1" OR "2" OR SOMETHING , U CAN SIMPLY RUN A FOR LOOP AND INCREMENT EACH VALUE :)

    for (int i = 0; i < 20; i++)
    {
        cout<< arr[i]<<" ";
    }

    cout <<endl;


    int ar[10]={1,2,3};
    int j=1;
    rement(j , ar, 10 );
    cout<< j <<endl;        //it will remain "1"
    cout<< ar[0] <<endl;    //changes will be reflected in ar[0] and ar[1] bcoz they were simply changing the value at that given address
    cout<< ar[1] <<endl;

    
    return 0;
}