#include <iostream>
#include <ctime>
#include <fstream>

/**
 * Print game header
 */
void print_header()
{
    std::cout << "╔═══════════════════════╗" << std::endl;
    std::cout << "║ Guess The Number Game ║" << std::endl;
    std::cout << "╚═══════════════════════╝" << std::endl;
}
/**
 * Return random value between 0 and max_value
 * @param max_value Upper limit for random number generation
 * @return
 */
int random_value(const int max_value)
{
    srand(time(nullptr)); // use current time as seed for random generator
    return rand() % max_value;
}
/**
 * Ask player to enter his/her name
 */
std::string ask_for_name()
{
    std::cout << "Hi! Enter your name, please:" << std::endl;
    std::string user_name;
    std::cin >> user_name;
    return user_name;
}
/**
 * Write user name and attempts count to high scores file
 * @param high_scores_filename Path to High Scores table file
 * @param user_name User name
 * @param attempts_taken Number of attempts taken to guess the number
 * @return
 */
int write_high_scores(const std::string& high_scores_filename, const std::string& user_name, unsigned int attempts_taken)
{
    std::ofstream out_file{high_scores_filename, std::ios_base::app};
    if (!out_file.is_open()) {
        std::cout << "Failed to open file for writing: " << high_scores_filename << "!" << std::endl;
        return -1;
    }
    out_file << user_name << ' ' << attempts_taken << std::endl;
    out_file.close();
    return 0;
}
/**
 * Print High Scores table read from file
 * @param high_scores_filename Path to High Scores table file
 * @return
 */
int print_high_scores(const std::string& high_scores_filename)
{
    std::ifstream in_file{high_scores_filename};
    if (!in_file.is_open()) {
        std::cout << "Failed to open file for reading: " << high_scores_filename << "!" << std::endl;
        return -1;
    }
    std::cout << "\n";
    std::cout << "╔═════════════╗" << std::endl;
    std::cout << "║ High Scores ║" << std::endl;
    std::cout << "╚═════════════╝" << std::endl;

    std::string username;
    unsigned int high_score=0;

    while (true)
    {
        in_file >> username;
        in_file >> high_score;
        in_file.ignore();
        if (in_file.fail()) break;
        std::cout << username << "\t" << high_score << std::endl;
    }
    in_file.close();
    return 0;
}
/**
 * Entry point
 */
int main(int argc, char** argv)
{
    const std::string high_scores_filename = "high_scores.txt";
    int max_value = 0;
    if (argc >= 2) {
        std::string key{argv[1]};
        if (key == "-max") {
            if (argc != 3)
            {
                std::cout << "Wrong usage! The '-max VALUE' parameter requires some value" << std::endl;
                return -1;
            }
            max_value = std::atoi(argv[2]);
        } else if (key == "-level"){
            if (argc != 3)
            {
                std::cout << "Wrong usage! The '-level VALUE' parameter requires some value" << std::endl;
                return -1;
            }
            int level_value = std::atoi(argv[2]);
            if (level_value == 1) {
                max_value = 10;
            } else if (level_value == 2) {
                max_value = 50;
            } else if (level_value == 3) {
                max_value = 100;
            } else {
                std::cout << "Wrong usage! The '-level VALUE' parameter supports 3 possible values:" << std::endl;
                std::cout << "-level 1 - random number is generated in range between 0 and 10" << std::endl;
                std::cout << "-level 2 - random number is generated in range between 0 and 50" << std::endl;
                std::cout << "-level 3 - random number is generated in range between 0 and 100" << std::endl;
                return -1;
            }

        } else if(key == "-table") {
            print_high_scores(high_scores_filename);
            return -1;
        } else {
            std::cout << "The following optional arguments are supportted:" << std::endl;
            std::cout << "'-max VALUE'   - upper limit for random number generation" << std::endl;
            std::cout << "'-level VALUE' - 3 possible upper limits for random number generation (1 - 10, 2 - 50, 3 - 100)" << std::endl;
            std::cout << "'-table'       - print High Scores table and exit" << std::endl;
            return -1;
        }
    }
    if (max_value < 0 || max_value > 100)
        max_value = 100;
    const int target_value = random_value(max_value);
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
    if (write_high_scores(high_scores_filename, user_name, attempts) != 0)
        return -1;
    if (print_high_scores(high_scores_filename) != 0)
        return -1;
    return 0;
}
