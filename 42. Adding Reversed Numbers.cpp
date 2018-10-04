#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int reverse_number(int); //reverses the number
int number_power(int); //finds the power of the number

int main(){
    int n;
    int x, y;
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        scanf("%d %d", &x, &y);
        x = reverse_number(x);
        y = reverse_number(y);
        printf("%d\n", reverse_number(x + y));
    }
    return (0);
}

int number_power(int number)
{
    if (number >= 1e9) return 9;
    else if (number >= 1e8) return 8;
    else if (number >= 1e7) return 7;
    else if (number >= 1e6) return 6;
    else if (number >= 1e5) return 5;
    else if (number >= 1e4) return 4;
    else if (number >= 1e3) return 3;
    else if (number >= 1e2) return 2;
    else if (number >= 1e1) return 1;
    else return 0;
}

int reverse_number(int number){
    int n = number_power(number);
    int result = 0, power;
    for (int i=0; i <= n; i++){
        power = floor(pow(10, n-i)); //the floor function is used to avoid
                                     //problems with the pow functions which returns a double
        result = result + (number % 10)*power;
        number = number / 10;
    }
    return result;
}
