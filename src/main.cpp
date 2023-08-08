#include "SampleConfig.h"

#include <string>
#include <iostream>

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

using namespace std;

namespace logging = boost::log;
namespace keywords = boost::log::keywords;

void init_logging() {
    logging::register_simple_formatter_factory<logging::trivial::severity_level, char>("Severity");

    logging::add_file_log(
            keywords::file_name = "sample.log",
            keywords::auto_flush = true,
            keywords::format = "[%TimeStamp%] [%ThreadID%] [%Severity%] [%ProcessID%] [%LineID%] %Message%"
            );

//    logging::core::get()->set_filter
//        (
//         logging::trivial::severity >= logging::trivial::info
//        );

    logging::add_common_attributes();
}

int main (int argc, const char *argv[])
{
    init_logging();

//    BOOST_LOG_TRIVIAL(trace) << "This is a trace severity message";
//    BOOST_LOG_TRIVIAL(debug) << "This is a debug severity message";
//    BOOST_LOG_TRIVIAL(info) << "This is an informational severity message";
//    BOOST_LOG_TRIVIAL(warning) << "This is a warning severity message";
//    BOOST_LOG_TRIVIAL(error) << "This is an error severity message";
//    BOOST_LOG_TRIVIAL(fatal) << "and this is a fatal severity message";
    
    return 0;
}

