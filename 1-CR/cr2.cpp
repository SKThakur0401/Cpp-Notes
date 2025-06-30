#include<iostream>  //THIS IS CALLED HEADER FILES...(SAME AS "import" in python)THERE ARE TWO TYPES OF HEADERE FILES, BUILT IN AND USER DEFINED. BUILT IN INCLUDES FILES LIKE "iostream" , "iomanip" (like math in python)  and user defined includes our pre-written files (like cr2, cr3,cr4 etc...) like using a code from another code written by us...like we imported in python

// using namespace std;    // "std" is short-form for "standard"   //SO THIS MEANS HERE WE ARE USING STANDARD NAMESPACE :)  //NOTE: AFTER WE HAVE WRITTEN THIS LINE WE DON'T HAVE TO TYPE "std::cout<<" ,,, instead we have to type only "cout<<"
// C++ HAS MANY NAMESPACES,,, DIFFERENT CODERS CAN CREATE THEIR OWN NAMESPACE WHERE DIFFERENT THINGS MIGHT HAVE DIFFERENT MEANINGS ,,, E.G. "frank" made his own namespace where "cout" has a different meaning ,,, so if we do "frank::cout<<" it will behave accordingly and differently than "std::cout<<"   ,,, but for now, we are only going to use the "STANDARD NAMESPACE OF C++" EVERYWHERE , SO INSTEAD OF WRITING "std::cout" every time..... we already declared "using namespace std" ,, that is--> we are using "cout" of "std" namespace ,, or "cin" of "std" namespace ;) 

//USING THE THREE LINES BELOW WILL BE A BETTER PRACTICE (LATER WHEN U WILL USE OTHER NAMESPACES :) .... FOR NOW ,    "using namespace std;"    is just fine :)


using std::cout;
using std::cin;
using std::endl;
int main(){             //EVERY C++ PROGRAM MUST HAVE EXACTLY ONE MAIN FUNCTION ... THIS FUNCTION IS CALLED BY THE COMPILER,,, IT RUNS AUTOMATICALLY WHEN THE PROGRAM IS RUN,,,,(U DON'T HAVE TO CALL THIS FUNCTION :)  "return 0;"  MEANS THAT THE FUNCTION EXECUTED SUCCESSFULLY!!! ,,, IF THE RETURN VALUE IS NOT "0" ,, then the operating system try's to determine what went wrong
    int  sam=69, sahaj=21 ;

    cout<<"How are you bro "<< sam+ sahaj ;
    return 0;
}