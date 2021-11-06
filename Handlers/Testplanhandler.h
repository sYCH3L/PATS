#ifndef TESTPLANHANDLER_H
#define TESTPLANHANDLER_H

#include <memory>
#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>


#include "Handlertemplate.h"
#include "../JobController/JobController.h"

using namespace Pistache;

class TestplanHandler : public HandlerTemplate
{
public:
    TestplanHandler(std::shared_ptr<JobController> ptr);
    void InitRoutes(Rest::Router& router);
private:
    void NewTestplan(const Rest::Request &request, Http::ResponseWriter response);
    void AllTestplans(const Rest::Request &request, Http::ResponseWriter response);
    void Deletetestplan(const Rest::Request &request, Http::ResponseWriter response);
    void Gettestplan(const Rest::Request &request, Http::ResponseWriter response);
    std::shared_ptr<JobController> m_jobcontroller;
};

#endif