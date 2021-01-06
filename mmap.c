#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    for(int i=0; i<5; i++) {
        char *ptr = malloc(5000000);
        //printf("Got memory! (Address=%p)\n", ptr);
    }

    void *first = sbrk(0);
    void *second = sbrk(4096);
    void *third = sbrk(0);

    printf("First: %p\n", first);
    printf("Second: %p\n", second);
    printf("Third: %p\n", third);
}
