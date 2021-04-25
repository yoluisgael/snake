#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void draw(int);
int initialsetup(int);

int main(int argc, char** argv) {
  int tam;
  printf("Inserte tamaño:");
  scanf("%d", &tam);
  draw(tam);

  return 0;
}
void draw(int tam){
  /*
  Función para dibujar el tablero
  Entrada: Ninguna
  Salida: Tablero 
  */
  int fruitx=0;
  int fruity=0;
  srand(time(NULL));
  int snake=tam/2; //Genera snake a la mitad del tablero
  
  //Genera Ubicación de frutita hasta que sea distinta de snake
  do{
    fruitx=1+rand()%(tam-2);
    fruity=1+rand()%(tam-2);
    printf("fruit:%d %d\n", fruitx, fruity);
  } while (fruitx==snake && fruity==snake);

  printf("snake:%d\n", snake);
  for(int i = 0; i < tam; i++){ // Recorre toda la Altura
    for(int j =0; j < tam; j++){ // Recorre toda la Anchura
      if (i == 0 || i == tam-1 || j == 0 || j == tam-1){ // Checa si es la orilla
        printf("* ");
      }
      else if(i == fruity && j == fruitx){// Checa ubicación y pone frutita
        printf("o ");
      }
      else if(i == snake && j == snake){//Checa snake y lo pone wuu
        printf("[]");
      }
      else {
        printf("  "); //imprime el vacío del tablero
      }
    }
    printf("\n"); //salto de línea cuando acaba de recorrer el ancho
  }
}