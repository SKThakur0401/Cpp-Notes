#include<iostream>
#include<cmath>
#include<string>
#include<stack>
#include<vector>
using namespace std;

class player
{
    public:
    string name;
    int score;
    int Rcount;
    int Mcount;
    int Ccount;
    int Scount;

    player(string name)
    {
        this->name= name;
        score=0;
        Rcount=0;
        Mcount=0;
        Ccount=0;
        Scount=0;
    }

    player()
    {
        score=0;
        Rcount=0;
        Mcount=0;
        Ccount=0;
        Scount=0;
    }
};

class game
{
    public:
    // player *p1 = new player("Somu");
    player *p2 = new player("Jesu");
    player *p3 = new player("Dhundhun");
    player *p4 = new player("Munmun");
    // player** arr= new player[4];
    // player p1;
    // player p2;
    // player p3;
    // player p4;
    vector<player*> arr;
    // arr.push_back
    arr[0]= new player("Somu");
    arr[1]= p2;
    arr[2]= p3;
    arr[3]= p4;

    game()
    {
        stack<string> history;
        while(1)
            {
            cout<<"Enter Command : ";
            string x; cin>>x;

            if(x.size()==4)
            {
                history.push(x);
                cout<< "Was the 'CHOR' caught (y/n)?" <<endl;
                char ans; cin>>ans;
                for (int i = 0; i < x.size(); i++)
                {
                    int increment;
                    if(x[i]== 'r'){ arr[i]->score+=1000 ; arr[i]->Rcount++; }
                    if(x[i]== 'm'){ arr[i]->score+=800 ; arr[i]->Mcount++; }
                    
                    if(x[i]== 'c')
                    {
                        if(ans=='n') {arr[i]->score+=500 ;} 
                        
                        arr[i]->Ccount++;
                    }

                    if(x[i]== 's')
                    {
                        if(ans=='y') arr[i]->score+=500;

                        arr[i]->Scount++;
                    }

                }

                cout<<"Noted!"<<endl;
            }

            else if(x== "result")
            {
                cout<< "Which Ranking system would you use ?? The banal white-ranking-system? Or The great BLACK-RANKING-SYSTEM" <<endl;

                string s; cin>>s;

                cout<< "The Final scores are : " <<endl;
                cout<< "Somu : "<<arr[0]->score <<endl;
                cout<< "Jesu : "<<arr[1]->score <<endl;
                cout<< "Dhundhun : "<<arr[2]->score <<endl;
                cout<< "Munmun : "<<arr[3]->score <<endl;
            }

            else if(x== "erase")
            {
                if(history.empty())
                {
                    cout<< "There's nothing to delete dumb ARSE _|_" <<endl;
                    continue;
                }

                string x2= history.top();
                history.pop();
                cout<< "Was the 'CHOR' caught last time(y/n)?" <<endl;
                char ans; cin>>ans;
                for (int i = 0; i < x2.size(); i++)
                {
                    int increment;
                    if(x2[i]== 'r'){ arr[i]->score-=1000 ; arr[i]->Rcount--; }
                    if(x2[i]== 'm'){ arr[i]->score-=800 ; arr[i]->Mcount--; }
                    if(x2[i]== 'c')
                    {
                        if(ans=='n') arr[i]->score-=500 ; 
                        arr[i]->Ccount--;
                    }
                    if(x2[i]== 's')
                    {
                        if(ans=='y') arr[i]->score-=500;
                        arr[i]->Scount--;
                    }
                }
                cout<<"Last Entry deleted!!"<<endl;
            }

        }
    }

};


int main(){


    game g1;

    return 0;
}