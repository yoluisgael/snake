#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
void draw(int, int);
int *randomSetup(int, int);

int main(int argc, char** argv) {
  int tam, snake;
  sranddev();
  printf("Inserte tamaño:");
  scanf("%d", &tam);
  while(1){
    if(tam>3){
      snake=tam/2; //Genera snake a la mitad del tablero
      draw(tam, snake);
      sleep(2);
    }
  }
  return 0;
}

void draw(tam, snake){
  /*
  Función para dibujar el tablero
  Entrada: Ninguna
  Salida: Tablero 
  */
  
  int *fruits;
  fruits=randomSetup(tam, snake);
  for(int i = 0; i < tam; i++){ // Recorre toda la Altura
    for(int j =0; j < tam; j++){ // Recorre toda la Anchura
      if (i == 0 || i == tam-1 || j == 0 || j == tam-1){ // Checa si es la orilla
        printf("* ");
      }
      else if(i == fruits[1] && j == fruits[0]){// Checa ubicación y pone frutita
        printf("o ");
      }
      else if(i == snake && j == snake){//Checa snake y lo pone wuu
        printf("▧ ");
      }
      else {
        printf("  "); //imprime el vacío del tablero
      }
    }
    printf("\n"); //salto de línea cuando acaba de recorrer el ancho
  }
}


int *randomSetup(tam, snake){
  static int fruits[2];
  for(int i=0; i<2; i++){
    fruits[i]=0;
  }
  
  //Genera Ubicación de frutita hasta que sea distinta de snake
  do{
    fruits[0]=rand()%(tam-2)+1;
    fruits[1]=rand()%(tam-2)+1;
    printf("fruit:%d %d\n", fruits[0], fruits[1]); //Imprime los valores de fruitx y fruity
  } while (fruits[0]==snake && fruits[1]==snake);

  return fruits;
}