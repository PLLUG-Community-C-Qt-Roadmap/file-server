#include "configuration.h"

Configuration::Configuration()
{

}

void Configuration::setIpAddress(const std::string &ipAddress)
{
    mIP = ipAddress;
}

void Configuration::setPort(const int &port)
{
    mPort = port;
}

void Configuration::setDocRoot(const std::string &docRoot)
{
    mDocRoot = docRoot;
}

void Configuration::setUnit(const std::string &unit)
{
    mUnit = unit;
}

void Configuration::setDownloadPermission(const bool &p)
{
    mDownloadPermission = p;
}

void Configuration::setVisibleIcon(const bool &v)
{
    mVisibleIcon = v;
}

void Configuration::setVisibleSize(const bool &v)
{
    mVisibleSize = v;
}

void Configuration::setVisibleInfo(const bool &v)
{
    mVisibleInfo = v;
}

std::string Configuration::ipAddress() const
{
    return mIP;
}

int Configuration::port() const
{
    return mPort;
}

std::string Configuration::docRoot() const
{
    return mDocRoot;
}

std::string Configuration::unit() const
{
    return mUnit;
}

bool Configuration::downloadPermission() const
{
    return mDownloadPermission;
}

bool Configuration::visibleIcon() const
{
    return mVisibleIcon;
}

bool Configuration::visibleSize() const
{
    return mVisibleSize;
}

bool Configuration::visibleInfo() const
{
    return mVisibleInfo;
}

