#include <stdio.h>
#include "../include/random.h"
#include "../include/structures.h"

// func defns
void dice_animation(struct ASCII ascii[DICE_PERM],struct user user,int DICE);
void random(int max,int min);

int game_logic(struct ASCII ascii[DICE_PERM], struct user user, int DICE){
        printf("\x1b[38;5;33m");
        printf("Your Bet is being Placed......\n");
        printf("\x1b[1;39m");
		DICE = _random(6,0);
        dice_animation(ascii,user,DICE);
		printf("Random Number : %d Your guess : %d\n",DICE,user.guess);
		if (user.guess == DICE) {
			return user.balance += (user.bet * 3);
			printf("CORRECT GUESS :+%d\n",user.bet * 3);
		}
		else{
			return user.balance -= (user.bet * 3);
			printf("WRONG GUESS :-%d\n",user.bet * 3);
			if(user.balance < 0 ){
			    printf("CURRENTLY IN DEBT\n");
			}
		}
}
