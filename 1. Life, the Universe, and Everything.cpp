#include <cstdio>

//The problem consists in reading and printing data until the number 42 appears

int main()
{
    int n;
    while(scanf("%d", &n) and n != 42) printf("%d\n", n);
    return (0);
}
