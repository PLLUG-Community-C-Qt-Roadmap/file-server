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
    std::string getIpAddress();
    int getPort();
    std::string getDocRoot();


private:
    std::string mIpAddress;
    int mPort;
    std::string mDocRoot;
};

#endif // CONFIGURATION_H
