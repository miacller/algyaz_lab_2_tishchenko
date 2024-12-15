#include "header.h"
#include <iostream>
#include <algorithm>

std::unordered_map<int, Pipe> pipes;
std::unordered_map<int, CompressorStation> stations;
int nextPipeId = 1;
int nextStationId = 1;

void addPipe() {
    Pipe p;
    p.id = nextPipeId++;
    std::cout << "Введите название трубы: ";
    std::cin.ignore();
    std::getline(std::cin, p.name);
    std::cout << "Труба в ремонте? (1 - да, 0 - нет): ";
    std::cin >> p.inRepair;
    pipes[p.id] = p;
    std::cout << "Труба добавлена с ID: " << p.id << std::endl;
}

void editPipe() {
    int id;
    std::cout << "Введите ID трубы для редактирования: ";
    std::cin >> id;
    if (pipes.find(id) != pipes.end()) {
        std::cout << "Редактируем трубу ID: " << id << std::endl;
        std::cout << "Новое название трубы: ";
        std::cin.ignore();
        std::getline(std::cin, pipes[id].name);
        std::cout << "Труба в ремонте? (1 - да, 0 - нет): ";
        std::cin >> pipes[id].inRepair;
        std::cout << "Труба обновлена!" << std::endl;
    }
    else {
        std::cout << "Труба с таким ID не найдена." << std::endl;
    }
}

void deletePipe() {
    int id;
    std::cout << "Введите ID трубы для удаления: ";
    std::cin >> id;
    if (pipes.erase(id)) {
        std::cout << "Труба удалена." << std::endl;
    }
    else {
        std::cout << "Труба с таким ID не найдена." << std::endl;
    }
}

void findPipes() {
    std::cout << "Поиск труб:\n1. По названию\n2. По признаку \"в ремонте\": ";
    int option;
    std::cin >> option;
    if (option == 1) {
        std::string name;
        std::cout << "Введите название трубы: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        for (const auto& [id, p] : pipes) {
            if (p.name == name) {
                std::cout << "Труба ID: " << id << ", Название: " << p.name << ", В ремонте: " << (p.inRepair ? "Да" : "Нет") << std::endl;
            }
        }
    }
    else if (option == 2) {
        bool inRepair;
        std::cout << "Ищем трубы \"в ремонте\"? (1 - да, 0 - нет): ";
        std::cin >> inRepair;
        for (const auto& [id, p] : pipes) {
            if (p.inRepair == inRepair) {
                std::cout << "Труба ID: " << id << ", Название: " << p.name << ", В ремонте: " << (p.inRepair ? "Да" : "Нет") << std::endl;
            }
        }
    }
}

void batchEditPipes() {
    std::cout << "Пакетное редактирование труб:\n1. Все трубы\n2. Трубы по фильтру\nВыберите: ";
    int option;
    std::cin >> option;
    if (option == 1) {
        for (auto& [id, p] : pipes) {
            std::cout << "Труба ID: " << id << " (" << p.name << ") сейчас \"в ремонте\": " << (p.inRepair ? "Да" : "Нет") << std::endl;
            std::cout << "Новая метка \"в ремонте\": (1 - да, 0 - нет): ";
            std::cin >> p.inRepair;
        }
    }
    else if (option == 2) {
        findPipes();
        std::cout << "Введите ID труб для редактирования (через пробел, 0 для завершения): ";
        std::vector<int> ids;
        int id;
        while (std::cin >> id && id != 0) {
            ids.push_back(id);
        }
        for (int id : ids) {
            if (pipes.find(id) != pipes.end()) {
                std::cout << "Труба ID: " << id << " (" << pipes[id].name << ") сейчас \"в ремонте\": " << (pipes[id].inRepair ? "Да" : "Нет") << std::endl;
                std::cout << "Новая метка \"в ремонте\": (1 - да, 0 - нет): ";
                std::cin >> pipes[id].inRepair;
            }
            else {
                std::cout << "Труба с ID " << id << " не найдена." << std::endl;
            }
        }
    }
}
void addStation() {
    CompressorStation cs;
    cs.id = nextStationId++;
    std::cout << "Введите название КС: ";
    std::cin.ignore();
    std::getline(std::cin, cs.name);
    std::cout << "Общее количество цехов: ";
    std::cin >> cs.totalShops;
    std::cout << "Количество незадействованных цехов: ";
    std::cin >> cs.inactiveShops;
    stations[cs.id] = cs;
    std::cout << "КС добавлена с ID: " << cs.id << std::endl;
}

void editStation() {
    int id;
    std::cout << "Введите ID КС для редактирования: ";
    std::cin >> id;
    if (stations.find(id) != stations.end()) {
        std::cout << "Редактируем КС ID: " << id << std::endl;
        std::cout << "Новое название КС: ";
        std::cin.ignore();
        std::getline(std::cin, stations[id].name);
        std::cout << "Общее количество цехов: ";
        std::cin >> stations[id].totalShops;
        std::cout << "Количество незадействованных цехов: ";
        std::cin >> stations[id].inactiveShops;
        std::cout << "КС обновлена!" << std::endl;
    }
    else {
        std::cout << "КС с таким ID не найдена." << std::endl;
    }
}

void deleteStation() {
    int id;
    std::cout << "Введите ID КС для удаления: ";
    std::cin >> id;
    if (stations.erase(id)) {
        std::cout << "КС удалена." << std::endl;
    }
    else {
        std::cout << "КС с таким ID не найдена." << std::endl;
    }
}

void findStations() {
    std::cout << "Поиск КС:\n1. По названию\n2. По проценту незадействованных цехов: ";
    int option;
    std::cin >> option;
    if (option == 1) {
        std::string name;
        std::cout << "Введите название КС: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        for (const auto& [id, cs] : stations) {
            if (cs.name == name) {
                std::cout << "КС ID: " << id << ", Название: " << cs.name << ", Незадействованные цехи: " << cs.inactiveShops << "/" << cs.totalShops << std::endl;
            }
        }
    }
    else if (option == 2) {
        double percentage;
        std::cout << "Введите минимальный процент незадействованных цехов: ";
        std::cin >> percentage;
        for (const auto& [id, cs] : stations) {
            double inactivePercentage = (cs.totalShops > 0) ? (cs.inactiveShops * 100.0 / cs.totalShops) : 0.0;
            if (inactivePercentage >= percentage) {
                std::cout << "КС ID: " << id << ", Название: " << cs.name << ", Незадействованные цехи: " << inactivePercentage << "%" << std::endl;
            }
        }
    }
}

// Главное меню
void menu() {
    while (true) {
        std::cout << "\n-----------------------\n"
            << "1. Добавить трубу \n"
            << "2. Добавить КС \n"
            << "3. Просмотр всех объектов \n"
            << "4. Редактировать трубу \n"
            << "5. Редактировать КС \n"
            << "6. Удалить трубу \n"
            << "7. Удалить КС \n"
            << "8. Поиск труб \n"
            << "9. Поиск КС \n"
            << "10. Пакетное редактирование труб \n"
            << "0. Выход \n"
            << "-----------------------\n"
            << "Выберите пункт меню: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            addPipe();
            break;
        case 2:
            addStation();
            break;
        case 3:
            for (const auto& [id, p] : pipes) {
                std::cout << "Труба ID: " << id << ", Название: " << p.name << ", В ремонте: " << (p.inRepair ? "Да" : "Нет") << std::endl;
            }
            for (const auto& [id, cs] : stations) {
                std::cout << "КС ID: " << id << ", Название: " << cs.name << ", Незадействованные цехи: " << cs.inactiveShops << "/" << cs.totalShops << std::endl;
            }
            break;
        case 4:
            editPipe();
            break;
        case 5:
            editStation();
            break;
        case 6:
            deletePipe();
            break;
        case 7:
            deleteStation();
            break;
        case 8:
            findPipes();
            break;
        case 9:
            findStations();
            break;
        case 10:
            batchEditPipes();
            break;
        case 0:
            return;
        default:
            std::cout << "Некорректный выбор. Попробуйте снова." << std::endl;
        }
    }
}

int main() {
    menu();
    return 0;
}
