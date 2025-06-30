#include<iostream>
#include<vector>
using namespace std;

int maxIndex(int arr[],int n)
{
    int maxi= INT_MIN;
    int ans;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]> maxi) {maxi= arr[i]; ans=i;}
    }
    return ans;
}

int minIndex(int arr[],int n)
{
    int mini= INT_MAX;
    int ans;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]< mini) {mini= arr[i]; ans=i;}
    }
    return ans;
}

void game()
{
    cout<< "Welcome, I am the Game analyser " <<endl;
    cout<< "The various commands you can enter are : " <<endl;
    cout<< "1. result (shows the detailed analysis of The Game" <<endl;
    cout<< "2. erase  (erases your last entry from database" <<endl;
    cout<< "3. A combination of 4-characters which are 'r', 'm', 'c', 's', these characters should be inserted in correspondence to the position granted to players(in descending order of their ages)" <<endl;

    cout<< "Do you want to play with the default names?(y/n) --->";
    char le; cin>> le;

    string sick[4] = {"--SOMU--", "--Jesu--", "Dhundhun", "-Munmun-"};

    if(le=='n')
    {
        cout<< "Enter 4 names : " <<endl;
        for (int i = 0; i < 4; i++)
        {
            cin>>sick[i];
        }
    }

    vector<string> v;
    while(1)
    {
        cout<< "Enter Command : ";
        string x; cin>>x;
        if(x.size()==4)
        {
            cout<< "Was the 'CHOR' caught (y/n) ? -->";
            string ans; cin>>ans;
            x.append(ans);
            v.push_back(x);
        }
        if(x.size()==5 && x != "erase")
        {
            v.push_back(x);
        }

        else if(x== "erase") v.pop_back();

        else if(x== "result")
        {
            // string sick[4] = {"SOMU", "Jesu", "Dhundhun", "Munmun"};

            int score[4] = {0};
            int Rcount[4]={0};
            int Mcount[4]={0};
            int Ccount[4]={0};
            int Scount[4]={0};
            int ThiefSlayed[4]={0};
            int BestThief[4]={0};
            int luckFactor[4]={0};

            for (int i = 0; i < v.size(); i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if(v[i][j]=='r')
                    {
                        score[j]+=1000;
                        Rcount[j]++;
                        luckFactor[j]+=10;
                    }
                    if(v[i][j]=='m')
                    {
                        score[j]+=800;
                        Mcount[j]++;
                        luckFactor[j]+=8;
                    }

                    if(v[i][j]=='c')
                    {
                        if(v[i][4]== 'n') {score[j]+=500; BestThief[j]+=2;}
                        BestThief[j]--;
                        Ccount[j]++;
                    }

                    if(v[i][j]=='s')
                    {
                        if(v[i][4]== 'y') {score[j]+=500; ThiefSlayed[j]+=2;}
                        ThiefSlayed[j]--;
                        Scount[j]++;
                    }
                }
            }
            cout<<endl;

            cout<<endl;
            cout<< "---ACHIEVEMENTS---" <<endl;

            cout<<"Highest Scorer : "<< sick[maxIndex(score,4)]<<" : " <<score[maxIndex(score,4)]<<endl;
            cout<<"Lowest  Scorer : "<< sick[minIndex(score,4)]<<" : " <<score[minIndex(score,4)]<<endl;
            cout <<endl;

            cout<< "Maharaja (person with maximum Rajas) : " <<sick[maxIndex(Rcount,4)]<<endl;
            cout <<endl;
            cout<< "'Thief Slayer' (For Catching highest number of thieves) : " <<sick[maxIndex(ThiefSlayed,4)]<<" : "<< ThiefSlayed[maxIndex(ThiefSlayed,4)] <<" (catch-miss)!!"   <<endl;

            cout<< "'Dangerous Thief' (Thief with maximum number of escapes): " <<sick[maxIndex(BestThief,4)]<<" :"<<BestThief[maxIndex(BestThief,4)] <<" (escapes-death)!!"<<endl;
            cout<< "Luckiest Guy (Easy go lucky): "<< sick[maxIndex(luckFactor,4)]<<endl;

            cout <<endl;
            cout <<endl;
            cout<< "---Detailed score Analysis---" <<endl;
            for (int i = 0; i < 4; i++)
            {
                cout<< "-------------------" <<endl;
                cout<<sick[i]<<endl;
                cout <<endl;
                cout<< "Total Score : "<<score[i] <<endl;
                cout <<endl;
                cout<< "Raja : "<<Rcount[i] <<"  |  ";
                cout<< "Mantri : "<<Mcount[i] <<endl;
                cout<< "Chor : "<<Ccount[i] <<"  |  ";
                cout<< "Sipahi : "<<Scount[i] <<endl;
                cout<< "-------------------" <<endl;
                cout <<endl;
            }
            
        }
        else if(x== "end")
        {
            break;
        }
    }
}

int main(){
    game();
    return 0;
}