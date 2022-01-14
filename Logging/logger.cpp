
#include "logger.h"
#include "../Utility/Config_location.h"

namespace logging = boost::log;
namespace keywords = boost::log::keywords;

void init_logging(int level)
{
    logging::register_simple_formatter_factory<logging::trivial::severity_level, char>("Severity");

    std::string path;
    //path.append(LOG_DIR);
    path.append("PATS_LOG_%N.log");

    logging::add_file_log(
        keywords::file_name = path,
        keywords::format = "[%TimeStamp%] [%Severity%] [%LineID%] %Message%");

    logging::core::get()->set_filter(
        logging::trivial::severity >= level);

    logging::add_common_attributes();

    BOOST_LOG_TRIVIAL(info) << "Logging init";
}