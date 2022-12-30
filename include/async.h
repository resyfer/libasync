#ifndef __LIBASYNC_H
#define __LIBASYNC_H

#include <libtpool/tpool.h>

static tpool_t *async_pool;

void async_init(void);

void async(routine_t routine, void* args);

void await_all(void);

#endif