#ifndef COMMANDLINEREADER_H
#define COMMANDLINEREADER_H
#include<configurationreader.h>
#include<configuration.h>
#include<iostream>


class CommandLineReader : public ConfigurationReader
{
public:
    CommandLineReader();
    CommandLineReader( int port ,std::string DocRoot ,std::string ipAddress ="0.0.0.0");
    void configInitialization(Configuration  &configObj);

private:

    std::string mipAddress;
    int mPort;
    std::string mDocRoot;


};

#endif // COMMANDLINEREADER_H
