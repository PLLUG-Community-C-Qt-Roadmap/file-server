#ifndef CONFIGURABLE_H
#define CONFIGURABLE_H
#include<configuration.h>


class Configurable
{
public:
    Configurable(Configuration  &configObj);
    Configurable(const Configurable &) = delete;


protected:
    Configuration& configuration() const;

private:

    Configuration &mConfigObj;
};

#endif // CONFIGURABLE_H
