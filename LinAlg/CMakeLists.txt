# Mathematics/LinAlg/CMakeLists.txt
file(GLOB_RECURSE LinAlgSources LIST_DIRECTORIES false src/*.cpp)
add_library(LinAlg ${LinAlgSources})
target_include_directories(LinAlg PUBLIC include)

link_directories(../Utils)
target_link_libraries(LinAlg PUBLIC Utils)