#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

int *randomSetup(int, int);
void draw(int tam, int snake, int *fruits);
void loopFruit(int tam, int snake, int *fruits);