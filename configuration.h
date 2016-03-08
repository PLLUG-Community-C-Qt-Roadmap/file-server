#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include<iostream>

class Configuration
{
public:
    Configuration();
    void setIpAddress(std::string ipAddress);
    void setPort(int port);
    void setDocRoot(std::string docRoot);
    std::string ipAddress() const ;
    int port() const ;
    std::string docRoot() const;


private:
    std::string mIpAddress;
    int mPort;
    std::string mDocRoot;
};

#endif // CONFIGURATION_H
