#include "configurationreader.h"

ConfigurationReader::ConfigurationReader()
{

}

void ConfigurationReader::configInitialization(Configuration &configObj)
{
    configObj.setPort(mPort);
    configObj.setDocRoot(mDocRoot);
    configObj.setUnit(mUnit);
    configObj.setDownloadPermission(mDownloadPermission);
    configObj.setVisibleIcon(mVisibleIcon);
    configObj.setVisibleSize(mVisibleSize);
    configObj.setVisibleInfo(mVisibleInfo);
}

