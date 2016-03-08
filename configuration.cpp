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

std::string Configuration::ipAddress() const
{
    return mIpAddress;
}

int Configuration::port() const
{
    return mPort;
}

std::string Configuration::docRoot() const
{
    return mDocRoot;
}

