#include <random>
#include <iostream>

int game(int players_guess, int random_number) {
    int silly_counter = 0;
    while(players_guess != random_number) {
        if(players_guess > 0 && players_guess < 101) {
            if(players_guess > random_number) {
                std::cout << "Nuh uh, my number is lower. ▼" << std::endl;
                std::cin >> players_guess;
            }
            else if(players_guess < random_number) {
                std::cout << "Nope, my number is GREATER. ▲" << std::endl;
                std::cin >> players_guess;
            }
        }
        else {
            if(silly_counter <= 2) {
                std::cout << "Stop being SILLY~ and and enter number between 1 and 100 ☻" << std::endl;
                silly_counter += 1;
                std::cin >> players_guess;
            }
            else if (silly_counter == 3) {
                std::cout << ". . .\n" "I repeat last time, NUMBER BETWEEN 1 AND 100:" << std::endl;
                silly_counter += 1;
                std::cin >> players_guess;
            }
            else if (silly_counter == 4 && (players_guess < 0 || players_guess > 100)){
                break;
            }
        }
        
    }
    std::cout << "░▒▓ CONGRATULATIONS!!! ▓▒░\n" "You've guessed my number, " << random_number << " ♥" << std::endl;
}

int main() {
    std::cout << "NUMBER GUESSING GAME (1-100)" << std::endl;

    std::random_device rd;  // 1
    std::mt19937 gen(rd());  // 2
    std::uniform_int_distribution<int> distrib(1, 100);  // 3
    int random_number = distrib(gen);  // 4
    
    std::cout << "The number was generated.\n" "Wath's your guess?\n" "Enter the number from 1 to 100: ";
    
    int anger_counter = 0;
    int players_guess;
    std::cin >> players_guess;

    if(0 < players_guess && players_guess < 101) {
        game(players_guess, random_number);
    }
    else{
            do { 
            if (anger_counter <= 2) {
                std::cout << "I've said 'Enter the number from 1 to 100': ";
                std::cin >> players_guess;
                anger_counter += 1;
            }
            else if (anger_counter == 3) {
                std::cout << ". . .\n" "I repeat last time, NUMBER BETWEEN 1 AND 100:" << std::endl;
                std::cin >> players_guess;
                anger_counter += 1;
            }
            else if (anger_counter == 4 && (players_guess < 0 || players_guess > 100)){
                break;
            }
        } while((0 > players_guess) || (100 < players_guess));
        if(0 < players_guess && players_guess < 101) {
            game(players_guess, random_number);
        }
    }

    return 0;
}


// КОММЕНТАРИИ

// 1
/* Получаем сид для генерации случайнного 
    числа с устройства и записываем в объект-генератор rd,
    который после своего вызова как функции вернёт на
    место вызова сид */

// 2
/* С помощью генератора mt19937 инициализируем сам
    генератор чисел, который в будущем будет вызываться
    как gen, а тот в свою очередь выдаст случайное число
    по сиду от rd() */

// 3
/* Задаём диапазон, в котором будет находиться
    сгенерированное число. Диапазон храниться внутри
    объекта, который поможет gen выдать число в нужном
    диапазоне с равным шансом */

// 4
/* Создаём переменную с типом данных "Целые числа"
    и генерируем там число. */