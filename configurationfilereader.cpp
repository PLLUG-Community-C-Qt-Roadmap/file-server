#include "configurationfilereader.h"


ConfigurationFileReader::ConfigurationFileReader(std::string configFile)
{
    boost::filesystem::path rootPath( boost::filesystem::current_path() );//file must be located in
    std::string strRootPath = rootPath.string();                          //build folder
    strRootPath += "\\";

    configFile.insert(0, strRootPath);

    std::ifstream ifs(configFile.c_str());
    if (!ifs)
    {
        std::cout << "can not open config file: " << configFile << std::endl;
        exit(1);
    }

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

    po::variables_map vm;
    store(parse_config_file(ifs, config), vm);
    notify(vm);

    if (vm.count("fsize")
            && vm["fsize"].as<std::string>() != "bytes"
            && vm["fsize"].as<std::string>() != "kilobytes"
            && vm["fsize"].as<std::string>() != "megabytes"
            && vm["fsize"].as<std::string>() != "automatically")
    {
        throw std::exception("Bad size type");
    }
}

void ConfigurationFileReader::configInitialization(Configuration &configObj)
{
    ConfigurationReader::configInitialization(configObj);
}
