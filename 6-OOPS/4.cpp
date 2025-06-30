#include<iostream>
#include<cmath>
using namespace std;

class employee
{
    public :  
    string name;
    int bday;

    private :
    int age;
    int salary;

    public :
    void setAge(int a, int password)
    {
        if(password != 2082){return;}
        if(a >0){age =a;}             //SO THAT PEOPLE DON'T ENTER "-ve" age
    }

    void getAge()
    {
        cout<< age <<endl;
    }
};


int main(){


    employee jesu;
    jesu.getAge();              //SINCE WE HAVEN'T GIVEN ANY AGE...IT WILL PRINT GARBAGE VALUE

    jesu.setAge(23,123);        //SINCE, WE INSERTED WRONG PASSWORD, THIS FUNCTION WOULDN'T DO ANYTHING  
    jesu.setAge(-21,2082);      // IF WE INSERT AGE IN NEGATIVE, THEN ALSO IT WOULDN'T DO ANYTHING  

    jesu.setAge(23,2082);       //THIS WILL SET THE AGE TO "23" 
    jesu.getAge();


// THESE ARE THE TYPES OF PARAMETERS/COMPLICATIONS WE CAN ADD IF WE MAKE PRIVATE PROPERTIES...WITH THE HELP OF FUNCTIONS :)

    return 0;
}