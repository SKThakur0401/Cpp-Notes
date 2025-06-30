#include<iostream>
#include<cmath>
using namespace std;


int main(){
    int a,b;
    cin>>a>>b;

    (a>b)? cout<<a<<endl: cout<<b<<endl;    //THIS IS CALLED TERNARY OPERATOR,, IT'S A SHORTER FORM OF "if"
    int c=(a>b)? a:b;   //WE CAN STORE THE VALUE IN SOME VARIABLE :)


    // const int x;     //NOTE: THIS WILL GIVE ERROR!! , BCOZ WHENEVER INITIALIZING A "CONST INT" , YOU MUST GIVE VALUE IN SAME LINE ; OTHERWISE THERE IS NO SENSE TO IT :)
    // x=10;


    int x=10;
    const int & k=x;
    x++;
//  k++;        //THIS WILL GIVE ERROR
    cout<< k <<endl;
    cout<< x <<endl;
    /*
        //HERE, WE CONCLUDE THAT "CONST" KEYWORD DOESN'T MAKE THE VALUE INSIDE THE ADDRESS AS CONSTANT,,, 
        IT ONLY MAKES THAT PATH CONSTANT,,, I USED CONST WITH variable "k" so I could not make any changes in that address using "k" 
        bcoz that path is now forbidden bcoz of "const" ,,, but however I can always use another path if that path is blocked,,, so I used x :)
    */
   
   int ap=27;
   const int *j= &ap;
   cout<< *j <<endl;
   cout<< ap <<endl;
   ap++;    //SURE, WE CAN MAKE CHANGES THROUGH "ap" bcoz it's not a constant,, i.e. it has not promised that it will not make any changes :)
// (*j)++;  //THIS WILL GIVE ERROR BCOZ IT'S A CONSTANT PATH , AND U ARE BREAKING THE RULE

   //NOW, LET'S SEE, IF WE CAN CHANGE A CONSTANT INTEGER....

    const int alpha=77;
    // int &k=alpha;       //NOW, WHEN WE WILL DO "k++" IT WILL HAVE TO AFFECT ALPHA, (BCOZ "k" is not a constant path so it can make changes) .......HOWEVER, THIS LINE ITSELF WILL GIVE ERROR ,,, PREVENTING U FROM EVEN THINKING ABOUT DOING SO :0
    // int *ptr= alpha;    //NOW, WE CAN "(*ptr)++ " AND IT WILL HAVE TO AFFECT ALPHA :) ....BUT SAME PROBLEM AS ABOVE :)

    // THE ONLY THING U CAN DO IS ADD CONST ON THE ABOVE TWO LINES (to "k" and to "ptr") ,,, SO THAT U PROMISE , U WON'T MAKE ANY CHANGES IN "alpha" THROUGH THEM :)

    int const &k=alpha;     //SINCE U PROMISED U WON'T MAKE ANY CHANGES THROUGH "k" ,, its totally fine :)
    int const *ptr=alpha;



    return 0;
}