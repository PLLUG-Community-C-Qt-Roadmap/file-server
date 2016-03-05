#include "filewebserver.h"
using namespace boost::asio;
FileWebServer::FileWebServer( Configuration &configObj):Configurable(configObj),
mPort(configObj.getPort()),mipAddress(configObj.getIpAddress()),mDocRoot(configObj.getDocRoot())
{

mSocket = new ip::tcp::socket(m_io_service);
mAcceptor = new ip::tcp ::acceptor(m_io_service,ip::tcp::endpoint(ip::tcp::v4(),mPort));
}

void FileWebServer::run()
{
printDirectoryTree();
    for(;;)
    {
        mAcceptor->accept(*mSocket);
        boost::system::error_code error;
        boost::asio::write(*mSocket, boost::asio::buffer(mMainText.str()),error);
        std::cout << "connection successful!" << std::endl;
        mSocket->close();
    }
}

void FileWebServer::printDirectoryTree()
{

    std::string header = "<html>\n<head><title>This is title</title></head>\n<body>";
    std::string footer = "</body>\n</html>\n";
    std::string html = header + mDocRoot + footer;
    mMainText << "HTTP/1.1 200 OK" << std::endl;
    mMainText << "content-type: text/html" << std::endl;
    mMainText << "content-length: " << html.length() << std::endl;
    mMainText << std::endl;
    mMainText << html;

}

