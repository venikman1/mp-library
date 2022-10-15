#include "serialize.hpp"

#include <boost/program_options.hpp>

#include <iostream>
#include <stdexcept>
#include <string>

namespace po = boost::program_options;

po::options_description desc("Program options");
po::positional_options_description p;
po::variables_map vm;

int main(int argc, char* argv[]) {
    int port;
    std::string ip_address;
    bool is_server;

    try {
        desc.add_options()
        ("help,h", "produce help message")
        ("server,s", po::value<bool>(&is_server)->default_value(false)->implicit_value(true), "is it server")
        ("ip", po::value<std::string>(&ip_address)->required(), "ip address")
        ("port", po::value<int>(&port)->required(), "port");
        po::store(po::parse_command_line(argc, argv, desc), vm);
        if (vm.count("help")) {
            std::cout << "Usage: " << argv[0] << " <options>" << std::endl;
            std::cout << desc << std::endl;
            return 0;
        }
        po::notify(vm);
    }
    catch(std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    catch(...) {
        std::cerr << "Exception of unknown type!\n";
        return 1;
    }

    std::cout << ip_address << ":" << port << (is_server ? " server" : "") <<std::endl;
    fox::test_save();
    return 0;
}
