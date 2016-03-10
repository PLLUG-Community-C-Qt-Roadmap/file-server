#include "configurable.h"

Configurable::Configurable(Configuration &configObj): mConfigObj(configObj)
{
}

int Configurable::port() const
{
    return mConfigObj.port();
}

std::string Configurable::ipAddress() const
{
    return mConfigObj.ipAddress();
}

std::string Configurable::docRoot() const
{
    return mConfigObj.docRoot();
}

std::string Configurable::unit() const
{
    return mConfigObj.unit();
}

bool Configurable::downloadPermission() const
{
    return mConfigObj.downloadPermission();
}

bool Configurable::visibleIcon() const
{
    return mConfigObj.visibleIcon();
}

bool Configurable::visibleSize() const
{
    return mConfigObj.visibleSize();
}

bool Configurable::visibleInfo() const
{
    return mConfigObj.visibleInfo();
}

