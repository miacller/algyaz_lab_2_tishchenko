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