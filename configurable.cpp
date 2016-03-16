#include "configurable.h"

Configurable::Configurable(Configuration &configObj):mConfigObj(configObj)
{
}

const Configuration& Configurable::configuration()
{
    return mConfigObj;
}

