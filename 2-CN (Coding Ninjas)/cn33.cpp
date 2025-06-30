#include<iostream>
#include<cmath>
#include<string>
using namespace std;

bool compare(char a, char b){
    return (int)a < (int)b;
} 

int main(){
    // cout<< ('9' >'4') <<endl;

    // int n;
    // cout<< "Enter ur fav int : " <<endl;
    // cin>>n;
    // string s= to_string(n);
    string st= "1283"; 

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>arr[i];
        }
    }
    
    for (int i = st.size()-1 ; i <=0; i--)
    {
        for (int j = 0; j <i ; j++)
        {
            char s1= st[j];
            char s2= st[j+1];

            if (compare(s1, s2))
            {
                char temp = st[j];
                st[j]=st[j+1];
                st[j+1]=temp;
            }
        }
    }
    

    cout<< st <<endl;



    // string testing= "123";
    // if(testing[0]<testing[1]){
    //     char temp= testing[0];
    //     testing[0]= testing[1];
    //     testing[1]= temp;
    // }
    // cout<< testing <<endl;
    return 0;
}