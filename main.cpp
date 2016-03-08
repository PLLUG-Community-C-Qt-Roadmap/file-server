#include <iostream>
#include<configuration.h>
#include<filewebserver.h>
#include<commandlinereader.h>
#include<string>
#include<boost/asio.hpp>
#include"datamodel.h"
using namespace std;
using namespace boost::asio;
int main(int argc , char* argv[])
{
    DataModel o;
    vector <path> mas = o.listOfFiles();
    for(path  &x :mas)
    {
        if(o.isDirectory(x))
        cout<<x<<" is directory!"<<endl;
    }
    /*
    try
    {
  CommandLineReader commandReader(atoi(argv[2]),argv[4]);
  Configuration config;
  commandReader.configInitialization(config);
  FileWebServer server(config);
  server.run();
}
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
    system("pause");*/
    return 0;
}

