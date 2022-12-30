# libasync

A wrapper around [libtpool](https://github.com/resyfer/libtpool). For instructions on usage, please go [here](#usage).

For installation, please go [here](#installation). For documentation, please go [here](#documentation).

## Usage

### TL;DR

The shown below is a tl;dr version. Proper instructions are [here](#step-1)

```c
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
```

Compile and run:

```bash
$ gcc test.c -o test.o -lasync -ltpool -lqueue
$ ./test.o
```
Output:

![image](https://user-images.githubusercontent.com/74897008/210037312-701590ac-0fee-4dbd-806c-fec0c7894471.png)

### Step 1

Import the library:

```c
#include <libasync/async.h>
```

**NOTE**: Link the library and dependencies when compiling

```bash
$ gcc a.c -o a.o -lasync -ltpool -lqueue
```

### Step 2
Define dummy functions of type `routine_t`, ie. `void* fun(void* args)`:
```c
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
```

### Step 3
Initialize async:
```c
async_init();
```

### Step 4
Async:
```c
int a = 1;
async(fun_1, (void*) &a);

async(fun_2, (void*) &(int) {2});
```

### Step 5
Finish Async:
```c
await_all();
```

## Installation

Make sure to have [make](https://www.gnu.org/software/make/), [gcc](https://www.gnu.org/software/gcc/) and [git](https://git-scm.com/) installed.

Install the following dependencies first:
- [libtpool](https://github.com/resyfer/libtpool)
- [libqueue](https://github.com/resyfer/libqueue)

```bash
git clone https://github.com/resyfer/libasync.git
cd libasync
make install
cd ..
rm -rf libasync
```

Provide the password when prompted.

## Documentation

### Initialize
```c
void async_init(void);
```

### Async
```c
void async(routine_t routine, void* args);
```

### Finish
```c
void await_all(void);
```
