#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <algorithm>

using namespace std;

struct Player{
    string username;
    double score;
    Player(const string& name) : username(name), score(0) {} //constructor to initialize the score to 0
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

    void updateScore(const string& name, double score) {
        for (auto &player : players) {
            if (player.username == name) {
                player.score += score;
                break;
            }
        } //update the player score
    }

    void display() {
        cout << "\nLeaderboard:\n";
        int rank = 1;
        for (const auto& player : players) {
            cout << rank << ". "<< "Username: " << player.username << ", Score: " << player.score << endl;
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

int main() {

    Leaderboard leaderboard; 

    char playAgain;
    do {
        cout << "***************" << '\n';
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
                cout << "CONGRATULATIONS, you guessed the right word, word: " << secretWord<< '\n';
                found = true;        
            }
        }
        
        if(remainingAttempts == 0){
            cout << "YOU LOSE, the secret word: " << secretWord << '\n';
        }

            double tempScore = (remainingAttempts / secretWord.length()) * 10.0; //calculate the scores of the user
            double playerScore = tempScore; 
            leaderboard.updateScore(playerName, playerScore);
            leaderboard.display();

            cout << "Do you want to play again? (y/n): ";
            cin >> playAgain;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clears input buffer

    } while (playAgain == 'y');
    sort(leaderboard.players.begin(), leaderboard.players.end(), [](const Player& a, const Player& b) {
        return a.score > b.score; 
    }); //descending sort for the leaderboard

    leaderboard.display();
    return 0;
}
