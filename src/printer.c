#include "my_library.h"
#include <pthread.h>

void* print_thread(void* arg) {
    print_hello();
    print_world();
    return NULL;
}

void print_hello_world_concurrently() {
    pthread_t thread;
    pthread_create(&thread, NULL, print_thread, NULL);
    pthread_join(thread, NULL);
}
