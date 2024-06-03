cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "5" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(async VERSION ${PROJECT_VESRION})

add_executable(async_cli main.cpp)
add_library(bulklib bulk.cpp)
add_library(async async.cpp)
add_library(assyncPrinterlib asyncPrinter.cpp)


set_target_properties(bulklib assyncPrinterlib async_cli async PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(assyncPrinterlib
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_include_directories(bulklib
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_include_directories(async
    PRIVATE "${CMAKE_BINARY_DIR}"
)

target_link_libraries(async_cli
async
)

if (MSVC)
    target_compile_options(async_cli PRIVATE
        /W4
    )
else ()
    target_compile_options(async_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(assyncPrinterlib PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(bulklib PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(async PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS async RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "NN")
include(CPack)
