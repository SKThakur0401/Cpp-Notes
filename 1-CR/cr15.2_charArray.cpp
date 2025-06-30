#include<iostream>
#include<cmath>
using namespace std;


    //IN CASE OF CHARACTER ARRAY, ALWAYS REMEMBER---->THERE IS A "\0" AT THE END
    //char x[]= "abcde";                        // IF YOU DO "sizeof(x)" , you will get "6" bcoz there is a \0 after 'e' ;;;
    //char pig[5]="pqrs";                       // WE ONLY WROTE 4 CHARACTERS, BCOZ AFTER "s" THERE IS "\0" ,,, WRITING ANY MORE ALPHABETS WILL GIVE YOU ERROR
    //char pig[5]={'p','q','r','s','\0'};       // SAME THING IN A DIFFERENT WAY


int main(){


    char arr[20]="SaumyaKrT";           //THESE ARE SIMILAR TO 'STRINGS' BUT ARE NOT THE SAME ,, THE STRING COMMANDS LIKE "str.length()" , "str.size()" WILL NOT WORK HERE :)
    cout<< arr <<endl;          
//  cout<< arr.length() <<endl;      //THESE COMMANDS WILL NOT WORK HERE, THEY ARE ONLY VALID FOR PURE STRINGS AND NOT CHAR-ARRAYS :)
//  cout<< arr.size() <<endl;

    //HERE AT THE FIRST NINE INDICES,, MY NAME IS WRITTEN , AND ON THE TENTH INDEX (TENTH INDEX IS EQUAL TO "9" BCOZ INDEXING STARTS FROM "0") IS '\0'
    //WHEN WE CALL THE CHARACTER ARRAY POINTER i.e. "arr" , IT ACTUALLY GOES TO THE ADDRESS
    //AND STARTS PRINTING EVERYTHING UNLESS AND UNTILL MET WITH '\0'  (AFTER SEEING \0 , IT STOPS)
    //NOW, IF WE FILL SOMETHING ON THE 11th INDEX, (BACKSLASH 0 IS ON THE NINTH   INDEX)   ,, IT WILL NOT BE PRINTED :)

    arr[10]='d';
    arr[11]='e';
    arr[12]='f';
    cout<< arr <<endl;  //DEF IS NOT PRINTED :) BCOZ IT'S AFTER " BACKSLASH 0 "

    //NOW, WHAT IF WE REMOVE THE "\0" FROM THE 9TH INDEX, AND REPLACE IT WITH A NORMAL CHARACTER ??
    arr[9]= 'l';
    cout<< arr <<endl;      //IT WORKED :) NOW THE "\0" IS ACTUALLY PLACED AFTER "def" ,, on the index-13  ,,, it did it automatically to prevent the printing of garbage values :)

    char crr[100];
//  cin>>arr;       //THIS WILL NOT STORE ANYTHING WRITTEN AFTER "SPACE-BAR   or  '\t'   or   '\n'    "

    cin.getline(crr,10);        //HERE THE SECOND PARAMETER IS NUMBER OF CHARACTER U WANT TO STORE    //IT WILL ONLY STORE THE "1-ST" NINE ELEMENTS U ENTER,,,, THE TENTH SPACE WILL BE DEDICATED TO "\0" , SO ENTER ONLY NINE CHARACTERS( ANY CHARACTER INCLUDING SPACES AND TAB-SPACE) AFTER THAT IT WILL BE USELESS TO ENTER
    cout<< crr <<endl;          //THE MAXIMUM VALUE U CAN(*SHOULD) GIVE TO THE SECOND PARAMETER IS THE LENGTH OF THE ARRAY i.e. 100 in this case



// cin.getline(char_array_name , length_u_want_to_insert , delimeter)       //THIS IS THE COMPLETE TEMPLATE ,,, DELIMETER IS BY DEFAULT '\n' ,, so whenever u enter "\n"  the intake in character array will stop

    char somu[30];
    cin.getline(somu,20,'o');       //HERE, WE SET THE DELIMETER TO 'o' , NOW, AFTER "o" IT WILL NOT INSERT VALUES IN THE CHARACTER ARRAY(even "o" will not be inserted/printed):)
    cout<< somu <<endl;



// char pk[5];          //THIS METHOD IS ONLY ALLOWED FOR STRINGS AND IS ILLEGAL FOR CHARACTER ARRAYS :)
// getline(cin,pk);
// cout<< pk <<endl;

    return 0;
}
