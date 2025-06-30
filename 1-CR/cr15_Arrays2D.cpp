#include<iostream>
#include<cmath>
using namespace std;


int main(){

    int arr[5][5];      //NOTE: IN MEMORY THEY ARE STORED AS A "ONE-D" BLOCK OF MEMORY "JUST LIKE THE 1-D ARRAYS"   //THE SPACE ALLOCATED TO THE "arr" pointer is = R X C X (SIZEOF(DATA_TYPE))  ,
                        //  HERE = 5X5X4 = 100 BYTES ALLOCATED TO "arr" in continuous memory blocks :)
    
    //IN A 1-D ARRAY , SAY 'int ar[5];'   if we "cout<<ar[2];"    it actually does = arr + 2 x 4 = the required address equal to ar[2]
    //IN A 2-D ARRAY , SAY 'int arr[5][5];'   if we "cout<<ar[2][3];"    it actually does = arr + (2 x 4 x 5(i.e. number of column___bcoz for each row it skips, it actually skips 5 memory blocks:) ) + (3 x 4) = the required address equal to ar[2])

    return 0;
}
