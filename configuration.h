#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include<iostream>

class Configuration
{
public:
    Configuration();
    void setPort(const int &port);
    void setIpAddress(const std::string &ipAddress);
    void setDocRoot(const std::string &docRoot);
    void setUnit(const std::string &unit);
    void setDownloadPermission(const bool &p);
    void setVisibleIcon(const bool &v);
    void setVisibleSize(const bool &v);
    void setVisibleInfo(const bool &v);

    int port() const ;
    std::string ipAddress() const ;
    std::string docRoot() const;
    std::string unit() const;
    bool downloadPermission() const;
    bool visibleIcon() const;
    bool visibleSize() const;
    bool visibleInfo() const;

private:
    int mPort;
    std::string mIP;
    std::string mDocRoot;
    std::string mUnit;

    bool mDownloadPermission;
    bool mVisibleIcon;
    bool mVisibleSize;
    bool mVisibleInfo;
};

#endif // CONFIGURATION_H
