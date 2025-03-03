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

void print_array(string arr[3][3], int row);
void player1_move(int &row1, int &col1);
void player2_move(int &row2, int &col2);
string update_game();
string player1();
void is_winner1(string arr[3][3], int row, bool &winner);
void is_winner2(string arr[3][3], int row, bool &winner);
bool player_check(string arr[3][3], int row, int col);

int main(){
    int row1 = 0;
    int col1 = 0;
    int row2 = 0;
    int row2 = 0;
    string choice = "x";
    bool winner = false;
    string array[3][3] = {
        {"-","-","-"},
        {"-","-","-"},
        {"-","-","-"}        
       };

    print_array(array,3);
    while (winner == false) {  
        player1_move(row1, col1);
        array[row1][col1] = choice; 
        is_winner1(array, 3, winner); 
        is_winner2(array,3,winner);
        print_array(array,3);
    };

    return 0;
}

void is_winner1(string arr[3][3], int row, bool &winner){
    for(int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (arr[0][0] == "x" && arr[0][1] == "x" && arr[0][2] == "x"){  //handles row
                winner = true;
                cout << "Player 1 Wins!\n"; 
            }
            else if (arr[1][0] == "x" && arr[1][1] == "x" && arr[1][2] == "x"){ //handles row
                winner = true;
                cout << "Player 1 Wins!\n"; 
            }
            else if (arr[2][0] == "x" && arr[2][1] == "x" && arr[2][2] == "x"){  //handles row
                winner = true;
                cout << "Player 1 Wins!\n"; 
            }
            else if (arr[0][0] == "x" && arr[1][0] == "x" && arr[2][0] == "x"){  //handles col
                winner = true;
                cout << "Player 1 Wins!\n"; 
            }
            else if (arr[0][1] == "x" && arr[1][1] == "x" && arr[2][1] == "x"){ //handles col
                winner = true;
                cout << "Player 1 Wins!\n"; 
            }
            else if (arr[0][2] == "x" && arr[1][2] == "x" && arr[2][2] == "x"){ //handles col
                winner = true;
                cout << "Player 1 Wins!\n"; 
            }
            else if (arr[0][0] == "x" && arr[1][1] == "x" && arr[2][2] == "x"){ //handles vert
                winner = true;
                cout << "Player 1 Wins!\n"; 
            }
            else if (arr[0][2] == "x" && arr[1][1] == "x" && arr[2][0] == "x"){ //handles vert
                winner = true;
                cout << "Player 1 Wins!\n"; 
            }
            else{
                winner = false;
            }
        }      
    }   
}

void print_array(string arr[3][3], int row){   
    for(int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
}


string player1(){
    string choice;
    cout << "Choose either x or o ";
    cin >> choice;
    
    while (choice != "x" && choice != "o"){
        cout << "Enter either x or o: ";
        cin >> choice;
    }
    
    return choice;
}

void player1_move(int &row, int &col){
    
    cout << "Choose a row between 0 and 2: ";
    cin >> row;

    while (row != 0 && row != 1 && row != 2){
        cout << "Enter either a 0 or 2";
        cin >> row;
    }

    cout << endl;
    cout << "Choose a column 0 and 2: ";
    cin >> col;

    while (col != 0 && col != 1 && col !=2){
        cout << "Enter either a 0 or 2";
        cin >> col;
    }

}

void player2_move(int &row2, int &col2){
    srand(time(0));
    row2 = rand() % 3;
    col2 = rand() % 3;
}

bool player_check(string array[3][3], int row, int col){
    bool position;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (arr[i][j]) == "x" && arr[i][j] == "o"){
                position = true;
            }
             else{
                 position = false;
            }
        }
    }
    return position;
}

