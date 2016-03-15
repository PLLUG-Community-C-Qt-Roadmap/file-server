#ifndef COMMANDLINEREADER_H
#define COMMANDLINEREADER_H
#include <configurationreader.h>
#include <configuration.h>
#include <configurationfilereader.h>
#include <iostream>
#include <fstream>
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>

namespace po = boost::program_options;

class CommandLineReader : public ConfigurationReader
{
public:
    CommandLineReader(int argc , char* argv[]);
    ~CommandLineReader();
    void configInitialization(Configuration  &configObj) override;

private:
    ConfigurationFileReader *configFileReader;
};

#endif // COMMANDLINEREADER_H
