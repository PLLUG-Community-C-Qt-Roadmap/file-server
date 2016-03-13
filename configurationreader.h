#ifndef CONFIGURATIONREADER_H
#define CONFIGURATIONREADER_H
#include<configuration.h>


class ConfigurationReader
{
public:
    ConfigurationReader();
    virtual void configInitialization(Configuration &configObj) = 0;

protected:
    int mPort;
    std::string mDocRoot;
    std::string mUnit;

    bool mDownloadPermission;
    bool mVisibleIcon;
    bool mVisibleSize;
    bool mVisibleInfo;
};

#endif // CONFIGURATIONREADER_H
