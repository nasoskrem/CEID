#include<iostream>
using namespace std;
#include "kouti.h"

Kouti::Kouti(double lengthVal, double breadthVal, double heightVal){
    length = lengthVal;
    breadth = breadthVal;
    height = heightVal;
}

double Kouti::calculateOgkos(){
    return (double)(length * breadth * height);
}

int main(){
    double ogkos = 0.0;
    Kouti KoutiA(2.0, 3.2, 6.0);
    Kouti KoutiB(2.5, 4.0, 5.0);

    ogkos = KoutiA.calculateOgkos();
    cout << "O ogkos tou koutiou A einai: " << ogkos << endl;

    ogkos = KoutiB.calculateOgkos();
    cout << "O ogkos tou koutiou B einai: " << ogkos << endl;

    Kouti KoutiC;

    KoutiC = KoutiA + KoutiB;

    ogkos = KoutiC.calculateOgkos();
    cout << "O ogkos tou koutiou C einai: " << ogkos << endl;

    return 0;
}
