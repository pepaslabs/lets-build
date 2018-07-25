## Let's build a C program which reads `stdin` into a buffer

Prerequisites:
- [Let's build a program written in C](../c-program/README.md)
- [Let's build a basic Makefile](../makefile/README.md)

Create a [basic C program](../c-program/README.md) named `stdin.c`:

```c
#include <stdlib.h>

int main(void) {
    return EXIT_SUCCESS;
}
```

We'll start off by creating a [statically allocated](https://en.wikipedia.org/wiki/Static_variable) buffer of 10[KiB](https://en.wikipedia.org/wiki/Kibibyte):

```c
char buffer[10 * 1024];
```

Read up to 10KiB from `stdin` by calling `fread()`:

```c
fread(buffer, sizeof(char), stdin);
```

`fread` is defined in `stdio.h`.

```c
#include <stdio.h>
```

```
$ cat /usr/include/stdio.h | grep fread
size_t	 fread(void * __restrict, size_t, size_t, FILE * __restrict);
```

Read about the specifics of how to use `fread` by opening its [man page](https://en.wikipedia.org/wiki/Man_page):

```
$ man fread
```

If something went wrong with `fread`, print out the error and exit:

```c
if (ferror(stdin)) {
    perror("Error reading from stdin");
    exit EXIT_FAILURE;
}
```

The code thus far:

```c
#include <stdlib.h>
#include <stdio.h>

char buffer[10 * 1024];

int main(void) {
    fread(buffer, sizeof(char), sizeof(buffer), stdin);
    if (ferror(stdin)) {
        perror("Error reading from stdin");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
```

Build your program using a `[Makefile](../makefile/README.md)`:

```make
a.out: stdin.c
	gcc -Wall -Werror stdin.c

clean:
	rm -f a.out

.PHONY: clean
```

```
$ make
```

Run your program:

```
$ ./a.out
```

You can type text into it, which it will read and store into `buffer`.  Type CONTROL+d (which sends the [EOF character](https://en.wikipedia.org/wiki/End-of-file) to your terminal) to terminate the input and quit `a.out`.

You can also pipe random data into your program:

```
$ cat /dev/urandom | ./a.out
```

`a.out` will read 10,239 characters from `stdin`, then terminate the `buffer` with a NULL character.

(Note that this is technically an [off-by-one error](https://en.wikipedia.org/wiki/Off-by-one_error), since the goal was to read 10,240 characters!).
