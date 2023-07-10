cmake_minimum_required(VERSION 3.5)

project(Teste LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CriarBD criar_bd.cpp)
add_executable(CriarTabela criar_tabela.cpp)
add_executable(InserirInfo inserir_info.cpp)
add_executable(Apresentar apresentar.cpp)

target_link_libraries(CriarBD sqlcipher)
target_link_libraries(CriarTabela sqlcipher)
target_link_libraries(InserirInfo sqlcipher)
target_link_libraries(Apresentar sqlcipher)

#install(TARGETS CriarBD
#    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
#)
