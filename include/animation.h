#ifndef ANIMATION_H_
#define ANIMATION_H_

#define DICE_PERM 6

struct user {
    int guess;
    int bet;
    int balance;
};

struct ASCII {
    char ASCII[60];
};

void dice_animation(struct ASCII ascii[DICE_PERM], struct user user, int DICE);

#endif
