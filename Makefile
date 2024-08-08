#MAKE FILE
#dice game
all:
	gcc ./src/dice.c ./src/random.c ./src/dice_animation.c ./src/game_logic.c ./src/error.c -o ./output/dice
clean:
	rm ./output/dice
