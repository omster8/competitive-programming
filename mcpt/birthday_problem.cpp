#include <iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int temp;
    scanf("%i", &temp);
    long long n;
    scanf("%lli", &n);
    
    for (long long i = 0; true; i++) {
        if ((1103515245*i + 12345) % 2147483648 == n) {
            printf("%lli", i);
            break;
        }
    }

    return 0;
}