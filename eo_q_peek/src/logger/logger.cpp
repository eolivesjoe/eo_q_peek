#include <iostream>
#include "logger.h"

namespace logger 
{
    void Init()
    {
        std::ios::sync_with_stdio(false);
    }

    void logger::Info(const std::string& msg)
    {
        std::cout << "[INFO] " << msg << std::endl;
    }

    void logger::Warning(const std::string& msg)
    {
        std::cout << "[WARNING] " << msg << std::endl;
    }

    void logger::Error(const std::string & msg)
    {
        std::cerr << "[ERROR] " << msg << std::endl;
    }
}