// DICE GAME
#include<stdio.h>
#include<unistd.h>
#include "../include/structures.h"

struct user user;
struct ASCII ascii[DICE_PERM];

int DICE , bet_return ,random_return ;

//functions defns
int game_logic(struct ASCII ascii[DICE_PERM], struct user user, int DICE);
void error(struct user user, int random_return , int bet_return);

int main(){
    printf ( "\033[1;1H"); // move to row 1 col 1
    printf ( "\033[2J");
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
	   //replace the new user balance with return value from
		//game_logic() function
	    user.balance = game_logic(ascii,user,DICE);
		break;
	default:
	    error(user,random_return,bet_return);
	    continue;
		break;
}

}
else{
    error(user,random_return,bet_return);
    continue;
}
}while(user.balance > 0 && bet_return != 0 && random_return !=0);
printf("\033[1;1H");
printf("\033[2J");//clear screen

}
