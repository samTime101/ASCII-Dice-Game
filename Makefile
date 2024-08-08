#MAKE FILE
#dice game
all:
	gcc dice.c random.c dice_animation.c -o ./output/dice
clean:
	rm ./output/dice
