## Let's build a basic Makefile

First, [write a basic C program](../c-program/README.md).

Now create another text file (named `Makefile`) and type this into it:

```make
a.out: prog.c
	gcc prog.c

clean:
	rm -f a.out

.PHONY: clean
```

Note that the indentation must be made using tab characters, not spaces (`make` won't work correctly if you use spaces).

Use `make` to compile your C program.  [Run this in a terminal](../terminal/README.md):

```
$ make
```

The first time you run this command, you should see this:

```
$ make
gcc prog.c
```

If you run this program a second time, you should see this:

```
$ make
make: `a.out' is up to date.
```

This is because in our `a.out` rule, we listed a dependency of `prog.c`.  `make` has detected that `gcc` doesn't need to be run, because `prog.c` hasn't been changed since the last time `make` was run.

If you make a small change to `prog.c` (and the save the file), and then run `make` a third time, it will detect that ``prog.c` has been changed more recently then `a.out`, which will cause it run `gcc` to create an updated `a.out`.

Now, clean up by removing the compiled `a.out` program.  Type `make clean`:

```
$ make clean
rm -f a.out
```

