#include <stdio.h>

int Z(int);

int main(){
    int t, N;
    scanf("%d", &t);
    for (int i=0; i<t; i++){
        scanf("%d", &N);
        printf("%d\n", Z(N));
    }
    return (0);
}

int Z(int N){
    int n = 0, counter = 0;
    for (int k=5; k<=N; k*=5) //the limit of K is log5(N), its comes from the inequality N/5^k > 1
        counter = counter + N/k; //the number of fives determines the number of zeros
    return counter;
}
