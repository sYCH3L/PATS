#ifndef BACKEND_H
#define BACKEND_H

/* 
    Backend Module 
    Holds generic endpoints includes additional modules endpoints from different sources and initializes them
*/

#include <algorithm>
#include <string>
#include <sstream>
#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>

#include <vector>

#include "../Utility/Utility.h"
#include "../Handlers/Handlertemplate.h"
#include "Version.h"

#include "../Modules/Modules.h"

using namespace Pistache;

class Backend : public Modules
{
public:
    explicit Backend();                                    // Null config constructor
    Backend(Addr_Config conf, int port, int thread_count); // Backend init with addr config, binds to either ipv4 any or ipv6 any and specified port
    Backend(Address adr, int thread_count);                // Backend with address object and port object
    void Start();

    std::string Version()
    {
        std::ostringstream verstr;
        verstr << BACKEND_MAJOR << "." << BACKEND_MINOR << "." << BACKEND_PATCH;
        return verstr.str();
    }

    void AppendExthandlers(HandlerTemplate *handler)
    {
        m_exthandlers.push_back(handler);
    }
    void SetupExRoutes();

private:
    void GetAllversion(const Rest::Request &request, Http::ResponseWriter response);
    void SetupRoutes();

    Address m_address;
    Port m_port;
    std::shared_ptr<Http::Endpoint> m_endpoint;
    Rest::Router m_router;
    std::vector<HandlerTemplate *> m_exthandlers;
};

#endif