cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(PATS VERSION 0.1)

set(sources ${sources} 
    main.cpp
    Core/ATS.cpp
    Backend/Backend.cpp
    Handlers/Handlertemplate.cpp
    Handlers/Modulehandler.cpp
    Handlers/Testplanhandler.cpp
    Handlers/reshandler.cpp
    Handlers/testmoduleshandler.cpp
    Modules/Modules.cpp
    TestEngine/TestEngine.cpp
    TestModule/TestModule.cpp
    JobController/JobController.cpp
    Testplan/Testplan.cpp
    Testplan/TestItem.cpp
    Results/Resultshandler.cpp
    Logging/logger.cpp
    
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

ADD_DEFINITIONS(-DBOOST_ALL_DYN_LINK)

find_package(PkgConfig)
pkg_check_modules(Pistache REQUIRED IMPORTED_TARGET libpistache)
find_package(Boost 1.71 REQUIRED COMPONENTS log log_setup program_options)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} PkgConfig::Pistache ${CMAKE_DL_LIBS} Boost::log) 