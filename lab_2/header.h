#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <unordered_map>
#include <vector>

struct Pipe {
    int id;
    std::string name;
    bool inRepair;
};

struct CompressorStation {
    int id;
    std::string name;
    int totalShops;
    int inactiveShops;
};

void addPipe();
void editPipe();
void deletePipe();
void findPipes();
void batchEditPipes();

void addStation();
void editStation();
void deleteStation();
void findStations();

void menu();

#endif 