
#include <stdio.h>
#include <stdlib.h>
#include "../include/structures.h"
#include <unistd.h>
void error(struct user user, int random_return , int bet_return){
    if(user.guess < 1 || user.guess > 6){
  		printf("Your guess should be within 1 to 6\n");
        printf("Your guess i.e : %d is INVALID\n",user.guess);
    }
    else if(user.bet > user.balance){
		printf("Your bet :%d exceeds your balance:%d\n",user.bet,user.balance);
    }
    else if (bet_return == 0 || random_return == 0){
        sleep(2);
		exit(0);
    }
    else{
        sleep(10);
        exit(0);
    }
}
