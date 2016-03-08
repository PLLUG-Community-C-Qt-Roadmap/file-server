#include "commandlinereader.h"

CommandLineReader::CommandLineReader():ConfigurationReader()
{

}


CommandLineReader::CommandLineReader(int port, std::string DocRoot, std::string ipAddress):
    mipAddress(ipAddress),mDocRoot(DocRoot),mPort(port)
{

}

void CommandLineReader::configInitialization(Configuration &configObj)
{
    configObj.setIpAddress(mipAddress);
    configObj.setPort(mPort);
    configObj.setDocRoot(mDocRoot);
}
