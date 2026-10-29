#include <stdio.h>
#include <stdlib.h>

/*
lee los valores del usuario.
Retorna 1 o 0 (error si matriz == NULL o dimensiones inválidas).
*/
int llenar(int* matriz, int filas, int columnas) {
  if (matriz == NULL || (filas < 1 || filas > 100) ||
      (columnas < 1 || columnas > 100)) {
    printf("hubo un error al momento de llenar la matriz");
    return 0;
  }
  printf("ingrese %d enteros\n", filas * columnas);
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      int x;
      // printf("inserte el valor para la posicion %d,%d de la matriz: ", i, j);
      scanf("%d", &x);
      // solo acceder con matriz[i * columnas + j]
      matriz[i * columnas + j] = x;
    }
  }
  return 1;
};

/*
escribe en *resultado un entero por fila;
*resultado apunta a un arreglo de filas long long reservado por main
*/
int suma_filas(const int* matriz, int filas, int columnas,
               long long* resultado) {
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      // printf("antes: %d %d\n", resultado[i], i);
      resultado[i] += matriz[i * columnas + j];
      // printf("despues:%d %d\n", resultado[i], i);
    }
  }
};

/*
Ídem para columnas (arreglo de columnas)
*/
int suma_columnas(const int* matriz, int filas, int columnas,
                  long long* resultado) {
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      resultado[j] += matriz[i * columnas + j];
    }
  }
};
;

/*
escribe un único valor
*/
int suma_total(const int* matriz, int filas, int columnas,
               long long* resultado) {
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      resultado += matriz[i * columnas + j];
    }
  }
};

int main() {
  int filas = 0;
  int columnas = 0;

  // validar 1 a 100
  do {
    printf("filas = ");
    scanf("%d", &filas);
  } while (filas < 1 || filas > 100);
  do {
    printf("columnas = ");
    scanf("%d", &columnas);
  } while (columnas < 1 || columnas > 100);
  // printf("\n");
  int* matriz = (int*)calloc((size_t)filas * columnas, sizeof(int));
  // reservar con calloc
  long long* resultado_fil =
      (long long*)calloc((size_t)columnas, sizeof(long long));
  long long* resultado_col =
      (long long*)calloc((size_t)filas, sizeof(long long));
  long long* resultado;

  llenar(matriz, filas, columnas);
  suma_filas(matriz, filas, columnas, resultado_fil);
  suma_columnas(matriz, filas, columnas, resultado_col);
  suma_total(matriz, filas, columnas, resultado);

  printf("\n");

  printf("suma por filas\t\t: ");
  for (int i = 0; i < filas; i++)
    printf("%d ", resultado_fil[i]);
  printf("\n");

  printf("suma por columnas\t: ");
  for (int i = 0; i < columnas; i++)
    printf("%d ", resultado_col[i]);
  printf("\n");

  printf("suma total\t\t: %d", resultado);
  // solo acceder con matriz[i * columnas + j]
  return 0;
}