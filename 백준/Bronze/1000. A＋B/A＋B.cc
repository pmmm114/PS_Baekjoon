#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    if((0<a && a<10) && (0<b && b<10)) {
        cout << a+b << endl;
    }
    return 0;
}