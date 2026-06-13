#include <iostream>

// w c++11 tylko jeden return, może być (?:), wołanie innych funkcji constexpr, ale żadnych if,switch,while 
// można wołać dla zmiennych, ale wtedy odliczane w runtime
// const expr: nie może mieć żadnych skutków ubocznych (zmiana zmienych)
// constexpr: dla rzeczy które sami potrafimy obliczyć pisząc kod
// funkcja moze odebraćprzez stałą referencję, żeby nie kopiopwać dużych obiektów

// dla klas
// W c++11 konstruktor constexpr nie może mieć ciała, ale może mieć listę inicjalizacyjną

using namespace std;


constexpr int power(int val);  //  wystarczy deklaracja bo nie używamy w koltekscie constexpr, ale error po dodaniu : constexpr int val5 = power(10);
//constexpr bool czy_alfabetycznie(char a, char b); // a tu nie wystarczy !!!!
bool zwykla_funkcja(char a, char b);

constexpr bool czy_alfabetycznie(char a, char b) {
    
    // mamy funkcję constexpr, ale tylko ale warunku "true", inaczej jest nie-constexpr
    return a<b ? true : zwykla_funkcja(a,b);
}


int main() {
    int val = 3;
    cout<<"Power of literal 2 =  "<<power(2)<<"\n";  // constexpr 
    cout<<"Power of local variable 3 = "<<power(val)<<"\n";  // Możesz zawołąć dla zwykłych zmiennych również
   
    // połowa funkcji constexpr a połowa nie
    constexpr bool val1 = czy_alfabetycznie('a', 'b');  // tu jest ok, bo kod idzie w ścieżkę constexpr
    bool val2 = czy_alfabetycznie('b', 'a');  // tu jest ok, bo kod NIE idzie w ścieżkę constexpr, ale przypisujemy do zwykłej
    //constexpr bool val3 = czy_alfabetycznie('b', 'a');  // To już nie zadziała bo zmienna jest constexpr a idziemy w ścieżkę nie-constexpr
}

// prosty case
constexpr int power(int val) {
    return val*val;
}

// połowa funkcji constexpr a połowa nie

bool zwykla_funkcja(char a, char b){
    cout<<"To jnie jest funkcja constexpr"<<endl;
    return false;
}

// constexpr bool czy_alfabetycznie(char a, char b) {
    
//     // mamy funkcję constexpr, ale tylko ale warunku "true", inaczej jest nie-constexpr
//     return a<b ? true : zwykla_funkcja(a,b);
// }