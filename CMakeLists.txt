cmake_minimum_required(VERSION 3.14)
project(lab_9_2_1 CXX)
set(CMAKE_CXX_STANDARD 14)

# --- основна програма ---
# Головний файл може називатися 9.2.cpp (як у вашому проєкті) або lab_9_2_1.cpp
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/9.2.cpp)
    set(MAIN_SRC 9.2.cpp)
elseif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/lab_9_2_1.cpp)
    set(MAIN_SRC lab_9_2_1.cpp)
endif()

if(MAIN_SRC)
    add_executable(lab_9_2_1 ${MAIN_SRC} macros.h)
    target_include_directories(lab_9_2_1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    # інша гілка, наприклад z = 5:
    # target_compile_definitions(lab_9_2_1 PRIVATE Z=5)
endif()

# --- Google Test (завантажується автоматично) ---
include(FetchContent)
FetchContent_Declare(googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)   # для Visual Studio
FetchContent_MakeAvailable(googletest)
enable_testing()
include(GoogleTest)

# --- unit-тести: macros.h + tests_9_2_1.cpp (головний файл з main не входить) ---
add_executable(tests_9_2_1 tests_9_2_1.cpp macros.h)
target_include_directories(tests_9_2_1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tests_9_2_1 GTest::gtest_main)
gtest_discover_tests(tests_9_2_1)