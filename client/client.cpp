


#include "../server_implementation/server.h"
#include "../server_implementation/templates.h"
#include <boost/serialization/vector.hpp>
#include <boost/program_options.hpp>
#include <iostream>
#include <random>
#include <chrono>
#include <stdio.h>

#define DEFAULT_PORT 8000
#define DEFAULT_HOST "localhost"

using namespace std;
using namespace boost::program_options;

int main(int argc, char *argv[]) {
    string hostname;
    unsigned short port;
    int request_length;
    string message;
    double a, b;

    options_description desc("Client options");
    desc.add_options()
            ("help,h", "help")
            ("port,p", value<unsigned short>(&port)->default_value(DEFAULT_PORT), "set port")
            ("location,l", value<string>(&hostname)->default_value(DEFAULT_HOST), "set host")
            ("message,m", value<string>(&message)->required(), "set message");
    variables_map args;

    try {
        parsed_options parsed = command_line_parser(argc, argv).options(desc).run();
        store(parsed, args);
        notify(args);
    } catch(std::exception& ex) {
        cerr << desc << endl;
        exit(EXIT_FAILURE);
    }


    vector<string> toconv{};

    for(int i = 0; i < message.length(); i++)
    {
        string tmp = "";
        tmp += message[i];
        toconv.push_back(tmp);
    }


    OutcomingData out(hostname, port);

    serializedWrite(out, toconv);

    vector<string> result = serializedRead<vector<string>>(out);

    for(int i=0; i < result.size(); i++)
        cout << result[i];
    cout << endl;
    return 0;
}
