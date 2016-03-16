#ifndef CONFIGURABLE_H
#define CONFIGURABLE_H
#include<configuration.h>


class Configurable
{
public:
    Configurable(Configuration  &configObj);
    Configurable(const Configurable &) = delete;


protected:
    const Configuration& configuration();

private:

    Configuration &mConfigObj;
};

#endif // CONFIGURABLE_H
