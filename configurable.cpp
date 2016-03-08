#include "configurable.h"

Configurable::Configurable(Configuration &configObj):mConfigObj(configObj)
{
}

Configuration& Configurable::configuration()const
{
    return mConfigObj;
}

