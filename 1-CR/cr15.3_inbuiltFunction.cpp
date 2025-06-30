#include<iostream>
#include<cstring>       //WE WILL SOME INBUILT FUNCTIONS FROM THIS HEADER FILE
using namespace std;

// DO "cn0.2_STRINGS_basics"  before this  ;;; the functions here are quite similar, the syntax are a little different :)

int main(){
    // 1 : strlen(char_array)
    char crr[20];
    cin>>crr;
    cout<< strlen(crr) <<endl;      //WILL GIVE THE EXACT LENGTH OF STRING LIKE "SAUMYA" WILL RETURN "6"
    

    // 2 : strcmp(char_array(1)  ,  char_array(2))
    char arr[20];
    cin>>arr;
 
    if(!(strcmp(crr,arr)))          //COMPARES TWO CHAR-ARRAYS , AND RETURNS "0" IF IT SEES "0" DIFFERENECES BETWEEN THE TWO CHAR-ARRAYS :) !0  == 1 == TRUE        :)
                                    //IT ACTUALLY COMPARES EACH INDICES OF THE TWO CHAR-ARRAYS
    {
        cout<< "True" <<endl;
    }
    else{cout<< "False" <<endl;}

    cout<< strcmp(crr,arr) <<endl; 
    //IT COMPARES THE FIRST INDEX AND OF BOTH ARRAY AND CHECK THE DIFFERENCE ('a' - 'a'  i.e. ASCII DIFFERENCE) IF IT IS "0" , IT WILL GO THE SECOND CHARACTERS AND FIND DIFFERENCE OF THEIR "ASCII-VALUE"
    //IF IT IS "0" THEN IT WILL GO ON UNTIL IT FINDS "\0" AND FINALLY RETURN "0" IF ASCII DIFFERENCE OF ALL CHARACTERS IS "0" BUT IF ASCII DIFFERENCE OF SAY ANY TWO CHARACTERS IS SAY "-2" THEN THIS FUNCTION WILL INSTANTLY STOP AND RETURN THE DIFFERENCE OF ASCII i.e. "-2"
    // It does (first string - second string)
    
    // 3 : strcpy(c_array1 , c_array2)          //IT WILL COPY ALL THE MATERIALS IN "c_array2" and paste it in the corresponding addresses of "c_array1" in the corresponding positions (including '\0' ) so if "c_array2" has lesser elements it will replace the corresponding elements and not harm the others :) ( however, it also inserts "\0" in its corresponding position)

    char test[100]="for i am almighty and i am great";
    strcpy(test, "simp");
    cout<< test <<endl;     //THIS RETURNS ONLY "simp"      // but note on index-4 it has copied "\0"

    test[4]='f';            //HERE  WE REPLACE "\0" WITH "f"  ,,, SO THE ENDLINE CHARACTER ACTUALLY SHIFTS TO THE POSITION AFTER "great"
    cout<< test <<endl;     //INTERESTING :)


    // 4 : strncpy(c_array1 , c_array2 , n)     //HERE "n" means number of characters of "c_array2" you want to replace/copy in "c_array2"  NOTE: IT DOES NOT APPEND "\0"  :)

    char ch1[20]="alphaeleven";
    char ch2[20]="betatwelve";

    strncpy(ch1,ch2,5);     // SO IT SIMPLY REPLACED THE FIRST-5 CHARACTERS OF "ch1" AND PUT THERE THE FIRST 5 CHARACTERS OF "ch2"
    cout<< ch1 <<endl;

    //NOTE: IF "n" is greater than length of "c_array2" then all the left over spaces will be filled with "\0"

    
    return 0;
}