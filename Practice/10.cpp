#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


class student
{
    private:
    char grades;

    public:
    string name;
    int rollNo;
    char* testing;

    student(){}

    // void insertGrades(char g)
    // {
    //     cout<< "Enter password" <<endl;
    //     int n; cin>>n;
    //     if(n== 123) grades = g;
    //     else grades = 'f';
    // }

    void showGrades()
    {
        cout<< grades <<endl;
    }

    student(string name, char* a)
    {
        this->name = name;

        this->testing = new char[strlen(a)+1];
        
    }

    ~student()      // This gets executed automatically at the end of a program
    {
        cout<< "My destructor" <<endl;
    }

};


class fraction
{
    int nume; int deno;

    public:
    
    fraction(int n, int d)
    {
        nume = n; deno = d;
    }

    void simplify()
    {
        int hcf=1;

        for(int i=1; i <= min(nume,deno) ; i++)
        {
            if(nume%i == 0 && deno%i==0) hcf=i;
        }
        nume /=hcf;
        deno /=hcf;
    }

    fraction sum(fraction f2)
    {
        int n,d;
        d= (this->deno) * (f2.deno);
        n= (this->nume)*(f2.deno) + (f2.nume)*(this->deno);

        fraction ans(n,d);
        ans.simplify();
        return ans;
    }

    void display()
    {
        cout<< this->nume <<" / "<<this->deno<<endl;
    }
};

int main(){

    
    
    return 0;
}

