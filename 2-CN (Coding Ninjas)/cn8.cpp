#include <iostream>
using namespace std;
int main()
{
//  #QUESTION-1
    // char arr[5];
    // char *ptr=arr;
    // (*ptr)= 66;         //SO , IF YOU INSERT NUMBERS IN "CHARACTER ARRAY" , IT WILL ACTUALLY RECOGNIZE IT AS "ASCII values" AND ACTUALLY INSERT "CHARACTERS" CORRESPONDING TO THAT ASCII VALUE :)
    // *(ptr+1) =67;
    // cout<<arr;          // Output : BC**   '*' represents random characters
    // cout <<endl;
    // cout <<endl;

//  #QUESTION-2
    float arrAY[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
    float *ptr1 = &arrAY[0];
    float *ptr2 = ptr1 + 3;
    cout<<*ptr2<<" ";
    cout<< ptr2 - ptr1 << endl;         //INTERESTING, "ptr2" and "ptr" ARE TECHNICALLY TWO HEXADECIMALS WHOSE ACTUAL DIFFERENCE IS 12, (BCOZ EACH FLOAT IS OF 4-BITS) ; BUT THE DIFFERENCE CAME OUT TO BE "3" BCOZ ,   "ptr2=ptr+3"

    return 0;
}