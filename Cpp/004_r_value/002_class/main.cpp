#include <iostream>

using namespace std;

class MyClass {
public:
    MyClass() {
        cout<<"MyClass() Constructor\n";
    }
    ~MyClass() {
        cout<<"~MyClass() Destructor\n";
    }
    MyClass(const MyClass &rhs) {
        cout<<"MyClass(const MyClass &rhs) Copy Constructor\n";
    }
    MyClass(const MyClass &&rhs) {
        cout<<"MyClass(const MyClass &&rhs) Move Constructor\n";
    }

    MyClass& operator=(const MyClass &rhs) {
        cout<<"MyClass& operator=(const MyClass &rhs) Assignment operator"<<endl;
        if (this == &rhs) {
            cout<<"The same object used in assignment operator"<<endl;
            return *this;
        }
        return *this;
    }

    MyClass& operator=(const MyClass &&rhs) {
        cout<<"MyClass& operator=(const MyClass &&rhs) Move Assignment operator"<<endl;
        if (this == &rhs) {
            cout<<"The same object used in Move Assignment operator"<<endl;
            return *this;
        }
        return *this;
    }

};

MyClass globalClass;

MyClass funcReturningClass() {
    return globalClass;
}

MyClass funcReturningTempClass() {
    MyClass obj;
    return obj;
}

int main() {
    cout<<"********** Constructor expected **********" << endl;
    MyClass myClass;

    cout<< endl <<"********** Copy Constructor expected **********" << endl;
    MyClass myAnotherClass = myClass;
    MyClass myAnotherClass2 = funcReturningClass();
    MyClass myAnotherClass3{myAnotherClass2};

    cout<< endl<<"********** Move Constructor expected **********" << endl;
    MyClass myAnotherClass4 = move(myClass);
    
    cout<< endl<<"********** Assignment operator expected **********" << endl;
    myAnotherClass = myClass;

    cout<< endl<<"********** Move Assignment operator expected **********" << endl;
    myAnotherClass = move(myClass);
    //MyClass myAnotherClass5 = funcReturningTempClass();   // Compiler optimization?

    cout<< endl<<"********** Destructor expected **********" << endl;
    return 0;
}