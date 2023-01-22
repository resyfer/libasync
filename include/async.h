/**
 * @file async.h
 * @brief This header file is the entry point for the library.
 *
 * @author Saurav Pal (resyfer)
 * @bug No known bugs
 */

#ifndef __LIBASYNC_H
#define __LIBASYNC_H 1

/* Personal Libraries */
#include <libtpool/tpool.h>

/**
 * @mainpage
 * This library helps you complete tasks asynchronously.
 */

/**
 * @brief Initialize async
 */
void async_init(void);

/**
 * @brief Asynchronously complete the task `routine`
 *
 * @param routine Task
 * @param args Arguments for the task
 */
void async(routine_t routine, void* args);

/**
 * @brief Wait till all async tasks are completed
 */
void await_all(void);

#endif