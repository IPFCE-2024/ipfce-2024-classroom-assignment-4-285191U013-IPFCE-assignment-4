cmake_minimum_required(VERSION 3.16)
project(assignment-4 VERSION 0.1.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 17)

Include(FetchContent)

FetchContent_Declare(
		Catch2
		GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  		GIT_TAG        v3.6.0 # Newest version as of 12-08-2024
)

FetchContent_MakeAvailable(Catch2)

include_directories(include)

add_executable(loanRepayment src/loanRepayment.c)
target_link_libraries(loanRepayment m)


set (libs average counter longest_seq reverse get_min)

add_library(average STATIC src/average.c)
add_library(counter STATIC src/counter.c)
add_library(longest_seq STATIC src/longest_seq.c)
add_library(reverse STATIC src/reverse.c)
add_library(get_min STATIC src/get_min.c)

foreach(lib ${libs})
	# target_link_libraries(${lib} m)
	target_compile_definitions(${lib} PRIVATE -DTEST)
endforeach()

add_executable(unit-tests tests/tests.cpp)
target_link_libraries(unit-tests average counter longest_seq reverse get_min)
target_link_libraries(unit-tests Catch2::Catch2WithMain)
target_compile_definitions(unit-tests PRIVATE -DTEST)
