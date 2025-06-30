// IN-BUILT SORT FUNCTION

#include<iostream>
#include<algorithm>
using namespace std;

class edge
{
    public:
    int x; int y; int z;

    edge() {}
    edge(int x, int y, int z): x(x), y(y), z(z) {}
};


// NOTE : WE CAN ALSO MAKE A "COMPARATOR" WITH MULTIPLE CONSTRAINTS!!, like I have made "myComparator" , here , if there are 2 "edge" class objects, then they will be sorted in "asceding order" of their "x" values!, but!, if their "x" values are same... they the one with smaller "y" value will be present first (i.e. all elements with their "x" value same will be sorted in ascending order of their y values :) .. now if their "y" value is also same! then they will  be sorted in the ascending order of their "z" values :) ... THAT'S WHAT I HAVE WRITTEN IN THE "myComparator" , Ofcourse, u can make your own changes and  u could have had say if ("x values" are same then sort in descending order of y values or anything else :)

bool myComparator(edge one, edge two)
{
    if(one.x != two.x)
    {
        return one.x < two.x;
    }

    else if(one.y != two.y)
    {
        return one.y < two.y;
    }

    else
    {
        return one.z < two.z;
    }
}



bool compare(int a, int b)      // if this fn passed as 3rd argument, it would  
{                               // turn the sorting to descending!!
    return a>b;
}

bool comparatorxyz(edge a, edge b)
{
    return a.z < b.z;               // so, this will sort on the basis of "z" of each "edge         
                                    // container"
}

bool sumxyz(edge a, edge b)
{
    return a.x + a.y + a.z < b.x + b.y + b.z;
}

int main(){

    // SORT

    // Here, the sort function uses "INTROSORT" , 
    // INTROSORT= QUICK SORT + HEAP SORT + INSERTION SORT

    // THE SORT FUNCTION TAKES 2 OR 3 ARGUMENT,

    int arr[5]={1,3,2,5,4};


    sort(arr, arr+5);       // will sort 0,1,2,3,4 indices
                    // for vector it would have been "sort(v.begin(), v.end());"
    cout<< "Sort Ascending" <<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<< arr[i] <<" ";
    }
    cout <<endl;
    
    cout<< "Sort Descending" <<endl;
    // Now, this sort is ascending order by default, we can turn it into descending, and infact make some amazing changes using our own created function "compare", which will be passed as the third argument;


    sort(arr, arr+5, compare);

    for (int i = 0; i < 5; i++)
    {
        cout<< arr[i] <<" ";
    }
    cout <<endl;
    


    // Now, we can also sort our own custom-made containers!
    // I created a container called "edge", which stores 3 integers, x,y,z , now how will we sort such ambiguous thing?? , we are going to use "comparator", our own hand-made function and going to pass it as the 3rd argument, this comparator will tell on what basis sorting has to be done, we named our comparator function  "comparatorxyz" , it will sort the "edges" on increasing order of their "z" value

    edge* cobra= new edge[5];

    for (int i = 0; i < 5; i++)
    {
        int x,y,z; cin>>x>>y>>z;
        edge somu(x,y,z);

        cobra[i] =somu;
    }
    
    cout<< "Before sorting:" <<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<< cobra[i].x<<" "<< cobra[i].y<<" "<< cobra[i].z<<endl;
    }
    cout <<endl;
    cout<<"After sorting on the basis of ascending order of 'z' " <<endl;
    sort(cobra, cobra+5, comparatorxyz);
    
    for (int i = 0; i < 5; i++)
    {
        cout<< cobra[i].x<<" "<< cobra[i].y<<" "<< cobra[i].z<<endl;
    }


    // Now we r going to write a "comparator" which will sort on the basis of sum of its "x, y, z values"..

    sort(cobra, cobra+5, sumxyz);

    cout<<"After sorting on the basis of ascending order of sum of x,y,z " <<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<< cobra[i].x<<" "<< cobra[i].y<<" "<< cobra[i].z<<endl;
    }


    return 0;
}
// 1 2 3
// 2 3 8
// 12 58 24
// 42 92 84
// 24 32 98

