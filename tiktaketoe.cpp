#include <iostream>
#include <cctype>
#include <string>
#include <ctime>
#include <random>
#include <cstdlib>
using namespace std;

/*
TikTakToe

Project flow:
User prompted to enter either 'X' or 'O'
The user is then assigned either the 'X' or 'O'
User is asked to enter a cordinate in the 3d array
The answer is recorded and printed to the terminal.
If a spot is taken, then it cannot be overwriten and then player will be asked to 
make another selection. 
Each iteration the program will check if 

Handling a win, if three X or O in a row, then the program declares
a winner and program ends. 

Variables needed:
Player1
Player2
array

Functions:
Selection
Print_Array
Array

*/

void print_array(char arr[3][3], int row);
void player1_move(char arr[3][3], int &row, int &col);
void player2_move(char arr[3][3], int &row, int &col);
char update_game();
char player_choice();
char computer_choice(char choice1);
void is_winner(char array[3][3], int row, bool &winner);
void is_tie(char array[3][3], int row, bool &tie, bool winner);
bool player_check(char arr[3][3], int row, int col);

int main(){
    int row = 0;
    int col = 0;
    char choice1;
    char choice2;
    bool winner = false;
    bool tie = false;
    char array[3][3] = {
        {'-','-','-'},
        {'-','-','-'},
        {'-','-','-'}
    };
    choice1 = player_choice();
    choice2 = computer_choice(choice1);
    print_array(array,3);
 
    while (winner == false && tie == false) {
        
        cout << "Tie: " << tie << endl;    
        player1_move(array, row, col);
        array[row][col] = choice1;
        is_winner(array, 3, winner); 
        is_tie(array, 3, tie, winner);
        if (winner == true || tie == true){
            break;
        }
        player2_move(array, row, col);
        array[row][col] = choice2;
        is_winner(array, 3, winner); 
        is_tie(array, 3, tie, winner);
        if (winner == true || tie == true){
            break;
        }
        print_array(array,3);
    };
        print_array(array,3);
    return 0;
}

void is_winner(char array[3][3], int row, bool &winner){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3-2; j++){
            if (array[i][j] != '-'){
                if (array[i][j] == array[i][j+1] && array[i][j] == array[i][j+2]){
                    winner = true;
                    cout << "row";
                }           
            }
        }
    }
    
    for (int i = 0; i < 1; i++){
        for (int j = 0; j < 3; j++){
            if (array[i][j] != '-'){    
                if (array[i][j] == array[i+1][j] && array[i][j] == array[i+2][j]){
                    winner = true;
                    cout << "col";
                }
            }
        }
    }

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            if (array[i][j] != '-'){   
                if ( array[i][j] == array[i+1][j+1] && array[i][j] == array[i+2][j+2] ){
                    winner = true;
                    cout << "diag1";
                }
            }
        }    
    }

        for (int i = 2; i >= 2; i--){
            for (int j = 0; j < 1; j++){
                if (array[i][j] != '-'){   
                    if ( array[i][j] == array[i-1][j+1] && array[i][j] == array[i-2][j+2] ){
                        winner = true;
                        cout << "daig2";
                    }
                }
            }    
        }

    if (winner == true){
        cout << "Winner!";
    }
           
}

void is_tie(char array[3][3], int row, bool &tie, bool winner){
    tie = true;
    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (array[i][j] == '-'){
                tie = false;
                return;
            }
        }
    }
    if (tie == true && winner == false){
        cout << "Tie!\n"; 
    }        
}

void print_array(char arr[3][3], int row){  
    for(int i=0; i<3; i++){
       
        for (int j=0; j<3; j++){
            cout << arr[i][j];
            if (j<2){
                cout << "|";
            }   
        }
        if (i<2){
            cout << endl <<"-----";
        }
        cout << endl;
    }  
}

char player_choice(){
    char choice;
    cout << "Choose either x or o:  ";
    cin >> choice;
    tolower(choice);
    while (choice != 'x' && choice != 'o'){
        cout << "Enter either x or o: ";
        cin >> choice;
    }   
    return choice;
}

char computer_choice(char choice1){
    char computer;
    if(choice1 == 'x'){
        computer = 'o';
    }
    else{
        computer = 'x';
    }
    return computer;
}

void player1_move(char array[3][3], int &row, int &col){
    /*
    1. A row and column are entered
    2. at the end of the loop a check is made if there is an x or o in that place.
    3. If there is an x or o, the player is prompted to select again.  
    4. Do while loop?
    */
    bool check;
    while (check == false){
        cout << "Choose a row between 0 and 2: ";
        cin >> row;
        while (row != 0 && row != 1 && row != 2){
        cout << "Enter either 0, 1, or 2 ";
        cin >> row;
        }
        cout << endl;
        cout << "Choose a column 0 and 2: ";
        cin >> col;
        while (col != 0 && col != 1 && col !=2){
        cout << "Enter either 0, 1, or 2 ";
        cin >> col;
        }
        check = player_check(array, row, col);
        if (check == false){
        cout << "Invalid move";
        }
   }
}

void player2_move(char array[3][3], int &row2, int &col2){
    srand(time(0));
    bool check = false;
    
    while (check == false){
        row2 = rand() % 3;
        col2 = rand() % 3;
        check = player_check(array, row2, col2);
        cout <<  "Check: " << check << endl;
    }
        
}

bool player_check(char array[3][3], int row, int col){
    bool position;
            if (array[row][col] == 'x' || array[row][col] == 'o'){
                position = false;
            }
             else{
                 position = true;
            }
    return position;
}
