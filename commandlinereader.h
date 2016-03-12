#ifndef COMMANDLINEREADER_H
#define COMMANDLINEREADER_H
#include <configurationreader.h>
#include <configuration.h>
#include <iostream>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

class CommandLineReader : public ConfigurationReader
{
public:
    CommandLineReader(int argc , char* argv[]);
    void configInitialization(Configuration  &configObj) override;

private:
    int mPort;
    std::string mDocRoot;
    std::string mUnit;

    bool mDownloadPermission;
    bool mVisibleIcon;
    bool mVisibleSize;
    bool mVisibleInfo;

};

#endif // COMMANDLINEREADER_H
