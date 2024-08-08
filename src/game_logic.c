#include <stdio.h>
#include "../include/random.h"
#include "../include/structures.h"

// func defns
void dice_animation(struct ASCII ascii[DICE_PERM],struct user user,int DICE);
void random(int max,int min);

int game_logic(struct ASCII ascii[DICE_PERM], struct user user, int DICE){
		DICE = _random(6,0);
        dice_animation(ascii,user,DICE);
        printf("Your Guess : %d Random Number : %d\nYour Bet: %d\n",user.guess , DICE,user.bet);
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
