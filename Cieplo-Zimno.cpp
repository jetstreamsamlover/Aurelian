#include <iostream>
#include <random>
//komunikat jezeli uzytkownik nie poda nic
//usun niepotrzebne pliki z repozytorium


int secretNumber;
float guess = 0;
char playAgain = 'y';
bool hasGuess = false;
bool isCharacter = false;

void randomizer() {
     // Step 1: Setup random number generator
     std::random_device rd;   // Non-deterministic seed
     std::mt19937 gen(rd());  // Mersenne Twister engine
     std::uniform_int_distribution<> dist(1, 100); // Range [1, 100]

     secretNumber = dist(gen);
}

void guessing() {
        // If user enters nothing and presses enter, input extraction fails and loop continues
          while (true) {
          std::cout << "Guess the number between 1 and 100! ";
          if (!(std::cin >> guess)) {
          std::cin.clear();
          std::cin.ignore(10000, '\n');
          } 
          else {
          isCharacter = false;
          break;
          }
        }
}

void toLow() {
        std::cout << "Too low! Try again! ";
        // If user enters nothing and presses enter, input extraction fails
        if (!(std::cin >> guess)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        isCharacter = true;
        } 
        else {
        isCharacter = false;
     }
}

void toHigh() {
     std::cout << "Too high! Try again! ";
     // If user enters nothing and presses enter, input extraction fails
     if (!(std::cin >> guess)) {
     std::cin.clear();
     std::cin.ignore(10000, '\n');
     isCharacter = true;
     std::cout << "Brutha, do you understand was is a number?\n";
     } else {
     isCharacter = false;
     }
}

void pinPoint() {
     
     std::cout << "Wow you hit it! Would you like to play again(Y/N)? ";
     std::cin >> playAgain;
     if(playAgain == 'Y' || playAgain == 'y') {
     guessing(); 
     }
     else {
     std::cout << "Fah you for leaving me!!!";
     }
}

int main() {
     randomizer();

     while (playAgain == 'Y' || playAgain == 'y') {
          isCharacter = true;
          while (isCharacter) {
               guessing();
          }


          while (guess != secretNumber){
          isCharacter = true;
          while (isCharacter) {
          if (guess > secretNumber) {
               toHigh();
          }
          else {
               toLow();
          }
     }
}

          pinPoint();

          if (playAgain == 'Y' || playAgain == 'y') {
               randomizer();
               hasGuess = true;
          }
     }
}