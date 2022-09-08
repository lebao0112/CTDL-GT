
 
#include <stdio.h>
#include <algorithm>
int gcd1(int a, int b){
    // Nếu a = 0 => ucln(a,b) = b
    // Nếu b = 0 => ucln(a,b) = a
    if (a == 0 || b == 0){
        return a + b;
    }
    while (a != b){
        if (a > b){
            a -= b; // a = a - b
        }else{
            b -= a;
        }
    }
    return a; // return a or b, bởi vì lúc này a và b bằng nhau
}
 
int gcd2(int a, int b){
    // Nếu a = 0 => ucln(a,b) = b
    // Nếu b = 0 => ucln(a,b) = a
    if (a == 0 || b == 0){
        return a + b;
    }
    // Lặp tới khi 1 trong 2 số bằng 0
    while (a*b != 0){
        if (a > b){
            a %= b; // a = a % b
        }else{
            b %= a;
        }
    }
    return a + b; // return a + b, bởi vì lúc này hoặc a hoặc b đã bằng 0.
}
 
int gcd3(int a, int b) {
    if (b == 0) return a;
    return gcd3(b, a % b);
}
 
int gcd4(int a, int b) {
    int tmp;
    while(b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
 
int main(){
    int a = 5, b = 9;
    printf("\ngcd1(%d, %d) = %d", a, b, gcd1(a,b));
    printf("\ngcd2(%d, %d) = %d", a, b, gcd2(a,b));
    printf("\ngcd3(%d, %d) = %d", a, b, gcd3(a,b));
    printf("\ngcd4(%d, %d) = %d", a, b, gcd4(a,b));
    printf("\ngcd5(%d, %d) = %d", a, b, std::__gcd(a,b));
}