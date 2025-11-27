#include <iostream>

class PetraPsalidiXarti {
public:
    void play() {
        char again;
        do {
            int user = getUserChoice();
            int computer = getComputerChoice();
            determineWinner(user, computer);
            std::cout << "Play again? (y/n): ";
            std::cin >> again;
            std::cout << std::endl;
            srand(time(0));
        } while (again == 'y' || again == 'Y');

        std::cout << "Thanks for playing!" << std::endl;
    }
private:
    enum Choice { ROCK = 1, PAPER, SCISSORS };

    int getUserChoice() {
        int choice;
        std::cout << "Choose [1] Rock, [2] Paper, [3] Scissors: ";
        std::cin >> choice;
        while (choice < 1 || choice > 3) {
            std::cout << "Invalid choice. Try again: ";
            std::cin >> choice;
        }
        return choice;
    }

    int getComputerChoice() {
        srand(time(0)); 
        return rand() % 3 + 1; 
    }

    void determineWinner(int user, int computer) {
        std::cout << "You chose: " << choiceToString(user) << std::endl;
        std::cout << "Computer chose: " << choiceToString(computer) << std::endl;

        if (user == computer)
            std::cout << "It's a tie!" << std::endl;
        else if ((user == ROCK && computer == SCISSORS) ||
                 (user == PAPER && computer == ROCK) ||
                 (user == SCISSORS && computer == PAPER))
            std::cout << "You win!" << std::endl;
        else
            std::cout << "Computer wins!" << std::endl;
    }

    std::string choiceToString(int choice) {
        switch (choice) {
            case ROCK: return "Rock";
            case PAPER: return "Paper";
            case SCISSORS: return "Scissors";
            default: return "Invalid";
        }
    }
};

int main() {
    PetraPsalidiXarti game;
    game.play();
    return 0;
}