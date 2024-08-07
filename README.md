## ASCII Based Dice Game in C
This is my first time creating a Gambling type Dice game in **C**. 
## Headerfiles
 -  `stdlib`
 - `Unistd`
 - `stdio`
 - `random.h` 
## random.c

The random number function , although there is a builtin random function in C but it required some tweaking so i made it into a seperate function
```C
#include<stdlib.h>
#include "rand.h"

int _random(int max,int min){
    //rand() % (max_number + 1 - minimum_number) + minimum_number
    return rand() % (max + 1 - min) + min;
}
```
## ESCAPE CODES

I also used some ANSI escape codes , 
[REFERENCE](https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797)

|  |ESCAPE CHARACTER CODE  |
|--|--|
|  RED| `\x1b[38;5;196m`    |
|  GREEN| `\x1b[38;5;46m`	 |
|  BLUE| `\x1b[38;5;33m`    |
| DEFAULT| `\x1b[1;39m` |


