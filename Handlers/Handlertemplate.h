#ifndef HANDLERTEMPLATE_H
#define HANDLERTEMPLATE_H

#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>

using namespace Pistache;

class HandlerTemplate
{
public:
    HandlerTemplate();
    virtual void InitRoutes(Rest::Router& router);
};


#endif