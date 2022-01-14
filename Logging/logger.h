#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>


#define ATS_LOG(loglevel) BOOST_LOG_TRIVIAL(loglevel) << "[" << this->modulename << "] "

void init_logging(int level);

#endif