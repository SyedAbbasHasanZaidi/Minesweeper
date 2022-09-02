// Assignment 1 21T2 COMP1511: Minesweeper
// minesweeper.c (re-written)
// still testing lol

#include <stdio.h>
#include <stdlib.h>

// Possible square states.
#define VISIBLE_SAFE    0
#define HIDDEN_SAFE     1
#define HIDDEN_MINE     2

// The size of the starting grid.
#define SIZE              8

// The possible command codes.
#define DETECT_ROW      1
#define DETECT_SQUARE   2
#define REVEAL_CROSS    3
#define GAME_MODE       4
#define FLAG_MINE       5
#define DEFUSE          6

// Add any extra #defines here.

void initialise_field(int minefield[SIZE][SIZE]);
void print_debug_minefield(int minefield[SIZE][SIZE]);

// Place your function prototyes here.
void place_mines(int row, int column, int array[SIZE][SIZE]){
    //anymore efficent way to place mines then just looping through rows and columns
    for(int array_row = 0; array_row < SIZE ; array_row++){
        for(int array_column = 0; array_column < SIZE; array_column++){
            if(array_row == row && array_column == column || array[array_row][array_column] == 2){
                array[array_row][array_column] = 2;
            }
            else{
                array[array_row][array_column] = 1;
            }
        }
    }
}

//  error checking function //
int error_detect_row(int row,int column){
    if(row < 0 || column < 0 || row > SIZE || column > SIZE){
        return 0;
    }
    else{
        return 1;
    }
}
//                          //

void detect_row(int minefield[SIZE][SIZE],int command_array[4]){
    int mines_in_row = 0;
    for(int i = 0;i < command_array[3] ;i++){
        if(error_detect_row(command_array[1],command_array[2] + i) == 1 && minefield[command_array[1]][command_array[2] + i ] == 2 ){
            ++mines_in_row;
        }
    }
    printf("There are %d mines in row %d from column %d to %d",mines_in_row, command_array[1],command_array[2],command_array[])
}


int row_detect(int row,int initial_column,int increment,int array[SIZE][SIZE]){
    int mine_count = 0;
    for(int i = 0; i < increment; i++){
        if(array[row][initial_column] = 2){
           ++mine_count;
        }
        ++initial_column;
    }
    return mine_count;
}


int main(void) {

    int minefield[SIZE][SIZE];
    int number_of_mines;

    initialise_field(minefield);
    printf("Welcome to minesweeper!\n");
    printf("How many mines? ");
    scanf("%d", &number_of_mines);

    // TODO: Scan in the number of pairs of mines.
    if(number_of_mines != 0){
        printf("Enter pairs:\n");
    }

    for(int i = 0; i < number_of_mines; i++){
        int row,column; 
        scanf("%d %d", &row, &column);
        place_mines(row, column, minefield);
    }

    // TODO: Scan in the pairs of mines and place them on the grid.


    printf("Game Started\n");
    print_debug_minefield(minefield);


    // TODO: Scan in commands to play the game until the game ends.
    // A game ends when the player wins, loses, or enters EOF (Ctrl+D).
    // You should display the minefield after each command has been processed.
    for(;;){
        printf("Enter Command: ");
        int command_array[4] = {0};
        for(int i = 0; i < 4; i++){
            scanf("%d", &command_array[i]);
            /*if(command_array[i] == EOF){
                return 0;
            }*/
        }

        if(command_array[0] == DETECT_ROW){
            //  error checking  //
            if(error_detect_row(command_array[1],command_array[2]) == 0){
                printf("ERROR IN INPUT : Check row and column inputted\n");
            }
            //                  //
            else{
                detect_row(minefield, command_array);
            }
/*
        else if(command_array[0] == DETECT_SQUARE){
            detect_square(minefield, command_array);
        }

        else if(command_array[0] == REVEAL_CROSS){
            reveal_cross(minefield, command_array);
        }

        else if(command_array[0] == GAME_MODE){
            game_mode(minefield, command_array);
        }

        else if(command_array[0] == FLAG_MINE){
            flag_mine(minefield, command_array);
        }

        else if(command_array[0] == DEFUSE){
            defuse(minefield, command_array);
        }
        */
        } 
    }
     
    return 0;
}  



// Set the entire minefield to HIDDEN_SAFE.
void initialise_field(int minefield[SIZE][SIZE]) {
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            minefield[i][j] = HIDDEN_SAFE;
            j++;
        }
        i++;
    }
}


// Print out the actual values of the minefield.
void print_debug_minefield(int minefield[SIZE][SIZE]) {
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            printf("%d ", minefield[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}