#include <iostream>
using namespace std;

struct club
{
    int max;
    int min;
};

int main() {


	struct club ans;
    ans.min= INT_MAX;
    ans.max= INT_MIN;
	std::cout << "How many elements you want in array : " << std::endl;
	
	int n; cin>>n;
	int arr[n];
	for (int i = 0; i < n; i++) 
    {
	    cin>>arr[i];
	}

    for (int i = 0; i < n; i++)
    {
        if(arr[i]> ans.max) ans.max= arr[i];
        if(arr[i]< ans.min) ans.min= arr[i];
    }

    cout<< "The smallest no. in array is : " <<ans.min<<endl;
    cout<< "The largest no. in array is : " <<ans.max<<endl;
	
	return 0;
}
