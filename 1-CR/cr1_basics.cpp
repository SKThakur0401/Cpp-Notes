// /*

//       HARRY HAS GIVEN PROPER NOTES CORRESPONDING TO EACH LECTURE,,,IN THE DISCRIPTION OF EACH LECTURE
//       CHECK THAT OUT IF THESE DO NOT SEEM ENOUGH ;
//       LINK TO HIS PLAYLIST : https://www.youtube.com/playlist?list=PLu0W_9lII9agpFUAlPFe_VNSlXW5uE0YL


// */

// #include<iostream>          //HEADER FILE ("JUST LIKE WE IMPORTED MATH IN PYTHON,,, IT IS A NECESSARY IMPORT....IO-> STANDS FOR INPUT-OUTPUT....AND STREAM MEANS BIT STREAM (THE FLOW OF DATA IN BITS)")
// using namespace std;        //WE USE THIS SO THAT EVERY TIME WE HAVE TO PRINT... WE CAN ONLY TYPE "cout<<" instead of "std::cout<<"  ... thanks to this :)


// int main(){                 //THIS IS THE MAIN FUNCTION,,,WE CAN CREATE SEVERAL FUNCTIONS BUT THIS IS THE FUNCTION WHICH IS EXECUTED FIRST(IT IS EXECUTED ON IT'S OWN , WITHOUT CALLING)        NOTE: THE DATA TYPE YOU WRITE BEFORE MAIN..IS THE DATA TYPE OF THE OUTPUT (THE RETURN VALUE) U WANT,,,,I YOU WANT TO CREATE A FUNCTION WHICH DOES NOT ACTUALLY RETURN SOMETHING (like the swapping function, just swaps value of 2 variables and does not return anything).... you should use "void" data-type before function name;   "void swapPtr(int *a , int *b){ur code...} ...."
//     int x,y=1;
//     cout<<"Enter ur fav int : ";
//     cin>>x;
//     for(int i=1;i<=x;i++){
//         y*=i;
//     }
//     cout<<"Factorial of ur fav int is : "<<y<<endl;

//     return 0;
// }


#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


int main(){

    for(int j=2; j <= 20 ; j++)
    {
        for (int i = 1; i < 11; i++)
        {
            cout<< j<<" x "<< i<<" = "<< j*i <<endl;
        }
        cout <<endl;
        cout <<endl;
        cout <<endl;
    }
    

    return 0;
}

