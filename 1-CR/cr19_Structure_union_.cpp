#include<iostream>
using namespace std;

//TO ACCESS HARRY'S NOTES  ON STRUCTURE, UNION AND ENUM :) --> https://www.codewithharry.com/videos/cpp-tutorials-in-hindi-14


typedef struct employee{          //"typedef" is not necessary,,,we use "typedef" and at the end wrote a shorter name to call the struct easily,,, now in line-21 ; we typed "ep harry" instead of "struct employee harry"...that's what it's job was.    (IT'S SAME AS "import pandas as ps"  .... TO MAKE CALLING EASIER)
    int eID;
    char favChar;
    float salary;
}ep;                              //DON'T FORGET TO PUT "semi-colon" AT THE END OF STRUCTURE (WE DON'T PUT IT AT THE END OF FUNCTIONS...SO WE TEND TO FORGET)
 
union money{                      //Unions are similar to structures but they provide better memory management than structures.  Unions use shared memory so only 1 variable can be used at a time.
    int rice;
    char car;                     //SO THE USER CAN STORE VALUE IN ONLY ONE OF "car","rice","pound"
    float pound;                  //NOTE : The compiler chooses the data type which has maximum memory for the allocation....HERE,,, ( int / float ) has "4-bit size" and char has "1-bit size" ,,, so compiler will leave "4 bit space" for the memory allocation...(SO, THE USER CAN STORE ANY ONE OF THE FOLLOWING)      NOTE : IF YOU TRY TO GIVE VALUES TO MORE THAN ONE VARIABLES.....THE FORMER WILL START GIVING "GARBAGE VALUE" AND THE LATTER WILL HAVE THE REAL VALUE INTACT
};


int main(){
    ep harry;
    harry.eID= 69;
    harry.favChar= 'c';
    harry.salary= 11.25;

    cout<<harry.eID<<endl;
    cout<<harry.favChar<<endl;
    cout<<harry.salary<<endl;


    union money somu;
    somu.rice=69;
    somu.car= 'f';          //HERE, WE ALLOCATED 2 VALUES WITHIN "UNION", WHICH IS NOT ALLOWED,,, CONSEQUENTLY, "somu.rice" will start giving "garbage value" and "somu.car" will have the real value intact.....IF YOU ALLOCATE THE THIRD VALUE (pound) BELOW THESE TWO,,, THEN POUND WILL GIVE REAL VALUE AND THESE TWO GARBAGE VALUE :)


    cout<<somu.car<<endl;
    cout<<somu.rice<<endl;

    return 0;
}


// ----JUST ANOTHER PROGRAM

// #include<iostream>
// using namespace std;

// typedef struct employee{
//     int eId;
//     char favChar;
//     float salary;
// }ep;

// typedef union student{
//     float marks;
//     char grades;
//     int rank;
// }pink;

// int main(){
//     ep somu;
//     somu.eId = 3;
//     somu.favChar= 'S';
//     somu.salary=111.69;

//     cout<<"Somu\'s salary is : "<<somu.salary<<endl;
//     cout<<"Somu\'s eId is : "<<somu.eId<<endl;
//     cout<<"Somu\'s favChar is : "<<somu.favChar<<endl;
//     pink rahul;
//     rahul.marks= 92.4;
//     rahul.grades='a';
//     rahul.rank=9;

//     cout<<"Rahul\'s marks is : "<<rahul.marks<<endl;
//     cout<<"Rahul\'s grades is : "<<rahul.grades<<endl;
//     cout<<"Rahul\'s rank is : "<<rahul.rank<<endl;       //SINCE, UNION CAN STORE ONLY 1 VALUE....ONLY THIS WILL BE STORED CORRECTLY, THE ABOVE 2 WILL BE REPLACED BY GARBAGE VALUE;


//     return 0;
// }