#include <include/async.h>
#include <sys/sysinfo.h>

void
async_init(void)
{
	async_pool = tpool_new(get_nprocs_conf() - 1); // 1 for main thread
}

void
async(routine_t routine, void* args)
{
	tpool_push(async_pool, routine, args);
}

void
await_all(void)
{
	tpool_finish(async_pool);
}