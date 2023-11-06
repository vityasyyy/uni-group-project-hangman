#include <iostream>
#include <vector>
#include <string>
#include <ctime> //library for the rand() function
#include <cstdlib> //library for the rand() function
#include <limits> //library used for the cin.ignore

using namespace std;

//function untuk menentukan kata yang akan ditebak
string chooseRandomWord(const vector<string> &words){
    //memilih suatu angka random dari 0 sampai size dari array words
    int randomIndex = rand() % words.size();

    //return kata yang berada di index ke-n dari array words 
    return words[randomIndex]; 
} 

//function untuk mendisplay kata yang ditebak
string displayWord(const string &word, const string &guessed){
    //menduplikasi word, string displayedWord adalah string word
    string displayedWord = word; 


    for(char c : word){ 
        //jika c belum ada di dalam guessed letters
        if(guessed.find(c) == string::npos){
            //pos akan di-set menurut index c pertama di displayedWord
            int pos = displayedWord.find(c);

            while(pos != string::npos){
                //ganti character di index[pos] menjadi '_'
                displayedWord[pos] = '_';
                //update pos, apakah masih ada kemunculan c di displayedWord, dimulai dari index pos+1
                pos = displayedWord.find(c, pos+1);
            }
        }
    }
    return displayedWord;
}

int main(){

    //seed untuk random number generator
    srand(static_cast<unsigned int>(time(nullptr))); 

    //array nama-nama hewan
    vector<string> words = {"singa", "buaya", "hiu"}; 

    //kata yang akan ditebak
    string secretWord = chooseRandomWord(words); 

    //jumlah nyawa, nyawa akan sesuai dengan panjang secret word
    int remainingAttempts = secretWord.length(); 

    //string untuk menyimpan huruf yang sudah ditebak
    string guessedLetters; 

    //boolean yang menyatakan apakah kata tersebut sudah berhasil ditebak atau belum
    bool found = false; 

    std::cout << "Tebak suatu nama hewan" << '\n';

    //loop untuk memulai permainan. Jika nyawa belum 0, dan kata belum berhasil ditebak
    while(remainingAttempts > 0 && !found){
        cout << "Kata: " << displayWord(secretWord, guessedLetters) << '\n';
        cout << "Huruf yang telah ditebak: " << guessedLetters << '\n';
        cout << "Nyawa: " << remainingAttempts << '\n';

        char guess;
        cout << "Tebak satu huruf: ";
        cin >> guess;

        //untuk memastikan bahwa input dari huruf hanya 1
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        
        if(guessedLetters.find(guess) != string::npos){
            cout << "Anda telah menebak huruf tersebut" << '\n';
            continue;
        }

        //menambahkan guess ke dalam string guessedLetters
        guessedLetters += guess; 

        //jika guess ada di dalam secret words
        if(secretWord.find(guess) != string::npos){
            cout << "Tebakan anda benar" << '\n' << '\n';
        }
        else{
            cout << "Tebakan anda salah" << '\n' << '\n';
            remainingAttempts--;
        }

        //jika display word sudah sama dengan secret word
        if(displayWord(secretWord, guessedLetters) == secretWord){
            cout << "Selamat, anda menebak kata yang benar, kata yang ditebak: " << secretWord<< '\n';
            found = true;        
        }
    }

    if(remainingAttempts == 0){
        cout << "Maaf, kamu kalah. Kata rahasia adalah: " << secretWord << '\n';
    }

    return 0;
}
