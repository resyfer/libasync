#include <include/async.h>
#include <sys/sysinfo.h>

void
async_init(void)
{
	int n = get_nprocs_conf();
	if(n > 1) {
		n--; // 1 for main thread
	}
	async_pool = tpool_new(n);
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