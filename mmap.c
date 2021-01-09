#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

#define PAGESIZE 4096

int main() {
    for(int i=0; i<5; i++) {
        char *ptr = malloc(5000000);
        //printf("Got memory! (Address=%p)\n", ptr);
    }

    void *first = sbrk(0);
    void *second = sbrk(4096);
    void *third = sbrk(0);

    //seg fault
    int *ptr = (int *)third+1;
    //*ptr = 0xDEAD;

    printf("First: %p\n", first);
    printf("Second: %p\n", second);
    printf("Third: %p\n", third);

    u_int8_t* map_first = mmap(NULL, PAGESIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    u_int8_t* map_second = mmap(NULL, PAGESIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    printf("First: %p\n", map_first);
    printf("Second: %p\n", map_second);
}
