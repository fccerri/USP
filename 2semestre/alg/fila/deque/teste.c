#include <stdio.h>
#define mod(a) ((a) > 0 ? (a) : (-1)*(a))


int main () {
    printf("%d", mod(-1%10));
}