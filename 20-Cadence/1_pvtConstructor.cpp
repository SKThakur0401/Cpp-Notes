#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class alpha
{
    public:
    int marks;
    int ID;
    static int countOfObjects;
    static alpha *alreadyExistingObj;

    private:

    alpha(){}

    alpha(bool ObjectAlreadyExist)
    {
        if(ObjectAlreadyExist)
        {
            this->marks = alreadyExistingObj->marks;
            this->ID = alreadyExistingObj->ID;
            // return obj;
        }

        if(ObjectAlreadyExist== false)
        {
            countOfObjects++;
            ID = 47186;
            marks= 85;
            alreadyExistingObj->marks = (this->marks);
            alreadyExistingObj->ID = (this->ID);
        }

    }


    public:
    static alpha getOrCreateAlpha();
};


int alpha::countOfObjects= 0;
alpha* alpha::alreadyExistingObj;

alpha alpha::getOrCreateAlpha()
{

    if(alpha::countOfObjects ==0)
    {
        cout<<"I returned a newly created object :) "<<endl;

        alpha obj(false);
        return obj;
    }

    else
    {
        cout<<"I returned the already existing object :) "<<endl;
        alpha obj(true);
        return obj;
    }
}


int main(){

    cout<< alpha::countOfObjects <<endl;
    alpha a = alpha::getOrCreateAlpha();
    // alpha b = alpha::getOrCreateAlpha();
    cout<< alpha::countOfObjects <<endl;

    // cout<< a.marks <<endl;

    return 0;
}

