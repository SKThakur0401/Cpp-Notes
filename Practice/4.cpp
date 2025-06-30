#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

// int powe(int x, int n) {return (n==0)? 1: x* powe(x,n-1);}

bool bsr(int arr[], int k, int si, int ei)
{
    if(si> ei) return false;
    int mid= (si+ei)/2;
    if(arr[mid] == k) return true;

    if(arr[mid] > k) return bsr(arr,k, si, mid-1);

    return bsr(arr,k, mid+1, ei);
}

bool bsearch(int arr[], int k, int si ,int ei)
{
    // bool ans = false;

    while(si <= ei)
    {
        int mid= (si+ei)/2;

        if(arr[mid] == k) return true;

        if(arr[mid] < k)
        {
            si= mid+1;
        }
        else{
            ei= mid-1;
        }
    }
    return false;
}

void bsort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j+i < n-1; j++)
        {
            if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
}

void isort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];

        for (int j = 0; j < i; j++)
        {
            if(curr < arr[j])
            {
                for (int k = i; k >j; k--)
                {
                    arr[k] = arr[k-1];
                }
                arr[j]= curr;
                break;
            }
        }
        
    }
    
}

void swapper( int &a, int &b)
{
    a= a+b;
    b= a-b;
    a= a-b;
}

void merge(int arr[], int si, int mid, int ei)
{
    int n1 = mid-si+1;
    int n2 = ei- mid;

    int a[n1]; int b[n2];
    for (int i = 0; i < n1; i++)
    {
        a[i]= arr[i+si];
    }

    for (int i = 0; i < n2; i++)
    {
        b[i]= arr[i+mid+1];
    }

    int i=0;
    int j=0;
    int k=si;
    

    while(j < n2 && i < n1)
    {
        if(a[i] < b[j]) arr[k++] = a[i++];
        if(a[i] > b[j]) arr[k++] = b[j++];
        if(a[i] == b[j]) {arr[k++] = b[j++]; arr[k++] = a[i++];}
    }

    while(i < n1) arr[k++] = a[i++];
    while(j < n2) arr[k++] = b[j++];
}

void msort(int arr[], int si, int ei)
{
    if(si>= ei) return;
    int mid = (si+ei)/2;

    msort(arr, si, mid);
    msort(arr, mid+1, ei);

    merge(arr, si, mid, ei);
}

int subs(string s, string output[])
{
    if(s.empty())
    {
        output[0]= "";
        return 1;
    }

    int smallSizeOutput = subs(s.substr(1), output);

    for (int  i = 0; i < smallSizeOutput; i++)
    {
        output[i + smallSizeOutput] = output[i] + s[0];
    }

    return smallSizeOutput*2;
    
}

int partition(int arr[], int si, int ei)
{
    int count=0;
    int curr= arr[si];

    for (int i = si+1; i <= ei; i++)
    {
        if(arr[i] < curr) count++;
    }

    swap(arr[si], arr[si+count]);
    // swapper(arr[si], arr[si+count]);     // I don't know why but this is not working properly :(


    int i= si; int j= ei;

    while(i < si+count && j > si+count)
    {
        if(arr[i]> curr && arr[j] < curr)
        {
            swap(arr[i], arr[j]);
            // swapper(arr[i], arr[j]);        // Here, it is working just fine, so we don't need the inbuilt swap function 
             i++; j--;
        }
        
        else if (arr[i] > curr) j--;
        else if (arr[j] < curr) i++;

        else {i++; j--;}
    }

    return count;

}

void qsort(int arr[], int si, int ei)
{
    if(si >= ei) return;

    int c = partition(arr, si, ei);

    qsort(arr, si, si+c-1);
    qsort(arr, si+c+1, ei);
}


// Keypad dial question
// 2-"abc"  3-"def"  4-"ghi"  5-"jkl"  6-"mno"  7-"pqrs"  8-"tuv"  9-"wxyz"
// e.g.  23 will have the following permutations possible---> ad,ae,af , bd,be,bf , cd,ce,cf


int answer(string s, string* output, string arr[])
{
    if(s.size() == 1)
    {
        string l = arr[stoi(s)-2];
        for (int i = 0; i < l.size(); i++)
        {
            output[i] = l[i];
        }
        return l.size();
    }

    int smallSizeOutput = answer(s.substr(1), output, arr);
    string l = arr[s[0] - '2'];

    for (int i = 0; i < smallSizeOutput* l.size(); i++)
    {
        output[i]= output[i% smallSizeOutput];
    }

    for (int i = 0; i < smallSizeOutput* l.size(); i++)
    {
        output[i]= l[i/ smallSizeOutput] +output[i];
    }

    return smallSizeOutput* l.size();
    
}

void keypad(string s)
{
    string arr[8] = {"abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" ,"tuv" , "wxyz"};


    string* output= new string[(int) pow(4,s.size())];

    int n= answer(s, output, arr);

    for (int i = 0; i < n; i++)
    {
        cout<< output[i] <<" ";
    }
    cout <<endl;
}

string arr[8] = {"abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" ,"tuv" , "wxyz"};


void key(string s, string arr[], string output= "")
{
    if(s.empty()) {cout<< output <<" "; return;}

    for (int i = 0; i < arr[s[0]- '2'].size(); i++)
    {
        key(s.substr(1), arr, output+ arr[s[0]- '2'][i]);
    }
    
}

int main(){

    // int n; cin>>n;
    // int arr[n];

    // int arr[11]= {1,9 ,12 ,43 ,231, 244, 321, 994, 999,1023,1024};
    // int n= sizeof(arr)/ sizeof(arr[0]);
    // int k; cin>>k;
    // cout<< bsr(arr, k, 0, n-1) <<endl;
    // cout<< bsearch(arr, k, 0, n-1) <<endl;

    // int arr[]= {1,3,2,5,4,24,983,52,5,5,2,5,1,45,2,4,25};

    // int arr[] = {1,3,2,5,4};
    // int arr[] = {1, 2, 3, 4, 5};
    // qsort(arr, 0, (sizeof(arr)/sizeof(arr[0]))-1 );
    // msort(arr, 0, (sizeof(arr)/sizeof(arr[0]))-1 );
    // isort(arr, (sizeof(arr)/sizeof(arr[0])));
    // bsort(arr, (sizeof(arr)/sizeof(arr[0])));

    // swapper(arr[0], arr[4]);

    // for (int i = 0; i < (sizeof(arr)/sizeof(arr[0])); i++)
    // {
    //     cout<<arr[i]<< " ";
    // }

    // string s= "abcde";
    // string output[(int)pow(2, s.size())];

    // int n= subs(s, output);

    // for (int i = 0; i < n; i++)
    // {
    //     cout<< output[i]<<" ";
    // }

    string s; cin>>s;
    // string output[(int)pow(4,s.size())];
    keypad(s);
    key(s, arr);


    cout <<endl;

    return 0;
}

