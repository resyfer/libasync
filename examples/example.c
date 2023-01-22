#include <libasync/async.h>
#include <stdio.h>
#include <unistd.h> /* for sleep() */

void* fun_1(void* args) {
	int *i = args;
	sleep(1);
	printf("Function 1: %d\n", *i);
}

void* fun_2(void* args) {
	int *i = args;
	sleep(3);
	printf("Function 2: %d\n", *i);
}

int main() {

	async_init();

	int a = 1;
	async(fun_1, (void*) &a);
	async(fun_2, (void*) &(int) {2});

	sleep(2);
	printf("Hello World\n");

	await_all();
	return 0;
}