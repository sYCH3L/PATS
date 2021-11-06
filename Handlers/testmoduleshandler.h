#ifndef TESTMODHNDLR_H
#define TESTMODHNDLR_H

#include <memory>
#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>

#include "Handlertemplate.h"

class TestModuleHandler : public HandlerTemplate
{
public:
    TestModuleHandler();
    void InitRoutes(Rest::Router &router);

private:
    void AllModules(const Rest::Request &request, Http::ResponseWriter response);
    void ModulesById(const Rest::Request &request, Http::ResponseWriter response);
};

#endif