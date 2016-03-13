#include "commandlinereader.h"

CommandLineReader::CommandLineReader(int argc, char *argv[]):
    configFileReaderIsSet(false)
{
    po::options_description generic("Generic options");
    generic.add_options()
            ("help", "Produce help message")
            ("about", "Output README information")
            ("config", po::value<std::string>(), "Read options from config file");

    po::options_description config("Configuration");
    config.add_options()
            ("dir", po::value<std::string>(&mDocRoot)->required(), "Set root folder")
            ("port", po::value<int>(&mPort)->default_value(8080), "Port server use to connect to clinets")
            ("dpermission", po::value<bool>(&mDownloadPermission)->default_value(true),
                                                                     "set permission to download files")
            ("vicon", po::value<bool>(&mVisibleIcon)->default_value(false),
                                                                     "Visibility of displaying icon column")
            ("vsize", po::value<bool>(&mVisibleSize)->default_value(false),
                                                                     "Visibility of displaying size column")
            ("vinfo", po::value<bool>(&mVisibleInfo)->default_value(false),
                                                                     "Visibility of displaying info column")
            ("fsize", po::value<std::string>(&mUnit)->default_value("bytes"),
                                                                     "Specify the file size displaying mode");

    po::options_description cmdOptions;
    cmdOptions.add(generic).add(config);

    po::positional_options_description p;
    p.add("dir", -1);

    po::variables_map vm;
    store(po::command_line_parser(argc, argv).options(cmdOptions).positional(p).run(), vm);

    if (vm.count("help"))
    {
        std::cout << "Configuration commands" << std::endl
                  << cmdOptions << std::endl;
        exit(1);
    }
    if (vm.count("about"))
    {
       //print readme info func
        exit(1);
    }

    if (vm.count("config"))
    {
        configFileReaderIsSet = true;
        configFileReader = new ConfigurationFileReader(vm["config"].as<std::string>());
    }
    else
    {
      notify(vm);//throws if required options are not initialized,
                 //so do afterfunctions that can abort program

        if (vm.count("fsize")
                && vm["fsize"].as<std::string>() != "bytes"
                && vm["fsize"].as<std::string>() != "kilobytes"
                && vm["fsize"].as<std::string>() != "megabytes"
                && vm["fsize"].as<std::string>() != "automatically")
        {
            throw std::exception("Bad size type");
        }
    }
}

CommandLineReader::~CommandLineReader()
{
    if (configFileReaderIsSet)
    {
        delete configFileReader;
    }
}

void CommandLineReader::configInitialization(Configuration &configObj)
{
    if (configFileReaderIsSet)
    {
        configFileReader->configInitialization(configObj);
    }
    else
    {
        ConfigurationReader::configInitialization(configObj);
    }
}


