cmake_minimum_required(VERSION 3.6)
project(ELMO_ECAT LANGUAGES C CXX)

# SOEM make install location: /mnt/data/maestro/core/drivers/EtherCAT/external/SOEM/build/install/cmake/soemConfig.cmake
set(soem_DIR "/home/steam/Projects/SOEM/build/install/cmake")
find_package(soem REQUIRED)

# Add TinyXML-2 directly

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

add_executable(torque_test torque_test.c)
target_link_libraries(torque_test soem)