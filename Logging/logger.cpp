
#include "logger.h"

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>


namespace logging = boost::log;
namespace keywords = boost::log::keywords;

void init_logging(int level)
{
    logging::register_simple_formatter_factory<logging::trivial::severity_level, char>("Severity");

    logging::add_file_log(
        keywords::file_name = "PATS_LOG_%N.log",
        keywords::format = "[%TimeStamp%] [%ThreadID%] [%Severity%] %Message%");

    logging::core::get()->set_filter(
        logging::trivial::severity >= level);

    logging::add_common_attributes();
}