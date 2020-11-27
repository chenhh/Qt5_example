cmake_minimum_required(VERSION 3.1.0)
project(age)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# enable the moc uic, and rcc extensions of Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# find corresponding modules of Qt
# the NO_DEFAULT_PATH argument will skip the system path
#find_package(Qt5Widgets REQUIRED NO_DEFAULT_PATH)

# use the Qt modules in the system path
#find_package(Qt5Widgets REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(SRCS age.cpp)
add_executable(age ${SRCS})
target_link_libraries(age Qt5::Widgets)