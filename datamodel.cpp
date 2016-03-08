#include "datamodel.h"

DataModel::DataModel()
{
    mPath = "D:\\And" ;                       //testing
}
vector <path> DataModel::listOfFiles()
{
    vector <path> v;
    for (auto&& x : directory_iterator(mPath))
        v.push_back(x.path());
    return v;
}
bool DataModel::isDirectory(const path &filePath)
{
    return is_directory(filePath);
}
unsigned long DataModel::size(const path &filePath)
{
    return file_size(filePath);
}
