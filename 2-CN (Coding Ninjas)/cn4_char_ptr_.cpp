//---- CHARACTER POINTERS ----

//PLEASE NOTE: CHARACTER POINTERS BEHAVE QUITE DIFFERENTLY, (THAT IS BCOZ THE "COUT" IS ENCODED DIFFERENTLY FOR CHARACTER POINTERS)

#include<iostream>
#include<cmath>
using namespace std;

  
int main(){
    cout<<endl;
    int x[3] = {1,43,23};
    char c[]="abcde";
    cout<< c <<endl;                // HERE, "c" is basically address of the first-character of the character array..... BUT!!, "cout" behaves differently for character-pointers.... instead of printing that address.... it goes to that address.... and starts printing everything unless it sees "\0"  ..... "cout" will behave this way for all commands concerning character-pointer...so remember this!!!
    //so, instead of giving the address of first character, it ACTUALLY goes to the address and starts printing values unless and untill met with a backslash 0  OR NULL CHARACTER

    cout<< c+1 <<endl;              // IT WILL GO TO THE ADDRESS OF "c+1" (SINCE, IT'S A CHAR POITNER, DOING +1 WILL INCREASE ONLY ONE BIT(so its now pointing at 'b')) ,SO IT WILL GO TO THAT ADDRESS AND START PRINTING VALUES TILL IT SEES "\0",,,, SO IT WILL START FROM "b" and end when it sees "\0"
    cout<< c+2 <<endl;
    cout<< c+3 <<endl;

    cout<< x <<endl;                //This is how integer pointers work :)
    cout<< sizeof(c) <<endl;        //NOTE: ITS EQUAL TO 6 ,, BCOZ OF END-OF-STRING CHARACTER "\0" BEING THERE AFTER "abcde"    


    cout<< &c <<endl;           //GIVES THE ADDRESS OF "c" or the address of first character of "c" array

    cout<< c[0] <<endl;         // Will return "c[0]" i.e. "a" ....(the integer pointer will do the same for similar case...)
    cout<< &(c[0]) <<endl;      // NOW, SINCE "&(c[0])" is an address, we know how cout will behave....(it will print character residing on that address and all the addresses after that... unless it sees /0)              SINCE "&(c[0])" = c  ---> (it will return the same thing as "c" ,,, NOW SINCE "c" returned the entire char-array , so will this :)


    char str[] ="xyz";
    char* pstr= str;
//  char* p2str= "xyz";         //THIS WILL GIVE YOU ERROR!!!
    cout<< pstr <<endl;         //SO CHARACTER POINTERS ACTUALLY GIVE THE ELEMENTS OF THE ARRAY, HERE "pstr"  IS A POINTER POINTING TO "FIRST-CHARACTER OF 'str' character array , but when asked to print, IT ACTUALLY DIVES IN TO THAT LOCATION AND STARTS PRINTING EVERYTHING THAT COMES ON IT'S WAY UNLESS AND UNTILL STRUCK BY "\0 "

    return 0;
}


