#include <iostream>
#include <string>


int main();
void displayBoard(char board [3][3]); //displays the board
void hasWon(char board [3][3], int turn, bool &isWon); //determines if a player has won after each round
void hasTied(char board [3][3], bool &isTie); // determines if the game is tied; called after isWon
void player_turn(char (&board)[3][3], int turn); //runs through 1 player's turn 
void gameplay(char (&board)[3][3]); 




int main(){

    char board[3][3];

    //make all values of the board initially empty
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }

    //Game Start

    gameplay(board);

   return 0; 
}


void displayBoard(char board [3][3]){
    //layout of board
        for (int i = 0; i < 3; i++){
        
            std::cout << "    |    |    |\n";
            
            for (int j = 0; j < 3; j++){
                if (j == 2){
                    std::cout << " " << board[i][j] << "  |\n";
                }else{
                    std::cout << " " << board[i][j] << "  |";
                }
            }   

            std::cout << "____|____|____|\n";
        
       }
}



void hasWon(char board [3][3], int turn, bool &isWon){
    //defaulted to player 1
    int player = 1;
    char value = 'X';

    //specialized for player 2
    if (turn%2 == 1){
        player = 2;
        value = 'O';
    }


    //check each row
    for(int i = 0; i < 3; i++){
        if(board[i][0] == value && board[i][1] == value && board[i][2] == value){
            isWon = true;
        }
    }

    //check each column
    for(int i = 0; i < 3; i++){
        if(board[0][i] == value && board[1][i] == value && board[2][i] == value){
            isWon = true;
        }
    }

    //check diagonals
    if(board[0][0] == value && board[1][1] == value && board[2][2] == value){
        isWon = true;
    }else if(board[2][0] == value && board[1][1] == value && board[0][2] == value){
        isWon = true;
    }
    
    if(isWon){
        std::cout << "Player " << player << " wins!\n";
    }
}




void hasTied(char board [3][3], bool &isTie){
    for(int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if(board[i][j] == ' '){
                    return;
                }
            }
        }
        
        std::cout << "Its a tie! Game over!\n";
        isTie = true;
}


void player_turn(char (&board)[3][3], int turn){
    std::string coordinate = "0,0";

    //defaulted to player 1
    int player = 1;
    char value = 'X';

    //specialized for player 2
    if (turn%2 == 1){
        player = 2;
        value = 'O';
    }

    int xcoord = 0;
    int ycoord = 0;
    bool validCoord = false;
    bool error = false;
    std::string coordinateStrx = "";
    std::string coordinateStry = "";


    //goes through a for loop until the input is a valid coordinate
    for(int i = 0; !validCoord; i++){
        //
        if (i > 0 && !error){
            std::cout << "That was an invalid input, please try again:  \n";
        }
        error = false;

        try{
            
            std::cout << "Player " << player << ": Please enter the coordinates of " << value << " (x-coordinate,y-coordinate)\n";
            std::cin >> coordinate;

            
            //if any of these values throw an error, skip to the catch
            coordinateStrx = coordinate.at(0);
            coordinateStry = coordinate.at(2);

            xcoord = std::stoi(coordinateStrx);
            ycoord = std::stoi(coordinateStry);


        }catch(...){
            std::cout << "That was an invalid input, please try again:  \n";
            error = true;
        }
        
        //requirements for a valid coordinate
        if(!error && 0 <= xcoord && xcoord <= 2 && 0 <= ycoord && ycoord <= 2 && board[ycoord][xcoord] == ' ' && coordinate.length() == 3 && coordinate.at(1) == ','){
            validCoord = true;
        }
    }
    
    board[ycoord][xcoord] = value;

}

void gameplay(char (&board)[3][3]){
    bool isWon = false; //determines if a player has won after each round
    bool isTie = false; //determines if the game is tied; called after isWon
    
    std::cout << "Welcome, players!";
    std::cout << "Player 1: X \nPlayer 2: O \n";

    displayBoard(board);
    
    //uses a for loop to keep track of which player's turn: 0 - Player 1, 1 - Player 2
    for(int i = 0; !isWon && !isTie; i++){ 
    
        //modifies one value of the board for each player's turn
        player_turn(board, i);
        
        //show the new board after each turn
        displayBoard(board);

        //check if the player won this turn or if the game has tied
        hasWon(board, i, isWon);

        hasTied(board, isTie);

    }
}





