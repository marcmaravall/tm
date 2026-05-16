#include "tm.h"

#ifdef TM_POSIX

void tm_thread_create (tm_thread_t* thread, tm_fn_t fn, tm_arg_t arg) {
    pthread_create(thread, NULL, fn, arg);
}

void tm_thread_join   (tm_thread_t  thread, void* _return) {
    pthread_join(thread, _return);
}

void tm_mutex_lock    (tm_mutex_t* mutex) {
    pthread_mutex_lock(mutex);
}

void tm_mutex_unlock  (tm_mutex_t* mutex) {
    pthread_mutex_unlock(mutex);
}

void tm_cond_wait     (tm_cond_t* cond, tm_mutex_t* mutex) {
    pthread_cond_wait(cond, mutex);
}

void tm_cond_signal   (tm_cond_t* cond) {
    pthread_cond_signal(cond);
}

#else
#warning "Current platform is not supported!"
#endif
