cmake_minimum_required(VERSION 3.22)

if(NOT "${METAMODULE_SDK_DIR}" STREQUAL "")
	message("METAMODULE_SDK_DIR set by CMake variable ${METAMODULE_SDK_DIR}")
elseif (DEFINED ENV{METAMODULE_SDK_DIR})
    set(METAMODULE_SDK_DIR "$ENV{METAMODULE_SDK_DIR}")
	message("METAMODULE_SDK_DIR set by environment variable ${METAMODULE_SDK_DIR}")
else()
    set(METAMODULE_SDK_DIR "${CMAKE_CURRENT_LIST_DIR}/../metamodule-plugin-sdk")
	message("METAMODULE_SDK_DIR set to default: ${METAMODULE_SDK_DIR}")
endif()

include(${METAMODULE_SDK_DIR}/plugin.cmake)

project(LydDMetaModulePlugin
    VERSION     0.1
    DESCRIPTION "LydD Modules plugin for MetaModule"
    LANGUAGES   C CXX ASM
)

add_library(LydDModules STATIC)

set(SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR})

target_sources(LydDModules
    PRIVATE
    ${SOURCE_DIR}/src/BasicFunctions.cpp
    ${SOURCE_DIR}/src/Concierge.cpp
    ${SOURCE_DIR}/src/Dobbs.cpp
    ${SOURCE_DIR}/src/Ledger.cpp
    ${SOURCE_DIR}/src/Mom-and-Dad.cpp
    ${SOURCE_DIR}/src/Onceler.cpp
    ${SOURCE_DIR}/src/Poppy-Fields.cpp
    ${SOURCE_DIR}/src/Shear.cpp
    ${SOURCE_DIR}/src/Simone.cpp
    ${SOURCE_DIR}/src/Torus.cpp
    ${SOURCE_DIR}/src/plugin.cpp
)

target_include_directories(LydDModules PRIVATE
    ${SOURCE_DIR}
)

target_compile_options(LydDModules
    PRIVATE
    -Wno-deprecated
    -Wno-deprecated-enum-float-conversion
)

set_property(TARGET LydDModules PROPERTY CXX_STANDARD 20)

if("${INSTALL_DIR}" STREQUAL "")
    set(INSTALL_DIR ${CMAKE_CURRENT_LIST_DIR}/metamodule-plugins)
endif()

create_plugin(
    SOURCE_LIB      LydDModules
    PLUGIN_NAME     LydD-Modules
    PLUGIN_JSON     ${SOURCE_DIR}/plugin.json
    SOURCE_ASSETS   ${SOURCE_DIR}/assets
    DESTINATION     ${INSTALL_DIR}
)
