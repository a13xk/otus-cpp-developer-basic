#include <iostream>
#include <ctime>

void printHeader() 
{
    std::cout << "╔═══════════════════════╗" << std::endl;
    std::cout << "║ Guess The Number Game ║" << std::endl;
    std::cout << "╚═══════════════════════╝" << std::endl;
    std::cout << "Enter your guess:" << std::endl;
}

int randomValue()
{
    const int max_value = 100;
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    return std::rand() % max_value;
}


int main()
{
    const int target_value = randomValue();
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
