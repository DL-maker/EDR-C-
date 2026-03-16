#include <stdio.h>
#include <string.h>
#include <limits.h>

int main(void)
{
	char lists[] = {22, 55, 33, 66, 77, 88, 99, 11};
    int max = INT_MIN;
    int max2 = 0;
    int n = sizeof(lists) / sizeof(lists[0]);
    
    for (int i = 0; i < n; i++){
        if (lists[i] > max){
            max2 = max;
            max = lists[i];
        };
    };
    printf("Le deuxieme nombre le plus gran c'est : %d\n", max);
    printf("Le deuxieme nombre la deuxieme plus grand c'est : %d\n", max2);
    return 0;
};
