#ifndef CONFIGURABLE_H
#define CONFIGURABLE_H
#include<configuration.h>


class Configurable
{
public:
    Configurable(const Configuration  &configObj);
    Configurable(const Configurable &) = delete;

    int port() const;
    std::string ipAddress() const;
    std::string docRoot() const;
    std::string unit() const;
    bool downloadPermission() const;
    bool visibleIcon() const;
    bool visibleSize() const;
    bool visibleInfo() const;

private:
    Configuration mConfigObj;

};

#endif // CONFIGURABLE_H
