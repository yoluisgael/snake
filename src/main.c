#include "production.c"

int main(int argc, char** argv) {
  srand(time(NULL));

  int tam, snake;
  printf("Inserte tamaño: ");
  scanf("%d", &tam);
  if(tam<4){
    tam=4;
  }
  snake=tam/2; //Genera snake a la mitad del tablero
  int *fruits;
  fruits=randomSetup(tam, snake);
  loopFood(tam, snake, fruits);
  return 0;
}

