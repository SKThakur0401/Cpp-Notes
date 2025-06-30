// Friend function : is used to access "private properties" of some other class, 

// We make a function "friend" of some other class, now this friend function can access all private/protected/public properties of its friend class :)

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

void test();        // Initial declaration that " void test() " function exists!, later we have 
                    // described this function


class bus
{
    public:
    void print();           // Similar to line 10 :), this is " initial declaration " of a function 
                            // "print" which belongs to "bus" class, this function is described later
};


class truck
{
    private:
    int x;

    protected:
    int y;

    public:
    int z;


    friend void bus::print();       // NOTE: this line can be written in public/private/protected 
                                    // any area, it wouldn't be affected

    friend void test();
};


void bus::print()                   // Describing "print" function of "bus" class
{
    truck t;
    t.x= 10;
    t.y= 20;

    cout<< t.x<<"  "<< t.y <<endl;
}

void test()
{
    truck t;
    t.x= 10;
    t.y= 20;

    cout<< t.x<<"  "<< t.y <<endl;
}


int main(){


    bus b;
    b.print();

    test();

    return 0;
}

// NOTE: we can also create a "friend class"!
// "  friend class ClassName;  "

// Note this friendship is "one-way" , so this "ClassName" class can access all the properties of the class in which this line is mentioned, but its not the other way round :)

