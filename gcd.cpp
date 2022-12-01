#include"template.h"

int gcd(int a, int b) {
    int r = a % b;
    while(r != 0) {
        a = b;
        b = r;
        r = a %b; 
    }   
    return b;
}

int main() {
    srand(time(NULL));
    symbolic_int x, y;
    std::cout << "x is " << x << std::endl;
    std::cout << "y is " << y << std::endl;

    std::cout << gcd(x, y) << std::endl;
    return 0;
}
