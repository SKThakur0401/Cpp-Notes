// We use templates to create a class which is applicable for all types of data-types. E.g. we created a class called "stacks" and we want it to be applicable for "integers" , for "characters", for "strings" for "doubles" etc...

// Under normal circumstances... we will have to create separate classes to handle all these data types...with just the data type different (and rest code same).... but we can overcome this problem using "templates"

// we make templates and give it names like "T" , "V" , "W" etc... and we place these characters in places of data types...and later when we are creating an object of that class... we will have to specifically define what we want "T" , "V"  or "W"  to mean...which data-type the object is...

// so our class Stacks will be valid across all data-types :)

#include<iostream>
using namespace std;

template <typename T, typename V>

class Pair
{
    T x;
    V y;
    
    public:
    void setX(T x)
    {
        this->x = x;
    }
    void setY(V y)
    {
        this->y= y;
    }

    T getX()
    {
        return x;
    }

    V getY()
    {
        return y;
    }
};

int main(){

    Pair<int,int> p1;           // here... <int,int>  is pointing towards "template" ... where we defined "T" and "V" with comma separationg...here we are defining their values for "p1" object... so both "T" and "V" should refer to integer data-type for our object "p1"   :)
    p1.setX(69);
    p1.setY(31);
    cout<< p1.getX() <<endl;
    cout<< p1.getY() <<endl;

    Pair< Pair<int,int> , int> p2;

    Pair <int,int> p4;
    p4.setX(11);
    p4.setY(22);
    p2.setX(p4);
    p2.setY(33);

    cout<< p2.getX().getX() <<endl;         // p2.getX() ...will return a pair of integer..then "getX()" acting on that will return the "x" integer of that pair..ie "11"
    cout<< p2.getX().getY() <<endl;  
    cout<< p2.getY() <<endl;

    return 0;
}