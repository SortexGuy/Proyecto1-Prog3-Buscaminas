cmake_minimum_required(VERSION 3.11)

# --- Fetch FTXUI --------------------------------------------------------------
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)
set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)

FetchContent_Declare(
  ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v4.0.0
  GIT_PROGRESS TRUE)

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

# ------------------------------------------------------------------------------

project(
  buscaminas-tui
  LANGUAGES CXX
  VERSION 1.0.0)

add_executable(buscaminas-tui src/main.cpp)
target_include_directories(buscaminas-tui PRIVATE src)

target_link_libraries(
  buscaminas-tui
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component # Not needed for this example.
)

# if (EMSCRIPTEN) string(APPEND CMAKE_CXX_FLAGS " -s USE_PTHREADS")
# string(APPEND CMAKE_EXE_LINKER_FLAGS " -s ASYNCIFY") string(APPEND
# CMAKE_EXE_LINKER_FLAGS " -s PROXY_TO_PTHREAD")
#
# foreach(file "index.html" "run_webassembly.py") configure_file("src/${file}"
# ${file}) endforeach(file) endif()
