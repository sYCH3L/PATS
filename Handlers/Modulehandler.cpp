#include "Modulehandler.h"

Modulehandler::Modulehandler(std::list<Modules*> mods) : HandlerTemplate()
{
    this->m_list = mods;
}

void Modulehandler::InitRoutes(Rest::Router& router) 
{
    using namespace Rest;
    Routes::Get(router, "/versions", Routes::bind(&Modulehandler::DisplayAllModuleVersions, this));
}

void Modulehandler::DisplayAllModuleVersions(const Rest::Request &request, Http::ResponseWriter response) 
{
    std::ostringstream ss;
    for(auto it = m_list.begin(); it != m_list.end(); it++)
    {
        ss << (*it)->modulename << " " << (*it)->Version() << std::endl;
    }

    response.send(Http::Code::Ok, ss.str());
}