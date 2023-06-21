#include <iostream>
#include <string>
#include <windows.h>

// Функция для изменения текущей директории
void change_directory(const std::string& path) {
    if (SetCurrentDirectory(path.c_str())) {
        char buffer[MAX_PATH];
        GetCurrentDirectory(MAX_PATH, buffer);
        std::cout << "Текущая директория: " << buffer << std::endl;
    } else {
        std::cout << "Ne udalos poluchit." << std::endl;
    }
}

// Функция для вывода содержимого текущей директории
void list_directory() {
    WIN32_FIND_DATA findData;
    HANDLE hFind = FindFirstFile("*", &findData);
    if (hFind == INVALID_HANDLE_VALUE) {
        std::cout << "Ne udalos poluchit." << std::endl;
        return;
    }
    do {
        std::cout << findData.cFileName << std::endl;
    } while (FindNextFile(hFind, &findData));
    FindClose(hFind);
}

int main() {
    std::string command;
    while (true) {
        std::cout << ">";
        std::getline(std::cin, command);

        if (command == "exit") {
            break;
        } else if (command.substr(0, 3) == "cd ") {
            change_directory(command.substr(3));
        } else if (command == "dir") {
            list_directory();
        } else {
            std::cout << "Neizvestnaya komanda" << std::endl;
        }
    }

    return 0;
}
