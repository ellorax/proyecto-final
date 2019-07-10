#include "image.h"

Image::Image(string name,string path)
    :name(name),path(path)
{

}

string Image::getName() const
{
    return name;
}

void Image::setName(const string &value)
{
    name = value;
}

vector<string> Image::getLabels() const
{
    return labels;
}

void Image::setLabels(const vector<string> &value)
{
    labels = value;
}

string Image::getPath() const
{
    return path;
}

void Image::setPath(const string &value)
{
    path = value;
}
