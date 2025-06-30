#include<iostream>
#include<cmath>
using namespace std;

class student
{
    public : 
    int const age;
    int rollNo;
    int const &x;         //THIS IS A REFERENCE VARIABLE, WHICH WE WANT TO USE TO REFERENCE "AGE", since age is const int, we need to use "const" here also

    // WITHIN "INITIALISATION LIST" , IF WE WANT TO PUT SOMETHING WHICH BELONGS OUTSIDE THE CONSTRUCTOR WITH IN THE "BRACKETS", THEN WE WOULD NEED TO USE "THIS" KEYWORD..... LIKE IN CASOF "x(this->age)" ,,, IF WE HADN'T USED "THIS", THE COMPILER WOULD HAVE READ IT AS THE AGE INITIATED WITHIN CONSTRUCTOR...

 
    student(int const age,int rNo) : age(age),rollNo(rNo), x(this -> age)
    {
        cout<< "Age of student is : "<<age<< "     "<< "roll number : "<<rollNo <<"     "<<"referenece var is : "<<x <<endl;
    }
};

int main(){

    student s1(19,38922);

    return 0;
}
  