# Mathematics/Utils/CMakeLists.txt
file(GLOB_RECURSE UtilsSources LIST_DIRECTORIES false src/*.cpp)
add_library(Utils ${UtilsSources})
target_include_directories(Utils PUBLIC include)