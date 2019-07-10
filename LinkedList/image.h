#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include <vector>
using namespace std;
class Image
{
public:
    Image();
    Image(string name,string path);
    string getName() const;
    void setName(const string &value);
    vector<string> getLabels() const;
    void setLabels(const vector<string> &value);
    string getPath() const;
    void setPath(const string &value);

private:
    string name;
    string path;
    vector<string> labels;
};

#endif // IMAGE_H
