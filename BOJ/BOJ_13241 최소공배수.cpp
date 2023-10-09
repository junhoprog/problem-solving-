#include<iostream>
using namespace std;

long long gcd(int a, int b) {
    int temp;

    if (a < b)//a¸¦ Å©°Ô ¸¸µê
    {
        temp = a;
        a = b;
        b = temp;
    }
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

long long cal(long long a, long long b) {
    return (a * b) / gcd(a, b);
    //20*30/10
}


int main() {
    long long a, b;

    cin >> a >> b;
    cout << cal(a, b) << endl;
}
