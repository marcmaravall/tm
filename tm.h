#ifndef TM_H
#define TM_H

#ifdef _WIN32   // WINDOWS IMPLEMENTATION:
                // TODO: implement 
#define TM_WINODWS

#else   // POSIX IMPLEMENTATION:
#define TM_POSIX

#include <time.h>
#include <unistd.h>
#include <pthread.h>

typedef pthread_t       tm_thread_t;
typedef pthread_mutex_t tm_mutex_t;
typedef pthread_cond_t  tm_cond_t;

#define tm_sleep_s(s) usleep((s) * 1000000);

#endif

typedef void*(tm_fn_t)(void*);
typedef void* tm_arg_t;

// public api:

void tm_thread_create (tm_thread_t* thread, tm_fn_t fn, tm_arg_t arg);
void tm_thread_join   (tm_thread_t  thread, void* _return);

// void tm_sleep_s       (const double seconds);

void tm_mutex_lock    (tm_mutex_t* mutex);
void tm_mutex_unlock  (tm_mutex_t* mutex);

void tm_cond_wait     (tm_cond_t* cond, tm_mutex_t* mutex);
void tm_cond_signal   (tm_cond_t* cond);

// -----------

#endif // TM_H
