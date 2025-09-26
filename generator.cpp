#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    // Открываем файл с шутками
    std::ifstream file("jokes.txt");
    if (!file.is_open()) {
        std::cerr << "Could not open jokes.txt\n";
        return 1;
    }

    // Считываем шутки из файла
    std::vector<std::string> jokes;
    std::string line;
    while (std::getline(file, line)) {
        // Ищем разделитель ';' (предполагаем, что до него что-то вроде ID или категории)
        size_t pos = line.find(';');
        if (pos != std::string::npos) {
            // Берём текст после ';'
            std::string joke = line.substr(pos + 1);
            // Убираем лишний пробел в начале, если есть
            if (!joke.empty() && joke[0] == ' ')
                joke.erase(0, 1);
            // Добавляем шутку в вектор
            jokes.push_back(joke);
        }
    }
    file.close();

    // Проверяем, есть ли хоть одна шутка
    if (jokes.empty()) {
        std::cerr << "File is empty or no jokes found\n";
        return 1;
    }

    // Инициализируем генератор случайных чисел текущим временем
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    // Выбираем случайный индекс шутки
    int index = std::rand() % jokes.size();

    // Выводим случайную шутку
    std::cout << "Random joke:\n";
    std::cout << jokes[index] << "\n";

    return 0;
}
