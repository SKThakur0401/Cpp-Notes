#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class swe
{
    // int score;

    public:
    string name;
    int eID;

    void setScore(int k)
    {
        score = k;
    }

    int getScore()
    {
        cout<< "Enter passkey : " <<endl;
        int pass; cin>>pass;

        if(pass== 123)
        {
            cout<< "The score is : ";
            return score;
        }
        cout<< "Wrong Pin : ";
        return -1;
    }

    swe(string name, int e)
    {
        this->name = name;
        eID = e;
    }

    swe(){}

    private:
    int score;
};

int main(){

    // swe somu;
    // somu.name= "Saumya";
    // somu.eID= 6969;
    // // somu.score= 69;
    // somu.setScore(69);
    // cout<< somu.getScore() <<endl;
    // // cout<< somu.score <<endl;

    // swe* skit = new swe;
    // (*skit).name = "Sahaj";
    // (*skit).eID  = 2983;
    // skit->setScore(24);
    
    // cout<< skit->getScore() <<endl;


    // swe miaKhalife( "mia", 19);

    // cout<< miaKhalife.name <<endl;
    // cout<< miaKhalife.eID <<endl;

    swe *e1 = new swe("somu", 20);

    swe e2(*e1);

    cout<< e2.name <<endl;

    e2.name = "jesu";

    cout<< e2.name <<endl;
    cout<< e1->name <<endl;

    e2 = *e1;

    cout<< e2.name <<endl;


    return 0;
}

