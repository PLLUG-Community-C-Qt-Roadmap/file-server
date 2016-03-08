#include <iostream>
#include<configuration.h>
#include<filewebserver.h>
#include<generator.h>
#include<commandlinereader.h>
#include<string>
#include<boost/asio.hpp>
#include <mstch/mstch.hpp>
using namespace std;
using namespace boost::asio;
int main(int argc , char* argv[])
{
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
    system("pause");
    return 0;
}

