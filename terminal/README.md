## Let's run a command in the terminal

In some of these tutorials, you may be asked to "run this in a terminal", and you may see something like this:

```
$ gcc -o foo foo.c
```

This is typically asking you to:
- Start your terminal emulator program
  - On a Mac, this would be the `terminal.app` program which comes with your Mac.
  - On a Linux box, this might be `xterm`, `gnome-terminal`, or `konsole`.
- `cd` to the appropriate directory
  - Above, if you had been instructed to create a file named `foo.c` and then run the above `gcc` command, it is expected that you will navigate to the directory in which `foo.c` was created.
  - For example, if I had created `foo.c` in my "home" directory, simply opening a terminal would place me into the correct directory.
  - If I had created `foo.c` in the `/tmp` directory, I would need to run `cd /tmp` in my terminal.
- Type the command into the terminal and then run the command by pressing `enter`.
  - Note that you don't type the `$` -- that's just to indicate the terminal prompt.  You would type out `gcc -o foo foo.c` and then hit `enter`.

You may also see this "terminal" notation used when a tutorial is trying to convey what happens when you run a command:

```
$ abracadabra
-bash: abracadabra: command not found
```

Here, if you were type `abracadabra` into a terminal and hit `enter`, your terminal should print out the same response above.
