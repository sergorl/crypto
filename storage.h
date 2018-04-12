#ifndef STORAGE_H_INCLUDED
#define STORAGE_H_INCLUDED

#include <stdio.h>
#include <fstream>


struct UTXO {
    UTXO() = default;

    UTXO(int i, const char* s) : id(i), str(s) {}

    int id;
    std::string str;

    void write(std::ofstream &os);

};

constexpr size_t SIZEUTXO = sizeof(UTXO);

std::ofstream make_file_stream();

UTXO recover(std::ifstream &os, size_t offset);


#endif // STORAGE_H_INCLUDED
