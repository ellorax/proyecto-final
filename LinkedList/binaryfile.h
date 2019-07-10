#ifndef BINARYFILE_H
#define BINARYFILE_H

#include <iostream>
#include <fstream>
#include "mainwindow.h"
using namespace std;
class BinaryFile
{
public:
    BinaryFile(string);
    void save_binary(LinkedList<Image> &v);
    void binaryLoad(LinkedList<Image> &v);

private:
    string fileName;
};

#endif // BINARYFILE_H
