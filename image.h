#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include <vector>
using namespace std;
class Image
{
public:
    Image(string name);
    string getName() const;
    void setName(const string &value);
    vector<string> getLabels() const;
    void setLabels(const vector<string> &value);
private:
    string name;
    vector<string> labels;
};

#endif // IMAGE_H
