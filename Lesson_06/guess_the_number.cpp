#include <iostream>

void printHeader() 
{
    std::cout << "╔═══════════════════════╗" << std::endl;
    std::cout << "║ Guess The Number Game ║" << std::endl;
    std::cout << "╚═══════════════════════╝" << std::endl;
    std::cout << "Enter your guess:" << std::endl;
}


int main()
{
    const int target_value = 54;
    int current_value = 0;
    bool not_win = true;

    printHeader();

    do {
        std::cin >> current_value;

        if (current_value < target_value) {
            std::cout << "You entered " << current_value << ". It is less than guessed number, please try again" << std::endl;
        }
        else if (current_value > target_value) {
            std::cout << "You entered " << current_value << ". It is greater than guessed number, please try again" << std::endl;
        }
        else {
            std::cout << "Congratulation! You guessed correct number!" << std::endl;
            break;
        }

    } while(true);

    return 0;
}
