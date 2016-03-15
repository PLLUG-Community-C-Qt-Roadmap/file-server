#ifndef CONFIGURATIONFILEREADER_H
#define CONFIGURATIONFILEREADER_H
#include <configurationreader.h>
#include <configuration.h>
#include <iostream>
#include <fstream>
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>

namespace po = boost::program_options;

class ConfigurationFileReader: public ConfigurationReader
{
public:
    ConfigurationFileReader(std::string configFile);
    void configInitialization(Configuration  &configObj) override;

};

#endif // CONFIGURATIONFILEREADER_H
