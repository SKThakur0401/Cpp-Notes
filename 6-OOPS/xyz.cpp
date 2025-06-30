#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int arr[10] = {1,2,4,5,6,1,3,7,9,10};

Desired output : 1,2,4,5,6,3,7,9,10



int main(){

    int arr[10] = {1,2,4,5,6,1,3,7,9,10};
    vector<int> output;

    for (int i = 0; i < 10; i++)
    {
        int curr= arr[i];
        bool isAlreadyPresent=false;

        for(int j= i-1; j>=0; j--)
        {
            if(arr[j] == curr) isAlreadyPresent= true;
        }
        if(!isAlreadyPresent) output.push_back(arr[i]);
    }

    for (int i = 0; i < output.size(); i++)
    {
        cout<< output[i] <<"  ";
    }
    return 0;
}

