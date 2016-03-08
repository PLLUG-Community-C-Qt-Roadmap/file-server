#include "commandlinereader.h"

CommandLineReader::CommandLineReader(int argc, char *argv[])
{
    std::string configFileName = "no config file";

    po::options_description desc("Allowed options");
    desc.add_options()
            ("help", "Produce help message")
            ("about", "Output README information")
            ("port", po::value<int>(&mPort)->default_value(8080), "Port server use to connect to clinets")
            ("dir", po::value<std::string>(&mDocRoot)->required(), "Set root folder")
            ("ip", po::value<std::string>(&mIP)->default_value("127.0.0.1"), "Set ip")
            ("config", po::value<std::string>(&configFileName), "Read options from config file")
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

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);

    if (vm.count("help"))
    {
        std::cout << "Configuration commands" << std::endl
                  << desc << std::endl;
        exit(1);
    }
    if (vm.count("about"))
    {
        //print readme info func
        exit(1);
    }

    po::notify(vm); //throws on error, so so do after help in case there are any problems

    if (vm.count("config"))
    {
        //call config file reader
    }
    else
    {
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

void CommandLineReader::configInitialization(Configuration &configObj)
{
    configObj.setPort(mPort);
    configObj.setIpAddress(mIP);
    configObj.setDocRoot(mDocRoot);
    configObj.setUnit(mUnit);
    configObj.setDownloadPermission(mDownloadPermission);
    configObj.setVisibleIcon(mVisibleIcon);
    configObj.setVisibleSize(mVisibleSize);
    configObj.setVisibleInfo(mVisibleInfo);
}
