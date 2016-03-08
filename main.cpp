#include <iostream>
#include<configuration.h>
#include<filewebserver.h>
#include<commandlinereader.h>
#include<string>
#include<boost/asio.hpp>

using namespace std;
using namespace boost::asio;

int main(int argc , char* argv[])
{
    try
    {
        CommandLineReader commandReader(argc, argv);
        Configuration config;
        commandReader.configInitialization(config);
        FileWebServer server(config);
        server.run();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

