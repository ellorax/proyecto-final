#include "binaryfile.h"

BinaryFile::BinaryFile(string n)
    :fileName(n)
{

}
/*
void BinaryFile::save_binary(LinkedList<Image> &v)
{
    ofstream f;
    f.open(this->fileName,ios::out|ios::binary);
    int  tmp;
    for(LinkedList<Image>::iterator it= v.begin();it!=++v.end();++it){
        tmp=(*it).getPath().size();
        f.write((char *)&tmp, sizeof(int));
        f.write( (*it).getPath().c_str(), (*it).getPath().size());
        tmp=(*it).getName().size();
        f.write((char *)&tmp, sizeof(int));
        f.write( (*it).getName().c_str(), (*it).getName().size());
    }
    f.close();
}
void BinaryFile::binaryLoad(LinkedList<Image> &v)
{
    ifstream f;
    f.open(this->fileName,ios::binary);
    if(f.fail())
    {
        return;
    }
    else
    {
        Image s;
        int size_string;
        while(f.read((char*)&size_string,sizeof(int))){
            char c[size_string + 1];
            f.read((char*)&c,size_string);
            c[size_string] = '\0';
            s.setName(c);
            f.read((char *)&size_string,sizeof(int));
            char c2[size_string+1];
            f.read((char*)&c2,size_string);
            c2[size_string] = '\0';
            s.setPath(c2);
            v.insertAtBack(s);
        }
    }
    f.close();
}
*/
