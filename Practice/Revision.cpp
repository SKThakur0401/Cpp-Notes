#include<iostream>
#include<climits>
#include<cmath>
#include<algorithm>
using namespace std;    // Its the inbuilt "std"... called 'namespace'... it helps us write    "cout<<23*5;" instead of "std::cout<<32*5;"

int fibo(int n)
{
    return (n==1 || n==2)? 1 : fibo(n-1) + fibo(n-2);
}

int fibonacci(int n)
{
    if(n==1 || n==2) return 1;

    int t1=1,t2=1;
    int next;
    for (int i = 0; i < n-2; i++)
    {
        next= t1+t2;
        t1=t2;
        t2=next;
    }
    return next;
}

int summation(int arr[],int size)
{
    return (size==1)? arr[0]: arr[0] + summation(arr+1,size-1);
}

bool checker(int arr[],int size,int k)
{
    if(arr[0]== k) return true;
    if(size==0) return false;
    return checker(arr+1,size-1,k);
}

int pow(int x,int n)
{
    return (n==0)? 1: x * pow(x,n-1);
}

float gp(int k)
{
    // float ans=0;         // THIS SOLUTION IS ALSO CORRECT
    // for (int i = 0; i < k+1; i++)
    // {
    //     ans+= (1.0/pow(2,i));
    // }

    if(k==0) return 1;
    return 1.0/pow(2,k) + gp(k-1);
}

void UpperCasify(char arr[])
{
    if(*arr <= 91 && *arr >= 65) UpperCasify(arr+1);
    if(*arr >= 97 && *arr <= 123){

        *arr = (*arr)-32;
        UpperCasify(arr+1);
    }
}

void removeX(char carr[])
{
    if(carr[0]== '\0') return;
    if(carr[0] != 'x') {removeX(carr+1); return;}

    int i;
    for (i = 0; carr[i] != '\0' ; i++)
    {
        carr[i]= carr[i+1];
    }
    removeX(carr); return;
}

void dupify(char carr[])
{
    if(carr[0]=='\0' || carr[1]=='\0') return;
    if(carr[1]== carr[0])
    {
        for (int i = 0; carr[i] != '\0'; i++)
        {
            carr[i]=carr[i+1];
        }
        dupify(carr); return;
    }
    dupify(carr+1); return;
}

void ssort(int arr[],int n)
{
    if(n==1) return;
    int min= INT_MAX;
    int pos;
    for (int i = 0; i < n; i++)
    {
        if(min> arr[i])
        {
            min=arr[i];
            pos=i;
        }
    }
    int temp= arr[pos];
    arr[pos]=arr[0];
    arr[0]= temp;

    ssort(arr+1,n-1); return;
}

void isort(int arr[], int n)
{
    for(int curr=0; curr<n-1; curr++)
    {
        int pos= -1;
        if(arr[curr+1] >= arr[curr]) continue;
        if(arr[curr+1] <arr[curr])
        {
            for (int i = curr; i >=0; i--)
            {
                if(arr[i]< arr[curr+1])
                {
                    pos=i;
                    break;
                }
            }
        }

        int temp= arr[curr+1];

        for (int i = curr+1; i > pos+1; i--)
        {
            arr[i]= arr[i-1];
        }
        arr[pos+1]= temp;
    }
}



void Merge(int arr[],int ar[], int n1, int n2, int ans[])
{
    int i=0, j=0,k=0;
    while(i<n1 && j<n2)
    {
        if(arr[i] < ar[j]) {ans[k]= arr[i]; k++;i++;}
        else if(arr[i]> ar[j]) {ans[k]= ar[j]; k++;j++;}
        else if(arr[i]== ar[j])
        {
            ans[k]= arr[i]; k++;i++;
            ans[k]= ar[j]; k++;j++;
        }
    }

    while(i<n1)
    {
        ans[k]= arr[i]; k++;i++;
    }

    while(j<n2)
    {
        ans[k]= ar[j]; k++;j++;
    }
}


void merge(int arr[],int si, int mid, int ei)
{
    int n1= mid-si+1;
    int n2= ei-mid;
    int a[n1];
    int b[n2];
    for (int i = si; i < n1+si; i++)
    {
        a[i-si]= arr[i];
    }

    for (int i = mid+1; i <= ei; i++)
    {
        b[i-mid-1]= arr[i];
    }
    int i=0,j=0,k=si;

    while(i<n1 && j<n2)
    {
        if(a[i]<b[j]) {arr[k]=a[i]; k++;i++;}
        else if(a[i]>b[j]) {arr[k]=b[j]; k++;j++;}
        else if(a[i]==b[j]) {arr[k]=b[j]; k++;j++;arr[k]=a[i]; k++;i++;}

    }
    while(i<n1){arr[k]=a[i]; k++;i++;}
    while(i<n1){arr[k]=b[j]; k++;j++;}
}

void msort(int arr[], int si, int ei)
{
    if(ei<= si) return;
    int mid= (si+ei)/2 ;

    msort(arr,si,mid);
    msort(arr,mid+1,ei);

    merge(arr,si,mid,ei);
}


int partition(int arr[], int si, int ei, int curr)
{
    int count=0;
    for (int i = si; i <= ei; i++)
    {
        if(arr[i]<curr) count++;
    }

    int temp= arr[si];
    arr[si]= arr[si+count];
    arr[si+count]=temp;

    int i= si, j=ei;
    while(i < si+count && j> si+count)
    {
        if(arr[i] > arr[si+count] && arr[j] < arr[si+count])
        {
            int temp= arr[i];
            arr[i]=arr[j];
            arr[j]= temp;
            i++; j--;
        }

        else if(arr[i] > arr[si+count]) j--;
        else if(arr[j] < arr[si+count]) i++;
        else {i++; j--;}
    }

    return count;
}

void qsort(int arr[],int si, int ei)
{
    if(ei<=si) return;
    int curr= arr[si];

    int c= partition(arr,si,ei, curr);

    qsort(arr,si,si+c-1);
    qsort(arr,si+c+1,ei);
}

int ss(string s, string output[])
{
    if(s.empty()) {output[0]= ""; return 1;}

    int smallSizeOutput = ss(s.substr(1),output);
    for (int i = 0; i < smallSizeOutput; i++)
    {
        output[i+ smallSizeOutput]= s[0] + output[i];
    }
    return 2* smallSizeOutput;
}


int dial(int n, string output[])
{
    string sarr[]= {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    if(to_string(n).size() == 1)
    {
        for (int i = 0; i < sarr[n-2].size(); i++)
        {
            output[i]=sarr[n-2][i];
        }
        return sarr[n-2].size();
    }

    int smallSizeOutput = dial( stoi(to_string(n).substr(1)) , output);

    for (int i = 0; i < smallSizeOutput; i++)
    {
        for (int j = 0; j < sarr[stoi(to_string(n).substr(0,1)) -2].size() ; j++)
        {
output[i+ smallSizeOutput*j]= sarr[stoi(to_string(n).substr(0,1)) -2][j] + output[i].substr(output[i].size()- to_string(n).size()+1);
        }
    }
    return sarr[stoi(to_string(n).substr(0,1)) -2].size() * smallSizeOutput;
}

void subsequenter(string input, string output="")
{
    if(input.empty()) {cout<< output <<" "; return;}

    subsequenter(input.substr(1), output);
    subsequenter(input.substr(1), output + input[0]);
}

int main()
{
//     int n; cin>>n;
//     cout<<"The nth term of Fibonacci series is : "<<fibo(n)<<endl;
//     cout<<"The nth term of Fibonacci series is : "<<fibonacci(n)<<endl;

    // int ar[5]= {1,2,3,4,5};
    // // cout<< summation(ar,5) <<endl;
    // cout<< checker(ar,5,6) <<endl;

    // cout<< gp(3) <<endl;

    // char arr[]= "SaumYA";

    // UpperCasify(arr);
    // cout<< arr <<endl;

    int z= 'z';
    cout<< z <<endl;

    // cout<< int('c') <<endl;
    // STRINGS
    // string x;
    // cout<<"Enter string : ";
    // // getline(cin,x);
    // cin>>x;
    // cout<< x <<endl;

    // x= "I am a bad boy";
    // string y= "Fuck you all";
    // cout<<x.substr(3,3)<<endl;
    // cout<<x.find("b")<<endl;
    // // x.erase(3,2);
    // x.insert(4,"fuck");
    // cout<< "Size of x is : "<<x.length() <<endl;


    // x.append(y);
    // cout<< x <<endl;
    // cout<< x.empty() <<endl;
    // x.clear();
    // cout<< x.empty() <<endl;


    // int x=20;
    // string s="40";
    // // int a= stoi(s);
    // string a= to_string(x);
    // cout<< s+a <<endl;


    // string random="ihfelsjlkf";
    // for (int i = random.size()-1; i > 0; i--)
    // {
    //     for (int j = 0; j <i ; j++)
    //     {
    //         if(random[j]> random[j+1])
    //         {
    //             char temp= random[j];
    //             random[j]=random[j+1];
    //             random[j+1]= temp;
    //         }
    //     }
        
    // }
    // cout<< random <<endl;
    // cout<< sizeof(char) <<endl;

    // string random="ihflllleeeeeeelsjlkf";

    // int arr[26] = {0};

    // for (int i = 0; i < random.size(); i++)
    // {
    //     arr[random[i]-'a']++;
    // }
    // int max=0;
    // int k=0;
    // for (int i = 0; i < 26; i++)
    // {
    //     if(arr[i]> max)
    //     {
    //         max= arr[i]; k=i;
    //     }
    // }
    // cout<< char(k+ 'a') <<endl;
    

    // char carr[]= "saxxumxxyxa";
    // cout<< carr <<endl;
    // // removeX(carr);
    // dupify(carr);
    // cout<< carr <<endl;



    // 1
    // 1 2
    // 1 2 3
    // 1 2 3 4 


    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            cout<<i*(i+1)/2  +j+1<<" ";
        }
        cout <<endl;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            cout<<char(68-i+j);
        }
        cout <<endl;
    }
    
//  Isosceles Triangle
    int n=4;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            cout<< " ";
        }
        for (int j = 0; j < i+1; j++)
        {
            cout<<j+1+i;
        }
        for (int j = 0; j < i; j++)
        {
            cout<<i-j+i;
        }
        cout<<endl;
    }
    
//  Diamond

    // int n=9;
    for (int i = 1; i <=n; i++)
    {
        for(int j=0; j < n-i; j++)
        {
            cout<<" ";
        }
        for (int j = 0; j < 2*i-1; j++)
        {
            cout<<"*";
        }
        cout <<endl;
    }
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            cout<<" ";
        }
        
        for (int j = 0; j < 2*(n-i-1)-1; j++)
        {
            cout<<"*";
        }
        cout <<endl;
    }
    
//  Selection sort
    // int arr[7]= {7,8,1,2,5,9,6};
    // int arr[12]= {2,5,15,1,25,1,2,5,2,5,2,5};
    // int arr[20]= {2,5,15,1,25,1,2,5,2,5,2,5,20,51,63,23,61,11,32,63};
    // ssort(arr,sizeof(arr)/4);
    // for (int i = 0; i < sizeof(arr)/4; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }

//  Insertion sort
    // isort(arr,sizeof(arr)/4);
    // for (int i = 0; i < sizeof(arr)/4; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;


    // int ar[5]= {1,3,5,7,9};
    // int arr[6]= {2,4,6,8,10,12};
    // int ans[(sizeof(arr)+sizeof(ar))/4]={0};
    // Merge(arr,ar, sizeof(arr)/4, sizeof(ar)/4, ans);
    // for (int i = 0; i < sizeof(ans)/4; i++)
    // {
    //     cout<<ans[i]<<" ";
    // }
    // cout <<endl;

    int arr[]={1,4,3,5,2,2,52,51,25,2,51,5,2,21,52,52};

//  Merge sort
    // int arr[]={1,4,3,5,2,2,52,51,25,2,51,5,2,21,52,52};
    // msort(arr,0, sizeof(arr)/4 -1);
    // for (int i = 0; i < sizeof(arr)/4; i++)
    // {
    //     cout<< arr[i] <<" ";
    // }

//  Quick sort
    // qsort(arr,0,sizeof(arr)/4 -1);
    // for (int i = 0; i < sizeof(arr)/4; i++)
    // {
    //     cout<< arr[i] <<" ";
    // }


//  Subsequent String
    // string s= "abc";
    // string output[100];
    // int size = ss(s, output);
    // for (int i = 0; i < size; i++)
    // {
    //     cout<<output[i]<<endl;
    // }
    // cout <<endl;
    

//  Keypad-Dial
    // int x; cin>>x;
    // string output[100];
    // int count = dial(x, output);
    // for (int i = 0; i < count; i++)
    // {
    //     cout<< output[i] <<endl;
    // }
    
//  Subse...
    string input= "abcd";
    subsequenter(input);

    return 0;
}

