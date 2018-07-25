## Let's build a program written in [C](https://en.wikipedia.org/wiki/C_(programming_language))

Create a text file named `prog.c` and type this into it:

```c
int main(void) {
    return 0;
}
```

Compile it.  [Run this in a terminal](../terminal/README.md):

```sh
$ gcc prog.c
```

You should now see a file named `a.out` in that directory, which is the compiled executable.

Run it:

```
./a.out
```

C programs begin execution by running the `main` function.

The `int` in `int main()` indicates the return value of `main` is an `int`.  The convention is that 0 is returned if the program was successful, while any non-zero return value indicates the program failed for some reason.

Rather than use the [magic number](https://en.wikipedia.org/wiki/Magic_number_(programming)) '0', we can instead use the `EXIT_SUCCESS` constant defined in `stdlib.h`:

```
$ cat /usr/include/stdlib.h | grep EXIT_
#define	EXIT_FAILURE	1
#define	EXIT_SUCCESS	0
```

Here's the revised `prog.c`:

```c
#include <stdlib.h>

int main(void) {
    return EXIT_SUCCESS;
}
```
