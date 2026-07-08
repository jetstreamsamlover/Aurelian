#include <iostream>
#include <random>

int secretNumber;
int guess = 0;
char playAgain = 'y';
bool hasGuess = false;

void randomizer() {
     // Step 1: Setup random number generator
    std::random_device rd;   // Non-deterministic seed
    std::mt19937 gen(rd());  // Mersenne Twister engine
    std::uniform_int_distribution<> dist(1, 100); // Range [1, 100]

    secretNumber = dist(gen);
}

void guessing() {
std::cout << "Guess the number between 1 and 100! ";
     std::cin >> guess;
}

void toLow() {
     std::cout << "Too low! Try again! ";
     std::cin >> guess;
}

void toHigh() {
     std::cout << "Too high! Try again! ";
     std::cin >> guess;
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
          if (!hasGuess) {
               guessing();
          }
          hasGuess = false;

          while (guess != secretNumber)
          {
               if (guess > secretNumber) {
                    toHigh();
               }
               else {
                    toLow();
               }
          }

          pinPoint();

          if (playAgain == 'Y' || playAgain == 'y') {
               randomizer();
               hasGuess = true;
          }
     }
}