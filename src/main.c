#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
int *randomSetup(int, int);
void draw(int tam, int snake, int *fruits);

int main(int argc, char** argv) {
  sranddev();

  int tam, snake, ch;
  printf("Inserte tamaño: ");
  //tam=getchar()-'0';
  scanf("%d", &tam);
  if(tam<4){
    tam=4;
  }
  snake=tam/2; //Genera snake a la mitad del tablero
  int *fruits;
  fruits=randomSetup(tam, snake);

  //Inicializa modo no canónico para la terminal
  struct termios info;
  tcgetattr(0, &info);
  info.c_lflag &= ~ICANON;
  info.c_cc[VMIN]=1;
  info.c_cc[VTIME]=0;
  tcsetattr(0, TCSANOW, &info);

  while((ch=getchar())!=27){ 
    if(ch<0){
      if(ferror(stdin)){
        clearerr(stdin);
      }
    }
    printf("%d", ch);
    if(ch==111){
    fruits=randomSetup(tam, snake);
    }
    draw(tam, snake, fruits);
    sleep(1);
  }

  tcgetattr(0, &info);
  info.c_lflag |= ICANON;
  tcsetattr(0, TCSANOW, &info);
  return 0;
}

void draw(int tam, int snake, int *fruits){
  /*
  Función para dibujar el tablero
  Entrada: Ninguna
  Salida: Tablero 
  */
  
  printf("\n");
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
    printf("\nfruit:%d %d\n", fruits[0], fruits[1]); //Imprime los valores de fruitx y fruity
  } while (fruits[0]==snake && fruits[1]==snake);

  return fruits;
}