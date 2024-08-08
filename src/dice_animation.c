#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "../include/structures.h"


void dice_animation(struct ASCII ascii[DICE_PERM], struct user user, int DICE) {
    strcpy(ascii[0].ASCII, "---------\n|\t|\n|   O\t|\n|\t|\n---------\n");
    strcpy(ascii[1].ASCII, "---------\n|O\t|\n|\t|\n|      O|\n---------\n");
    strcpy(ascii[2].ASCII, "---------\n|O\t|\n|   O   |\n|      O|\n---------\n");
    strcpy(ascii[3].ASCII, "---------\n|O     O|\n|\t|\n|O     O|\n---------\n");
    strcpy(ascii[4].ASCII, "---------\n|O     O|\n|   O   |\n|O     O|\n---------\n");
    strcpy(ascii[5].ASCII, "---------\n|O     O|\n|O     O|\n|O     O|\n---------\n");

    for (int i = 0; i < DICE_PERM; i++) {
        printf("\033[1;1H"); // move to row 10 col 1
        printf("Placing your bet.\n");// move to row 10 col 1
        printf("\033[0J");
        printf("%s", ascii[i].ASCII);
        usleep(400000);
    }
    printf("\033[1;1H");
    printf("\033[0J");
    if (user.guess != DICE) {
        printf("\x1b[38;5;196m");
        printf("%s", ascii[user.guess - 1].ASCII);
        printf("\x1b[1;39m");
    } else {
        printf("\x1b[38;5;46m");
        printf("%s", ascii[user.guess - 1].ASCII);
        printf("\x1b[1;39m");
    }
}
