#ifndef RESHANDLER_H
#define RESHANDLER_H

#include <memory>
#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>

#include "Handlertemplate.h"

class ResHandler : public HandlerTemplate
{
public:
    ResHandler();
    void InitRoutes(Rest::Router &router);

private:
    void AllResults(const Rest::Request &request, Http::ResponseWriter response);
    void ResultById(const Rest::Request &request, Http::ResponseWriter response);
};

#endif