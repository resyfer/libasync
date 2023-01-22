#include <include/async.h>
#include <sys/sysinfo.h>

static tpool_t *async_pool;

void
async_init(void)
{
	async_pool = malloc(sizeof(tpool_t));
	int n = get_nprocs_conf();
	if(n > 1) {
		n--; // 1 for main thread
	}
	tpool_new(async_pool, n);
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