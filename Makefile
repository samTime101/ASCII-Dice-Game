#MAKE FILE 
#dice game 
all:
	gcc dice.c random.c -o ./output/dice
clean:
	rm dice
