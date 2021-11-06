#include "Backend.h"

Backend::Backend() : Modules()
{
    this->modulename = std::string("Backend");

    this->m_address = Address(Ipv4::any(), 8080);

    this->m_endpoint = std::make_shared<Http::Endpoint>(m_address);

    auto opts = Http::Endpoint::options()
                    .threads(static_cast<int>(2));
    this->m_endpoint->init(opts);

    SetupRoutes();
}

Backend::Backend(Addr_Config conf, int port, int thread_count) : Modules(), m_port(port)
{
    this->modulename = std::string("Backend");

    if (Addr_Config::IPV4 == conf)
    {
        this->m_address = Address(Ipv4::any(), port);
    }
    else if (Addr_Config::IPV6 == conf)
    {
        this->m_address = Address(Ipv6::any(), port);
    }

    this->m_endpoint = std::make_shared<Http::Endpoint>(m_address);

    auto opts = Http::Endpoint::options()
                    .threads(static_cast<int>(thread_count));
    this->m_endpoint->init(opts);

    SetupRoutes();
}
Backend::Backend(Address adr, int thread_count) : Modules()
{
    this->modulename = std::string("Backend");
    
    this->m_port = adr.port();

    this->m_endpoint = std::make_shared<Http::Endpoint>(m_address);

    auto opts = Http::Endpoint::options()
                    .threads(static_cast<int>(thread_count));
    this->m_endpoint.get()->init(opts);

    SetupRoutes();
}
void Backend::Start()
{
    this->m_endpoint.get()->setHandler(this->m_router.handler());
    this->m_endpoint.get()->serveThreaded();
}

void Backend::SetupRoutes()
{
    using namespace Rest;
    Routes::Get(this->m_router, "/api/v1/version", Routes::bind(&Backend::GetAllversion, this));
}

void Backend::SetupExRoutes() {
    for(auto it = m_exthandlers.begin(); it != m_exthandlers.end(); it++)
    {
        (*it)->InitRoutes(m_router);
    }
}

void Backend::GetAllversion(const Rest::Request &request, Http::ResponseWriter response)
{
    std::ostringstream ss;
    ss << "Backend: " << this->Version() << "\n";
    response.send(Http::Code::Ok, ss.str());
}