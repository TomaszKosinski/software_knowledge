#include <iostream>

using namespace std;

void foo(int &val)
{
    cout<<"Passed by l-value reference:"<<val<<endl;
}

void foo(int &&val)
{
    cout<<"Passed by r-value reference:"<<val<<endl;
}

int returnInt()
{
    return 1000;
}

int main() {
    int a = 100, b = 200;

    // by l-value
    foo(a);
    int &&c = 5;    // "c" becomes l-value
    foo(c);

    // by r-value
    foo(move(a));
    foo(10);
    foo(int(11));
    foo(1+2);
    foo(a+b);
    foo(returnInt());

    return 0;
}