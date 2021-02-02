cmake_minimum_required(VERSION 3.2)

project(ip_filt VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

configure_file(before_deploy.sh.in before_deploy.sh COPYONLY)
configure_file(gen_test_out.sh.in gen_test_out.sh COPYONLY)

add_executable(ip_filt main.cpp)

set_target_properties(ip_filt PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

##----------------------------------------------------------
## Handle warnings as errors
if (MSVC)
    target_compile_options(ip_filt PRIVATE
        /W4
    )
else ()
    target_compile_options(ip_filt PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()
##----------------------------------------------------------


install(TARGETS ip_filt RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_NAME "${AK_DEB_PKG_NAME}")

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)
