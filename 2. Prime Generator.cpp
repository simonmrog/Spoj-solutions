#include <stdio.h>
#include <cstring>
#include <math.h>

const int MAX = 32000;
int primes[4000];

/*A number always can be written as a product of prime numbers, and also as a number greater to its square root
multiplied by a number smaller to its square root, this is the reason why we only test divisibility for prime
numbers in the range 1 to sqrt(n)*/

void sieve_of_erastothenes();   //fills an array with the prime numbers between 2 and 31999

int main(){
    int i, j, l, t, m, n;
    bool flag;
    scanf("%d", &t);    //reads number of cases
    sieve_of_erastothenes();    //fills the array
    for (l=0; l<t; l++){
        scanf("%d %d", &m, &n); //reads data
        if (m < 2) m = 2;   //there is no prime numbers less than two
        for (i=m; i<=n; i++){ //We check for divisibility by prime numbers in the range 1 to sqrt(i)

            //tests the rest between until the square root is reached
            for (j=0, flag=true; primes[j]*primes[j]<=i and flag; j++)

                if (i % primes[j] == 0) flag = false;
            if (flag) printf("%d\n", i);
        }
        printf("\n");
    }
    return (0);
}

void sieve_of_erastothenes(){
    int k = 0, flags[MAX];
    memset(flags, true, sizeof(flags));
    flags[0] = flags[1] = false;    //zero and one are not prime numbers
    for (int i=2; i<MAX; i++)
    if (flags[i]){
        primes[k++] = i;    //adds a prime number to the array
        for (int j=2; i*j < MAX; j++) flags[i*j] = false;
    }
}
