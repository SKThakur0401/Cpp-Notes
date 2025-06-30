#include<iostream>
#include<cmath>
using namespace std;

//  IF YOU ITERATE IN A STRING AND "arr[i]" IS AN ELEMENT IN THAT STRING then ,,, arr[i] is actually a "char" data-type since it is a single alphabet here

 
int main(){
    //ASCII VALUE OF "a"=97 ; "b"=98 ; "c"=99 and so on....ASCII VALUE OF "A"=65 ; "B" =66 ; "C" =67 ;

    //NOTE: THERE'S A DIFFERENCE OF "32" B/W CAPITAL AND SMALL ALPHABETS LIKE ,, 'a'-'A' = 32 ; 'b'-'B'= 32 ; 'c'-'C' = 32 ....AND SO ON FOR ALL LETTERS ;)
    //SO, TO CONVERT LOWER CASE ALPHABETS TO UPPER CASE ,, WE JUST HAVE TO SUBTRACT (32)  FROM EACH LOWER-CASE ALPHABET OF THE STRING


    //NOTE: ANY MATHEMATICAL OPERATION ON A CHARACTER WILL ACT ON IT'S "ASCII-VALUE"

    char a= 'a';
    cout<< ('a'+4) <<endl;              //RETURNS ASCII VALUE OF 'a'+4 = 97+4 = 101
    cout<< char('a'+4) <<endl;          //RETURNS ASCII VALUE( Ascii_value(a) + 4 = 101) AND THEN "CHAR"CONVERTS IT INTO ALPHABET CORRESPONDING TO THAT ASCII VALUE
    cout<< 'c'-'a' <<endl;              //RETURNS DIFFERENCE IN ASCII VALUES OF BOTH THE CHARACTERS ,,, NOTE: MATHEMATICAL OPERATIONS PERFORMED ON CHARACTERS, ACTUALLY TAKE PLACE ON THEIR ASCII VALUES :)
    cout<< 'a'+1 <<endl;
    cout<< 'A' <<endl;

    char alpha=69;                      //HERE IT WILL TAKE THE ASCII Value CORRESPONDING TO THE NUMBER,,, SINCE IT'S A CHAR_____i.e.="E"
    cout<< alpha <<endl;                //NOTE: A CHARACTER DATA TYPE WILL ALWAYS RETURN A CHARACTER AND NEVER A NUMBER :)

    int z = 'c';       // HERE, "z" will assume the ASCII value of 'c'.. i.e. z=99
    cout<< z <<endl;

    string s = "sahaj";
    cout<< s <<endl;
    for (int i = 0; i < s.size(); i++)
    {
        s[i]++;                     // "s[i]" BEHAVES EXACTLY AS CHAR :)    AND DOING ++; WILL INCREASE IT'S ASCII VALUE BY "1" SO EACH ALPHABET WILL ACTUALLY BE REPLACED BY THE ALPHABET NEXT TO IT!!!
    }
    cout<< s <<endl;



    cout<< char(68) <<endl;         //RETURNS THE CHARACTER CORRESPONDING TO "ASCII-Value" 68  :)

    cout<< int('y');        //  RETURNS ASCII VALUE OF "y"


    for (int i = 0; i < 140; i++)
    {
        cout<< "Character corresponding to ASCII-Value "<<i<<" is : "<< char(i) <<endl;
    }
    
    return 0;
}
