#ifndef CONFIGURATIONREADER_H
#define CONFIGURATIONREADER_H
#include<configuration.h>


class ConfigurationReader
{
public:
    ConfigurationReader();
    virtual void configInitialization(Configuration &configObj) = 0;

};

#endif // CONFIGURATIONREADER_H
