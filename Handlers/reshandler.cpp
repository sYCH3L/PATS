#include "reshandler.h"

ResHandler::ResHandler() : HandlerTemplate() {

}
void ResHandler::InitRoutes(Rest::Router &router)
{
    using namespace Rest;
    Routes::Get(router, "/results", Routes::bind(&ResHandler::AllResults,this));
    Routes::Get(router, "/results/:id", Routes::bind(&ResHandler::ResultById, this));

}

void ResHandler::AllResults(const Rest::Request &request, Http::ResponseWriter response)
{
    std::cout << "All results" << std::endl;
    response.send(Http::Code::Ok, std::string("{ message: \"ok\" }"));
}
void ResHandler::ResultById(const Rest::Request &request, Http::ResponseWriter response)
{
    std::cout << "Result by id" << std::endl;
    response.send(Http::Code::Ok, std::string("{ message: \"ok\" }"));
}