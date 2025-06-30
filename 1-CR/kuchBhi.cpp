#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
using namespace std;

int binToDec(int n)
{
    int sum=0;
    int k=1;
    while(n)
    {
        sum+= (n%10)*k;
        k*=2;
        n/=10;
    }
    return sum;
}

int decToOct(int n)
{
    int ans=0;
    int k=1;
    while(n)
    {
        ans+= (n%8)*k;
        k*=10;
        n/=8;
    }

    return ans;
}

int octToDec(int n)
{
    int sum=0;
    int k=1;
    while(n)
    {
        sum+= (n%10)*k;
        k*=8;
        n/=10;
    }

    return sum;
}

int hexToDec(string s)
{
    int ans=0;
    int k=1;
    for (int i = s.size()-1; i >=0 ; i--)
    {
        if(s[i] >= 'a' && s[i] <= 'f')
        {
            ans+= (s[i]- 'a' +10)*k;
            k*=16;
        }

        else
        {
            ans+= (s[i]- '0')*k;
            k*=16;
        }
    }
    
    return ans;
}

string decToHex(int n)
{
    string s= "";
    while(n)
    {
        int x = n%16;
        if(x>9)
        {
            s= char(x-10+ 97) + s;
        }
        else
        {
            s= to_string(x)+ s;
        }
        n/=16;
    }
    return s;
}

int bsearch(int arr[], int k, int si, int ei)
{
    if(si > ei) return -1;
    int mid= (si+ei)/2;

    if(arr[mid] == k) return 1;


    if(arr[mid] > k) return bsearch(arr, k, si, mid-1);
    if(arr[mid] < k) return bsearch(arr, k, mid+1, ei);
    return -1;
}

int bsearchIter(int arr[], int k, int si, int ei)
{
    if(si > ei) return -1; 
    int mid= (si+ei)/2;

    if(arr[mid] == k) return 1;

    while(si <= ei)
    {
        int mid= (si+ei)/2;

        if(arr[mid] == k) return 1;

        else if(arr[mid] > k) ei= mid-1;
        else if(arr[mid] < k) si= mid+1;
    }
    return -1;
}

void bsort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n-1; j >= i; j--)
        {
            if(arr[j] < arr[j-1]) swap(arr[j-1], arr[j]);
        }
        
    }
    
}

void isort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for(int j=i-1; j>=0; j--)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void merge(int arr[], int si, int mid, int ei)
{
    int n1= mid-si+1;
    int n2= ei-mid;
    int a[n1];
    int b[n2];

    for (int i = 0; i < n1; i++)
    {
        a[i]= arr[i+si];
    }

    for (int i = 0; i < n2; i++)
    {
        b[i]= arr[i+ mid+1];
    }
    
    int i=0; int j=0;
    int k=si;
    while(i < n1 && j < n2)
    {
        if(a[i] < b[j]) arr[k++] = a[i++];
        else if(a[i] > b[j]) arr[k++] = b[j++];
        else if(a[i] == b[j]) {arr[k++] = a[i++]; arr[k++] = b[j++];}
    }
    while (i < n1)
    {
        arr[k++] = a[i++];
    }

    while (j < n2)
    {
        arr[k++] = b[j++];
    }
    
}

void msort(int arr[], int si, int ei)
{
    if(si >= ei) return;
    int mid= (si+ei)/2;

    msort(arr, si, mid);
    msort(arr, mid+1, ei);

    merge(arr, si, mid, ei);
}

int partition(int arr[], int si, int ei)
{
    int c=0;
    int curr= arr[si];
    for (int i = si; i <= ei; i++)
    {
        if(arr[i] < curr) c++;
    }
    swap(arr[si], arr[si+c]);

    int i= si; int j= ei;
    while(i <si+c && j > si+c)
    {
        if(arr[i] > curr && arr[j] < curr) swap(arr[i++], arr[j--]);
        else if(arr[i] > curr) j--;
        else if(arr[j] < curr) i++;
        else{ i++; j--; }
    }
    return c;
}

void qsort(int arr[], int si, int ei)
{ 
    if(si >= ei) return;
    
    int c= partition(arr, si, ei);

    qsort(arr, si, si+c-1);
    qsort(arr, si+c+1, ei);
}

int subs(string arr[], string s)
{
    if(s.empty())
    {
        arr[0]= "";
        return 1;
    }

    int sA = subs(arr, s.substr(1));

    for (int i = 0; i < sA; i++)
    {
        arr[i+ sA] = s[0] + arr[i];
    }
    return 2*sA;
}

int dial(int k, string *output)
{
    string sarr[]= {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    if(to_string(k).size()== 1)
    {
        for (int i = 0; i < sarr[k-2].size(); i++)
        {
            output[i] = sarr[k-2][i];
        }
        return sarr[k-2].size();
    }

    int sA = dial(k/10, output);
    int K= k%10;

    for (int i = sA; i < sA* (sarr[K-2].size()); i++)
    {
        output[i] = output[i%sA];
    }

    for (int i = 0; i < sA* (sarr[K-2].size()); i++)
    {
        output[i] = output[i] + sarr[K-2][i/sA];
    }
    
    return sA*(sarr[K-2].size());
}

void subsPro(string output, string s)
{
    if(s.empty()) cout<< output <<"  ";
    else
    {
        subsPro(output, s.substr(1));
        subsPro(output+ s[0], s.substr(1));
    }
}

void dialPro(string sarr[], string output, int k)
{
    if(k==0) cout<< output <<"  ";

    else
    {
        for (int i = 0; i < sarr[(k%10)-2].size(); i++)
        {
            dialPro(sarr, sarr[(k%10)-2][i] + output ,k/10);
        }
    }
}

bool chk(string s)
{
    if(s.size()==0) return true;

    if(s.size()==1 && s[0] == 'a') return true;
    if(s.size()==1 && s[0] == 'b') return false;

    if(s[0]== 'a' && s[1] == 'a') return chk(s.substr(1));
    if(s[0]== 'a' && s.size()>=3 && s.substr(1,2) == "bb") return chk(s.substr(3));

    return false;
}

int stairs_Memoised(int n, int memo[])
{
    int ans=0;
    if(n<0) return 0;
    if(n==0) return memo[0] = 1;
    if(memo[n] !=0 ) return memo[n];
    ans+= stairs_Memoised(n-1, memo);
    ans+= stairs_Memoised(n-2, memo);
    ans+= stairs_Memoised(n-3, memo);

    return memo[n] = ans;
}

void solve(string k, string store, string output= "")
{
    if(k.size() ==0) cout<< output <<endl;

    else if(k.size()== 1) solve( k.substr(1), store , output + store[k[0]-'0']);

    else
    {
        solve( k.substr(1), store , output + store[k[0]-'0']);
        int xi = (k[0]- '0')*10 + k[1]- '0';
        solve( k.substr(2), store , output +  store[xi]);
    }
}

void machine(string s, vector<bool> &v, int fcount= 0, string output= "")
{
    if(fcount == s.size()) cout<< output <<endl;

    for (int i = 0; i < s.size(); i++)
    {
        if(v[i])
        {
            v[i]=false;
            machine(s, v, fcount+1, output+ s[i]);
            v[i]= true;
        }
    }
    
}

void permutate(string s)
{
    vector<bool> v(s.size(), true);
    machine(s, v);
}

class student
{
    int grades;
    public:
    int rollNum;
    int id;
    char* name;
    void setGrade(int k)
    {
        int password;
        cout<< "Enter password : ";
        cin>>password;
        if(password == 123)
        {
            grades = k;
        }
    }

    void getGrade()
    {
        cout<< grades <<endl;
    }

    student(int rollNum, int id, char* name)
    {
        this->rollNum= rollNum;
        this->id= id;
        this->name= new char[sizeof(name)];
        strcpy(this->name, name);
    }

    student(student &s2)
    {
        this->rollNum= s2.rollNum;
        this->id= s2.id;
        this->name= new char[sizeof(s2.name)];
        strcpy(this->name, s2.name);
    }
};

int main(){
    // int* j= new int[5];
    // j[0]= 0;j[1]= 11;j[2]= 22;j[3]= 33;j[4]= 44;
    // for (int i = 0; i < 5; i++)
    // {
    //     cout<< j[i] <<endl;
    // }
    // delete[] j;
    // for (int i = 0; i < 5; i++)
    // {
    //     cout<< j[i] <<endl;
    // }
    // int arr[5]= {1,2,3,4,5};
    // int * parr = arr;
    // int i= 66;
    // int* ptri= &i;
    // char* cptri = (char*) ptri;     // explicitly ordering it to be char!!
    // cout<< cptri <<endl;
    // cout<< cptri+1 <<endl;
    // cout<< cptri+2 <<endl;
    // cout<< cptri+3 <<endl;
    // cout<< cptri+4 <<endl;
    // if(1)
    // {
    //     int* p= new int;
    //     *(p) = 69;
    //     cout<< p[0] <<endl;
    //     delete p;
    // }

    // int* arr= new int[50];
    // for (int i = 0; i < 50; i++)
    // {
    //     int j;
    //     cin>>j;
    //     arr[i] = j;
    // }
    // int n=13;
    // int arr[] = {7,9,1,3,5,4,12,41,52,1,19, 27, 14};
    // // int phi; cin>>phi;
    // qsort(arr, 0, 12);
    // for (int i = 0; i < n; i++)
    // {
    //     cout<< arr[i] <<" ";
    // }
    // cout <<endl;
    // cout<< bsearch(arr, phi, 0, 4) <<endl;
    // cout<< bsearchIter(arr, phi, 0, 4) <<endl;
    // string s= "abcd";
    // // string arr[16]={};
    // string output="";
    // subsPro(output, s);
    // // for (int i = 0; i < n; i++)
    // // {
    // //     cout<< arr[i] <<"  ";
    // // }
    // cout <<endl;
    // int k = 972;
    // string *output= new string[50];
    // int n = dial(k, output);
    // for (int i = 0; i < n; i++)
    // {
    //     cout<< output[i] <<" ";
    // }
    // int k= 79;
    // string sarr[]= {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    // string output= "";
    // dialPro(sarr, output, k);
    // string s= "abbabb";
    // cout<< chk(s) <<endl;
    // int n;
    // cout<< "Enter n : ";
    // cin>>n;
    // // int* memo= new int[n];
    // int *memo = new int[n+1];
    // for (int i = 0; i < n+1; i++)
    // {
    //     memo[i]=0;
    // }
    // cout<<mcount(n, memo)<<endl;
    // int k= 1123;
    // // string* arr= new string[20];
    // string store= "0abcdefghijklmnopqrstuvwxyz";
    // string s = to_string(k);
    // solve(s, store);
    // vector<int> vi;
    // vi.push_back(1);
    // vi.push_back(2);
    // vi.push_back(3);
    // vector<int>::iterator it= vi.begin();
    // while(it != vi.end())
    // {
    //     cout<< *it <<endl;
    //     it++;
    // }
    // unordered_map<int,int> um;
    // um[2]= 4;
    // um[3]= 9;
    // um[4]= 16;
    // um[5]= 25;
    // um[6]= 36;
    // unordered_map<int,int>::iterator fk= um.begin();
    // while(fk != um.end())
    // {
    //     cout<< (*fk).first <<"   ";
    //     cout<< (*fk).second <<endl;
    //     fk++;
    // }
    // string st= "abcde";
    // rotate(st.begin(), st.begin()+3,);
    // cout<< st <<endl;

    // student s1;
    // s1.rollNum= 15;
    // s1.id= 2020;
    // s1.setGrade(97);
    // cout<< s1.id <<endl;
    // s1.getGrade();

    student* s1= new student(15,2021, "saum");
    // s1->rollNum=15;
    // s1->id= 2021;
    cout<< s1->name <<endl;

    student* s2= new student(*s1);

    // cout<< s2->name <<endl;
    s1->name[2] = 'x';
    cout<< s1->name <<endl;
    cout<< s2->name <<endl;


    return 0;
}

