#include "image.h"

Image::Image(string name)
    :name(name)
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
