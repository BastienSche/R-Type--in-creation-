cmake_minimum_required(VERSION 3.15)
include(FetchContent)
project(R-Type-client)
project(R-Type-server)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(SOURCE_FILES_CLI Client/Src/main.cpp Client/Src/Systems/BulletControlSystem.cpp Client/Src/Systems/MonsterControlSystem.cpp Client/Src/Systems/PlayerControlSystem.cpp Client/Src/Graphics.cpp Client/Src/WindowManaging.cpp Client/Src/Game.cpp Client/Src/Menu.cpp Client/Src/Assets.cpp Client/Src/Button.cpp)
set(SOURCE_FILES_SERV Server/main.cpp)
#Server/tcp_connection.cpp Server/tcp_server.cpp Server/udp_server.cpp Server/Utils.cpp

set(Headers Client/Src/Core/*.h Client/Src/Systems/*.h Client/Src/Systems/*.hpp Client/Src/*.hpp Client/Includes/*.h)

# option(ASIO_USE_CPM "Download Asio with CPM instead of FetchContent" OFF)
# option(
#   ASIO_CPM_FETCHCONTENT_COMPAT
#   "Should asio be declared with FetchContent functions to be compatible. This doesn't not allow CPM cache to work."
#   ON
# )
option(ASIO_USE_CPM "Download Asio with CPM instead of FetchContent" OFF)
option(
  ASIO_CPM_FETCHCONTENT_COMPAT
  "Should asio be declared with FetchContent functions to be compatible. This doesn't not allow CPM cache to work."
  ON
)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

include(FetchContent)
FetchContent_Declare(
  asiocmake
  GIT_REPOSITORY "https://github.com/OlivierLDff/asio.cmake"
  GIT_TAG        "main"
)
FetchContent_MakeAvailable(asiocmake)
# include(FetchContent)
# FetchContent_Declare(
#   asiocmake
#   GIT_REPOSITORY "https://github.com/OlivierLDff/asio.cmake"
#   GIT_TAG        "main"
# )
# FetchContent_MakeAvailable(asiocmake)

add_executable(R-Type-client ${SOURCE_FILES_CLI})
add_executable(R-Type-server ${SOURCE_FILES_SERV})

# include_directories(/usr/local/include)

#find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
#include_directories(${SFML_INCLUDE_DIRS})

# The minimum version of CMake required
# The project name
# The C++ standard version. Can be 98 11 14 or 17
target_link_libraries(R-Type-client PRIVATE sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
target_link_libraries(R-Type-server PRIVATE sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
target_link_libraries(R-Type-client PRIVATE asio::asio)
target_link_libraries(R-Type-server PRIVATE asio::asio)
target_compile_features(R-Type-client PRIVATE cxx_std_17)
target_compile_features(R-Type-server PRIVATE cxx_std_17)