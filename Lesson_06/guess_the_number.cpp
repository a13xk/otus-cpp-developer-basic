#include <iostream>
#include <ctime>

void print_header()
{
    std::cout << "╔═══════════════════════╗" << std::endl;
    std::cout << "║ Guess The Number Game ║" << std::endl;
    std::cout << "╚═══════════════════════╝" << std::endl;
}

int random_value()
{
    const int max_value = 100;
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    return std::rand() % max_value;
}

std::string ask_for_name()
{
    std::cout << "Hi! Enter your name, please:" << std::endl;
    std::string user_name;
    std::cin >> user_name;
    return user_name;
}


int main()
{
    const int target_value = random_value();
    int current_value = 0;
    unsigned int attempts = 0;

    print_header();
    std::string user_name = ask_for_name();

    std::cout << "Enter your guess:" << std::endl;
    do {
        std::cin >> current_value;
        attempts++;
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
    std::cout << "Attempts taken: " << attempts << std::endl;
    return 0;
}
