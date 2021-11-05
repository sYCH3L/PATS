#ifndef MODULEHANDLER_H
#define MODULHANDLER_H

#include "Handlertemplate.h"
#include "../Modules/Modules.h"

#include <list>
#include <sstream>

using namespace Pistache;

class Modulehandler : public HandlerTemplate
{
public:
    explicit Modulehandler(std::list<Modules*> mods);
    void InitRoutes(Rest::Router& router);
    void DisplayAllModuleVersions(const Rest::Request &request, Http::ResponseWriter response);
private:
    std::list<Modules*> m_list;
};


#endif