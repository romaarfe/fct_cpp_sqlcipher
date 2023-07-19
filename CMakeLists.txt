cmake_minimum_required(VERSION 3.5)

project(Teste LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
    criar_bd.cpp
    criar_tabela.cpp
    inserir_info.cpp
    apresentar.cpp
    main.cpp
)

add_executable(PROJECT_SOURCES
    ${PROJECT_SOURCES})

#install(TARGETS CriarBD
#    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
#)
