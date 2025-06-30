// SORTED ARRAY

#include<iostream>
#include<cmath>
using namespace std;

bool chk(int p[] ,int size){
    if( size == 1  ||  size ==0){return true ;}
    if(p[0]> p[1]){return false ;}

    else{return chk(p+1 , size-1);}
}

 
int main(){
    int arr[]={1,3,5,32,321,2};
    int size= (sizeof(arr))/4;

    if(chk(arr, size)) {cout<< "Yes its sorted!!!!" <<endl;}
    else{cout<< "No , not sorted" <<endl;}

    // cout<< chk(arr) <<endl;

    

    return 0;
}