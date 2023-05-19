#include<iostream>
using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char choice, row, col;
bool draw = false;
char turn = 'X';

void displayBoard(){
    system("clear");
    cout<<"\n\n\t  T i c k   C r o s s   G a m e\n\n";

    cout<<"\t   You [X]\t  Computer [O]\n\n";

    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  \n";
    cout<<"\t\t     |     |     \n\n";

    cout<<"*If you want exit the match\nthen press 'e'\n\n";
}

void playerTurn(){
    if(turn == 'X') {
        cout<<"\tYour [X] turn: ";
        cin>>choice;

        switch (choice){
            case '1': row = 0, col = 0; break;
            case '2': row = 0, col = 1; break;
            case '3': row = 0, col = 2; break;
            case '4': row = 1, col = 0; break;
            case '5': row = 1, col = 1; break;
            case '6': row = 1, col = 2; break;
            case '7': row = 2, col = 0; break;
            case '8': row = 2, col = 1; break;
            case '9': row = 2, col = 2; break;
            case 'e': exit(1); break;
            default: 
                cout<<"\n *Invalid Choice*\n*Please try again*\n\n";
                playerTurn();
        }
        if(turn == 'X' && board[row][col]!='X' && board[row][col]!='O'){
            board[row][col] = 'X';
            turn = 'O';
        }else{
            cout<<"\n*Box already filled!*\n*Please try again!!*\n\n";
            playerTurn();
        }
    }
    
    else if(turn == 'O') {
        // cout<<"\tComputer [O] turn: ";
        srand(time(0));

        do{
            choice = (rand() % (57 - 49 + 1)) + 49;
            // choice = int((rand()%9)+1);
            // choice = char(choice+49);

            switch (choice){
                case '1': row = 0, col = 0; break;
                case '2': row = 0, col = 1; break;
                case '3': row = 0, col = 2; break;
                case '4': row = 1, col = 0; break;
                case '5': row = 1, col = 1; break;
                case '6': row = 1, col = 2; break;
                case '7': row = 2, col = 0; break;
                case '8': row = 2, col = 1; break;
                case '9': row = 2, col = 2; break;
                case 'e': exit(1); break;
                default: 
                    cout<<"\n *Invalid Choice*\n*Please try again*\n\n";
                    // playerTurn();
            }
        }while(board[row][col]=='X' && board[row][col]=='O');
        if(turn == 'O' && board[row][col]!='X' && board[row][col]!='O'){
            board[row][col] = 'O';
            turn = 'X';
        }
        // else{
        //     cout<<"\n*Box already filled!*\n*Please try again!!*\n\n";
        //     playerTurn();
        // }
    } // 49 57

    displayBoard();
}

bool gameOver(){
    for (int i = 0; i < 3; i++)
        if(board[i][0]==board[i][1] && board[i][0]==board[i][2] || board[0][i]==board[1][i] && board[0][i]==board[2][i]) return false;
    
        if(board[0][0]==board[1][1] && board[0][0]==board[2][2] || board[0][2]==board[1][1] && board[0][2]==board[2][0]) return false;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if(board[i][j] != 'X' && board[i][j] != 'O') return true;

    draw = true;
    return false;
}

int main(){
// #ifndef ONLINE_JUDGE
//     freopen("io/input.txt", "r", stdin);
//     freopen("io/output.txt", "w", stdout);
// #endif

    while(gameOver()){
        displayBoard();
        playerTurn();
        gameOver();
    }

    if(turn == 'X' && draw == false) cout<<"Congratulations\nComputer [O] Wins!!\n\n";
    else if(turn == 'O' && draw == false) cout<<"Congratulations\nYou [X] Wins!!\n\n";
    else cout<<"*GAME DRAW!!*\n\n";


    return 0;
}
