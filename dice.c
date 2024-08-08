// DICE GAME
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>
#include "./include/rand.h"

#define DICE_PERM 6


struct user{
	int bet;
	int guess;
	int balance;
}user;

struct ASCII {
    char ASCII[60];
}ascii[DICE_PERM];

int DICE , bet_return ,random_return ;


void dice_animation() {
    strcpy(ascii[0].ASCII, "---------\n|\t|\n|   O\t|\n|\t|\n---------\n");
    strcpy(ascii[1].ASCII, "---------\n|O\t|\n|\t|\n|      O|\n---------\n");
    strcpy(ascii[2].ASCII, "---------\n|O\t|\n|   O   |\n|      O|\n---------\n");
    strcpy(ascii[3].ASCII, "---------\n|O     O|\n|\t|\n|O     O|\n---------\n");
    
    strcpy(ascii[4].ASCII, "---------\n|O     O|\n|   O   |\n|O     O|\n---------\n");
    strcpy(ascii[5].ASCII, "---------\n|O     O|\n|O     O|\n|O     O|\n---------\n");

for(int i = 0; i < DICE_PERM; i++){
        printf ( "\033[10;1H"); // move to row 10 col 1
        printf ( "\033[0J");
        printf("%s",ascii[i].ASCII);
        sleep(1);
}
    printf ( "\033[10;1H");
    printf ( "\033[0J");
    if (user.guess != DICE){
        printf("\x1b[38;5;196m");
       printf("%s",ascii[user.guess-1].ASCII);
        printf("\x1b[1;39m");
    }else{
        printf("\x1b[38;5;46m");
        printf("%s",ascii[user.guess-1].ASCII);
        printf("\x1b[1;39m");
    }

}

int _random(int max,int min);

void error(){
    if(user.guess < 1 || user.guess > 6){
  		printf("Your guess should be within 1 to 6\n");
        printf("Your guess i.e : %d is INVALID\n",user.guess);
    }
    else if(user.bet > user.balance){
		printf("Your bet :%d exceeds your balance:%d\n",user.bet,user.balance);
    }
    else if(bet_return == 0 || random_return == 0){
		exit(0);
    }
    else{
        exit(0);
    }
}

void game_logic(){
        printf("\x1b[38;5;33m");
        printf("Your Bet is being Placed......\n");
        printf("\x1b[1;39m");
		DICE = _random(6,0);
        dice_animation(user.guess);
		printf("Random Number : %d Your guess : %d\n",DICE,user.guess);
		if (user.guess == DICE) {
			user.balance += (user.bet * 3);
			printf("CORRECT GUESS :+%d\n",user.bet * 3);
		}
		else{
			user.balance -= (user.bet * 3);
			printf("WRONG GUESS :-%d\n",user.bet * 3);
			if(user.balance < 0 ){
			    printf("CURRENTLY IN DEBT\n");
			}
		}
}

int main(){
    printf ( "\033[1;1H"); // move to row 1 col 1
    printf ( "\033[2J");
    //starting balance
	user.balance = 1000;
do{
    printf("-------------------------------------\n");
	printf("BALANCE : %d\n",user.balance);
	printf("Please place a bet:\n");
	bet_return = scanf("%d",&user.bet);
if ( user.bet <= user.balance && bet_return == 1){
	   printf("Please guess a number from 1 to 6:\n");
	    random_return = scanf("%d",&user.guess);
switch(user.guess){
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	    game_logic();
		break;
	default:
	    error();
	    continue;
		break;
}

}
else{
    error();
    continue;
}
}while(user.balance > 0 && bet_return != 0 && random_return !=0);
printf("\033[1;1H");
printf("\033[2J");//clear screen

}
