# Interview Questions 
### 1. Intro
> Here is a computer with a compiler and an editor. Please implement "hello world." Once you have the basic version working, add in the functionality to get a name from the command line. Finally, tell me what happens before your code executes-- in other words, before the main() function.

``` C
// basic Hello world version
#include <stdio.h>

int main() {
    printf("Hello World!\n")
}
```

``` C
// Add func for cmd line input 
#include <stdio.h>

int main() {
    char[10] buf;
    askInput = getLine ("Enter string!\n", buff, sizeof(buff));

    printf("Hello %s\n")
}
```

Before our code executes, the compiler first considers header files and links their source files to this target so that any functions not defined in our source file have definitions. Then it allocates space on the stack so that this code can be run. Symbols are loaded and our operating system allows the program to run? 