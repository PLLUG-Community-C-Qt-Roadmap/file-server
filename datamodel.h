#ifndef DATAMODEL_H
#define DATAMODEL_H
#include <iostream>
#include <boost/filesystem.hpp>

using namespace std;
using namespace boost::filesystem;
class DataModel
{
public:
   DataModel();
   vector <path> listOfFiles();
   bool isDirectory(const path & filePath);
   unsigned long size(const path & filePath);
private:
   path mPath;
};

#endif // DATAMODEL_H
