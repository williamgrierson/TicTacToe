#include <stdio.h>
#include <string.h>
#define SIZE 3

int checkGameOver();    //NOCH ZU IMPLEMENTIEREN
void update();
void draw(char (*m)[SIZE]);
void makeMove(char (*m)[SIZE], int *zugCounter);

int main(){

    int zugCounter = 0;
    int gameOver = 0;

    char matrix[SIZE][SIZE];

    //FILL MATRIX
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            matrix[i][j] = '-';
        }
    }

    while(gameOver == 0){
    draw(matrix);
    makeMove(matrix, &zugCounter);
    }


    return 0;
}

void draw(char (*m)[SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("%c ", *(*(m + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}

void makeMove(char (*m)[SIZE], int *zugCounter){
    int i=0;
    int j=0;

    do{
    printf("KREUZ/KREIS SETZEN, ZEILEN- UND SPALTENINDEX ANGEBEN: ");
    scanf("%d %d", &i, &j);
    }while(i>2 || i<0 || j>2 || j<0);
    
    if(*zugCounter%2 == 0){
        m[i][j] = 'X';
        (*zugCounter)++;
    }
    else{
        m[i][j] = 'O';
        (*zugCounter)++;
    }
    printf("\n");
}