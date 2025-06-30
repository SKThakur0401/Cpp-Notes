#include<iostream>
using namespace std;
int f(int x){     //HERE WE DEFINED A FUNCTION "f(x)" , where "x" is an integer #NOTE!!! : HERE WE WRITE "int f(x)"....THE "int" is to declare that the return value will be of integer data type.
    int a;
    int y=1, z=1;
    for(y=1;y<=x;y++){
        z*=y;
    }
    return z;
}


int main(){            //NOTE: Like any other function, main is also a function but with a special characteristic that the program execution always starts from the 'main'. ... int main – 'int main' means that our function needs to return some integer at the end of the execution and we do so by returning 0 at the end of the program.
                      // WE CAN ALSO USE "void main()" The void main() indicates that the main() function will not return any value, but the int main() indicates that the main() can return integer type data. When our program is simple, and it is not going to terminate before reaching the last line of the code, or the code is error free, then we can use the void main()

    for(int i=1; i<10; i++){
        cout<<f(i)<<endl;
    }
}