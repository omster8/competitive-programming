#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n, q;
    int temp = 0;
    scanf("%i %i", &n, &q);
    int a[n];
    int commandTypes[q];
    int command1[4];
    int command2[3];
    for (int i = 0; i < n; i++) {
        scanf("%i" , &a[i]);
    }
    for (int i = 0; i < q; i++) {
        scanf("%i", &commandTypes[i]);
        if (commandTypes[i] == 1) {
            scanf("%i %i %i %i", &command1[0], &command1[1], &command1[2], &command1[3]);
            for (int j = command1[0]-1; j < command1[1]; j++) {
                if (a[j] > command1[3]) {
                    a[j] -= command1[2];
                }
            }
        } else {
            scanf("%i %i %i", &command2[0], &command2[1], &command2[2]);
            temp = 0;
            for (int j = command2[0]-1; j < command2[1]; j++) {
                if (a[j] > command2[2]) {
                    temp += a[j];
                }
            }
            printf("%i\n", temp);
        }
    }
    
    return 0;
}