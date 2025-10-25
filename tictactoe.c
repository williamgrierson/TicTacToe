#include <stdio.h>
#define SIZE 3

void printMatrix(char m[SIZE][SIZE]);
int makeMove(char m[SIZE][SIZE], int zugCounter);

int main(){

    int zugCounter = 1;
    int run = 0;

    char m[SIZE][SIZE];

    //WIRD GEFÜLLT
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            m[i][j] = '-';
        }
    }

    while(run == 0){
        zugCounter = makeMove(m, zugCounter);
        printMatrix(m);
        run = checkGameState(m);
    }

    return 0;
}

int makeMove(char m[SIZE][SIZE], int zugCounter){
    int x;
    int y;
    printf("Spieler %d - Zeilen/Spaltenindex eingeben: ", zugCounter);
    scanf("%d %d", &x, &y);
    if(x<0 || x>2 || y<0 || y>2){
        printf("Ungültige Eingabe. Versuche es erneut!\n");
        makeMove(m, zugCounter);
    }
    printf("\n");
    if(zugCounter == 1){
        m[x][y] = 'X';
        zugCounter++;
        return zugCounter;
    }
    else{
        m[x][y] = 'O';
        zugCounter = 1;
        return zugCounter;
    }
}

int checkGameState(char m[SIZE][SIZE]){

    int run = 0;

    for(int i=0; i<SIZE; i++){
        if (m[i][0] != '-' && m[i][0] == m[i][1] && m[i][1] == m[i][2]) {
            run = 1;  //Zeilensieg gefunden
        }
        if(m[0][i] != '-' && m[0][i] == m[1][i] && m[1][i] == m[2][i]){
            run = 1;  //Spaltensieg gefunden
        }
        if(m[i][i] != '-' && m[0][0] == m[1][1] && m[0][0] == m[2][2]){
            run = 1;
        }
        if(m[i][SIZE-1-i] != '-' && m[0][2] == m[1][1] && m[0][2] == m[2][0]){
            run = 1;
        }
    }

    if(run == 1){
        printf("Spiel vorbei!\n");
    }

    return run;
}

void printMatrix(char m[SIZE][SIZE]){

    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            //printf("%c ", m[i][j]);
            printf("%c ", *(m[i]+j));
        }
        printf("\n");
    }
    printf("\n");

}
