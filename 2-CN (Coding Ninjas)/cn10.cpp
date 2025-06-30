#include<iostream>
#include<cmath>
using namespace std;


int main(){

    char c='x';
    char*ptr=&c;
    cout<< &c <<endl;       //SO, WHEN WE PRINT CHARACTER POINTER, IT RETURNS NOT THE ADDRESS, BUT THE VALUE (ACTUALLY IT STARTS TRAVERSING IN THE ADDRESS,,AND PRINTS EVERYTHING UNLESS IT FINDS '\0' OR NULL CHARACTER)
    cout<< ptr <<endl;      //SAME AS LINE ABOVE

    char d=67;           //SO IF YOU ENTER ANY NUMBER IN CHARACTER VARIABLE CONTAINER,,, IT WILL THINK OF IT AS IT'S "ASCII-value"
    cout<< d <<endl;
    int i=69;
    char di=i;
    cout<< di <<endl;
    return 0;
}
