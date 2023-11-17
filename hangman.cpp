#include <bits/stdc++.h>

using namespace std;

struct Player{
    string username;
    double score;
    int attempts;
    double avrgscore ;
    Player(const string& name) : username(name), score(0) , attempts(0), avrgscore(0){} //constructor to initialize the score to 0
};

struct Leaderboard {
    vector<Player> players;

    void addPlayer(const string &name) {                
        auto it = find_if(players.begin(), players.end(), [&](const Player &p) {
            return p.username == name;
        }); //to check for duplicate names, to ensure no duplicate names in the leaderboard

        if (it == players.end()) {
            players.emplace_back(name);
        } //if no match is found, place the name at the back of the array
    }
    int updateattempts(const string& name) {
        for (auto &player : players) {
            if (player.username == name) {
                player.attempts ++ ;
                return player.attempts ;
            }
        } //update the player attempts 
    }
    double changeScore(const string& name, double score) {
        for (auto &player : players) {
            if (player.username == name) {
                player.score += score;
                
                return player.score; 
            }
        } //update the player score
    }
    void updateavrgScore(const string& name, double score) {
        for (auto &player : players) {
            if (player.username == name) {
                player.avrgscore = score;
                
                break;
            }
        } //update the player score
    }

    void display() {
        cout << "\nLeaderboard:\n";
        int rank = 1;
        for (const auto& player : players) {
            cout << rank << ". "<< "Username: " << player.username << ", Score: " << player.avrgscore << ", Attempts: " << player.attempts << endl;
            rank++;
        }   //display the leaderboard
    }
};

string chooseRandomWord(const vector<string> &words){
    int randomIndex = rand() % words.size();
    return words[randomIndex]; //choose a random number
} 

string displayWord(const string &word, const string &guessed){
    string displayedWord = word; 

    for(char c : word){ 
        if(guessed.find(c) == string::npos){ // if that word is not already in the guessed string
            int pos = displayedWord.find(c); // set the pos index at the first occurence of that letter

            while(pos != string::npos){ // while c is found at the displayedWord
                displayedWord[pos] = '_'; // replace the word with '_' 
                pos = displayedWord.find(c, pos+1); //search for more occurence of c
            }
        }
    }
    return displayedWord;
}

void printhelloascii(){
        cout <<"  __    __                                                                 "<< endl;
        cout <<" /  |  /  |                                                                "<< endl;
        cout <<" $$ |  $$ |  ______   _______    ______   _____  ____    ______   _______  "<< endl;
        cout <<" $$ |__$$ | /      / /       /  /      / /     //    /  /      / /       / "<< endl;
        cout <<" $$    $$ | $$$$$$  |$$$$$$$  |/$$$$$$  |$$$$$$ $$$$  | $$$$$$  |$$$$$$$  |"<< endl;
        cout <<" $$$$$$$$ | /    $$ |$$ |  $$ |$$ |  $$ |$$ | $$ | $$ | /    $$ |$$ |  $$ |"<< endl; 
        cout <<" $$ |  $$ |/$$$$$$$ |$$ |  $$ |$$ /__$$ |$$ | $$ | $$ |/$$$$$$$ |$$ |  $$ |"<< endl;
        cout <<" $$ |  $$ |$$    $$ |$$ |  $$ |$$    $$ |$$ | $$ | $$ |$$    $$ |$$ |  $$ |"<< endl;
        cout <<" $$/   $$/  $$$$$$$/ $$/   $$/  $$$$$$$ |$$/  $$/  $$/  $$$$$$$/ $$/   $$/ "<< endl;
        cout <<"                               /  /__$$ |                                  "<< endl;
        cout <<"                                $$    $$/                                  "<< endl;
        cout <<"                                 $$$$$$/                                   "<< endl; 


        cout << "8                   .oo                              ooo.   8       o                          .oo           8  o    o               o " << endl;
        cout << "8                  .P 8                              8  `8. 8                                 .P 8           8  8b   8                 " << endl;
        cout << "8oPYo.o    o      .P  8oPYo..oPYo. o    o .oPYo.     8   `8 8oPYo. o8 o   o   o.oPYo.        .P  8odYo. .oPYo8  8`b  8 o    o.oPYo. o8 " << endl;
        cout << "8    88    8     oPooo88  `'8    8 8    8 .oooo8     8    8 8    8  8 Y. .P. .P.oooo8       oPooo88' `8 8    8  8 `b 8 8    88    8  8 " << endl;
        cout << "8    88    8    .P    88    8    8 8    8 8    8     8   .P 8    8  8 `b.d'b.d'8    8      .P    88   8 8    8  8  `b8 8    88    8  8 " << endl;
        cout << "`YooP'`YooP8   .P     88    `YooP8 `YooP8 `YooP8 88  8ooo'  8    8  8  `Y' `Y' `YooP8 88  .P     88   8 `YooP'  8   `8 `YooP'`YooP8  8 " << endl;
        cout << ":.....:....8 ::..:::::...::::....8 :....8 :.....:`P::.....::..:::..:..::..::..::.....:`P::..:::::...::..:.....::..:::..:.....:....8 :.." << endl;
        cout << "::::::::ooP'.:::::::::::::::::ooP'.::ooP'.::::::::.::::::::::::::::::::::::::::::::::::.:::::::::::::::::::::::::::::::::::::::ooP'.:::" << endl;
        cout << "::::::::...:::::::::::::::::::...::::...:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::...:::::" << endl;
}
void printwinascii(){
                cout <<" __      __ ______   __    __        __       __   ______   __    __ "<< endl;
                cout <<"/  /    /  /      / /  |  /  |      /  |  _  /  | /      / /  /  /  |"<< endl;
                cout <<"$$  /  /$$/$$$$$$  |$$ |  $$ |      $$ | / / $$ |/$$$$$$  |$$  / $$ |"<< endl;
                cout <<"  $$  $$/ $$ |  $$ |$$ |  $$ |      $$ /$$$  $$ |$$ |  $$ |$$$$  $$ |"<< endl;
                cout <<"   $$$$/  $$ |  $$ |$$ |  $$ |      $$ $$/$$ $$ |$$ |  $$ |$$ $$ $$ |"<< endl;
                cout <<"    $$ |  $$ /__$$ |$$ /__$$ |      $$$$/  $$$$ |$$ /__$$ |$$ |$$$$ |"<< endl; 
                cout <<"    $$ |  $$    $$/ $$    $$/       $$$/    $$$ |$$    $$/ $$ | $$$ |"<< endl;
                cout <<"    $$/    $$$$$$/   $$$$$$/        $$/      $$/  $$$$$$/  $$/   $$/ "<< endl;
}

void printloseascii(){
            cout <<" __      __ ______   __    __        __         ______    ______   ________  "<< endl;
            cout <<"/  /    /  /      / /  |  /  |      /  |       /      /  /      / /        | "<< endl;
            cout <<"$$  /  /$$/$$$$$$  |$$ |  $$ |      $$ |      /$$$$$$  |/$$$$$$  |$$$$$$$$/  "<< endl;
            cout <<" $$  //$$/$$ |  $$ |$$ |  $$ |      $$ |      $$ |  $$ |$$ /__$$/ $$ |__     "<< endl;
            cout <<"  $$  $$/ $$ |  $$ |$$ |  $$ |      $$ |      $$ |  $$ |$$      / $$    |    "<< endl;
            cout <<"   $$$$/  $$ |  $$ |$$ |  $$ |      $$ |      $$ |  $$ | $$$$$$  |$$$$$/     "<< endl; 
            cout <<"    $$ |  $$ /__$$ |$$ /__$$ |      $$ |_____ $$ /__$$ |/  /__$$ |$$ |_____ |"<< endl;
            cout <<"    $$ |  $$    $$/ $$    $$/       $$       |$$    $$/ $$    $$/ $$       | "<< endl;
            cout <<"    $$/    $$$$$$/   $$$$$$/        $$$$$$$$/  $$$$$$/   $$$$$$/  $$$$$$$$/  "<< endl;
}


int main() {

    Leaderboard leaderboard; 

    char playAgain;
    do {
        cout << "***************" << '\n';
        printhelloascii();
        cout << "Guess an animal" << '\n';
        cout << "***************" << '\n';
        
        string playerName;
        cout << "Enter your username (no spaces allowed): ";
        cin >> playerName;

        leaderboard.addPlayer(playerName);

        srand(static_cast<unsigned int>(time(nullptr))); 

        vector<string> words = {"lion", "alligator", "shark", "dog", "elephant", "cow", "komodo", "gecko", "pig", "deer", "gorilla", "monkey", "snake", "eagle", "whale", "salmon", "baraccuda", "zebra", "giraffe", "catfish", "cicada", "bat", "horse", "ant", "worm", "dragonfly"}; 

        string secretWord = chooseRandomWord(words); 

        double remainingAttempts = secretWord.length(); 

        string guessedLetters; 

        bool found = false; 

        while(remainingAttempts > 0 && !found){
            cout << "Word: " << displayWord(secretWord, guessedLetters) << '\n';
            cout << "Guessed letters: " << guessedLetters << '\n';
            cout << "Lives: " << remainingAttempts << '\n';

            char guess;
            cout << "Guess a word: ";
            cin >> guess;

            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clears input buffer
            
            if(guessedLetters.find(guess) != string::npos){ //if the new guess is already at the guessedLetters string
                cout << "You guessed that letter already" << '\n';
                continue;
            }

            guessedLetters += guess; 

            if(secretWord.find(guess) != string::npos){ //if the letter that we guess is in the secretWord
                cout << "Correct guess" << '\n' << '\n';                
            }

            else{
                cout << "Wrong guess" << '\n' << '\n';
                remainingAttempts--;
            }

            if(displayWord(secretWord, guessedLetters) == secretWord){ 
                printwinascii();
                cout << "CONGRATULATIONS, you guessed the right word, word: " << secretWord<< '\n';
                found = true;        
            }
        }
        
        if(remainingAttempts == 0){ 

            printloseascii();
            cout << "YOU LOSE, the secret word: " << secretWord << '\n';
        }

            double tempScore = (remainingAttempts / secretWord.length()) * 10.0; //calculate the scores of the user
            double playerScore = tempScore; 

            double scores = leaderboard.changeScore(playerName, playerScore); //change the player score
            int attempt = leaderboard.updateattempts(playerName); 
            
            double riilscore = scores / attempt ; 
            leaderboard.updateavrgScore(playerName, riilscore); //average score out of all attempts

            leaderboard.display();

            cout << "Do you want to play again? (y/n): ";
            cin >> playAgain;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clears input buffer

    } while (playAgain == 'y');
    sort(leaderboard.players.begin(), leaderboard.players.end(), [](const Player& a, const Player& b) {
        return a.avrgscore > b.avrgscore ; 
    }); //descending sort for the leaderboard

    leaderboard.display();
    return 0;
}
