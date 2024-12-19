#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <vector>

extern std::vector<Tube> tubes;

// Структуры
struct Tube {
    std::string name;
    double length;
    double diameter;
    bool inRepair;
};

struct CompressionStation {
    std::string name;
    int numbersOfWorkshops;
    int workshopsAtWork;
    int efficiency;
};

// Прототипы функций
void Print();
void incorrectData();

Tube createTube();
CompressionStation createCompressionStation();

void displayTube(const Tube& tube);
void displayCompressionStation(const CompressionStation& cs);

void editTube(Tube& tube);
void editCompressionStation(CompressionStation& cs);

void saveToFile(const Tube& tube, const CompressionStation& cs);
Tube readingTube(std::ifstream& fin);
CompressionStation readingCS(std::ifstream& fin);
void loadFromFile(Tube& tube, CompressionStation& cs);

#endif // HEADER_H
