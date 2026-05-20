#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int currentPlayer;
char currentMarker;
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void drawboard(){
    cout << "  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "  ";
    cout << "\n ---|---|--- \n";
    cout << "  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "  ";
    cout << "\n ---|---|--- \n";
    cout << "  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "  ";
}

bool placemarker(int slot){
    int row = (slot-1)/3;
    int col = (slot-1)%3;

    if(board[row][col] != 'X' && board[row][col] != '0'){
        board[row][col] = currentMarker;
        return true;
    }
    else{
        return false;
    }
}

int winner(){

    // rows
    for(int i = 0; i < 3; i++){
        if(board[i][0] == board[i][1] &&
           board[i][1] == board[i][2] &&
           (board[i][0] == 'X' || board[i][0] == '0')){
            return currentPlayer;
        }
    }

    // columns
    for(int i = 0; i < 3; i++){
        if(board[0][i] == board[1][i] &&
           board[1][i] == board[2][i] &&
           (board[0][i] == 'X' || board[0][i] == '0')){
            return currentPlayer;
        }
    }

    // diagonal
    if(board[0][0] == board[1][1] &&
       board[1][1] == board[2][2] &&
       (board[0][0] == 'X' || board[0][0] == '0')){
        return currentPlayer;
    }

    // anti-diagonal
    if(board[0][2] == board[1][1] &&
       board[1][1] == board[2][0] &&
       (board[0][2] == 'X' || board[0][2] == '0')){
        return currentPlayer;
    }

    return 0;
}

void swapPlayerandMarker(){
    if(currentMarker == 'X'){
        currentMarker = '0';
    }
    else{
        currentMarker = 'X';
    }
    if(currentPlayer == 1){
        currentPlayer = 2;
    }
    else{
        currentPlayer = 1;
    }
}

void game(){
    cout << "\n___WELCOME___\n\nARE YOU READY (Yes/No)\n\n";
    string ready;
    cin >> ready;

    transform(ready.begin(), ready.end(), ready.begin(), ::tolower);
    
    if(ready == "yes" ){
        cout << "\n-----Game on-----\n\n";
        cout << "\nPLAYER-1 CHOOSE YOUR MARKER (X / 0) : ";
        char marker_P1;
        cin >> marker_P1;
        marker_P1 = toupper(marker_P1);

        if(marker_P1 != 'X' && marker_P1 != '0'){
            cout << "Invalid marker!\n";
            return;
        }

        currentPlayer = 1;
        currentMarker = marker_P1;
        drawboard();

        int PlayerWon = 0;

        for(int i = 0;i<9;i++){
            cout << "\nits player " << currentPlayer << "'s turn choose your slot : ";
            int slot;
            cin >> slot;

            if(slot < 1 || slot  > 9){
                cout << "Enter valid slot (1-9)!";
                continue;
            }
            if(!placemarker(slot)){
                cout << "occupied ! try again\n";
                i--;
                continue;
            }
            drawboard();
            cout << "\n";
            PlayerWon = winner();

            if(PlayerWon == 1){
                cout << "\n___Congrats --- player-1 --- wins___\n";
                break;
            }
            if(PlayerWon == 2){
                cout << "\n___Congrats --- player-2 --- wins___\n";
                break;
            }
            swapPlayerandMarker();
        }
        if(PlayerWon == 0){
            cout << "\n___TIE___\n";
        }
    }
}


int main(){
    game();

    return 0;
}