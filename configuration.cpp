#include "configuration.h"

Configuration::Configuration():mIpAddress("0.0.0.0"),mPort(0),mDocRoot("")
{

}

void Configuration::setIpAddress(std::string ipAddress)
{
    mIpAddress = ipAddress;
}

void Configuration::setPort(int port)
{
    mPort = port;
}

void Configuration::setDocRoot(std::string docRoot)
{
    mDocRoot = docRoot;
}

std::string Configuration::getIpAddress()
{
    return mIpAddress;
}

int Configuration::getPort()
{
    return mPort;
}

std::string Configuration::getDocRoot()
{
    return mDocRoot;
}

