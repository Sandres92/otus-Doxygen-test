cmake_minimum_required(VERSION 3.12)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(doxygen_test VERSION ${PROJECT_VESRION})

option(WITH_BOOST_TEST "Whether to build Boost test" ON)

configure_file(version.h.in version.h)

add_executable(doxygen_test_cli main.cpp my_class.h my_class.cpp)
add_library(lib_version lib.cpp)

set_target_properties(doxygen_test_cli lib_version PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(lib_version
    PRIVATE "${CMAKE_BINARY_DIR}"
)
 
target_link_libraries(doxygen_test_cli PRIVATE
    lib_version
) 

if(WITH_BOOST_TEST)
    find_package(Boost COMPONENTS unit_test_framework REQUIRED)
    add_executable(test_doxygen test_doxygen.cpp)

    set_target_properties(test_doxygen PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
    )

    set_target_properties(test_doxygen PROPERTIES
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
    )

    target_link_libraries(test_doxygen
        ${Boost_LIBRARIES}
        lib_version
    )
endif()

if (MSVC)
    target_compile_options(doxygen_test_cli PRIVATE
        /W4
    )
    target_compile_options(lib_version lib_sfinae PRIVATE
        /W4
    )

    if(WITH_BOOST_TEST)
        target_compile_options(test_doxygen PRIVATE
            /W4
        )
    endif()
else ()
    target_compile_options(doxygen_test_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(lib_version PRIVATE
        -Wall -Wextra -pedantic -Werror
    )

    if(WITH_BOOST_TEST)
        target_compile_options(test_doxygen PRIVATE
            -Wall -Wextra -pedantic -Werror
        )
    endif()
endif()

install(TARGETS doxygen_test_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

if(WITH_BOOST_TEST)
    enable_testing()
    add_test(test_doxygen test_doxygen)
endif()
