# QtVideoDisplayer-msg/CMakeLists.txt
cmake_minimum_required(VERSION 3.16)
project(QtVideoDisplayer-msg VERSION 1.0.0 LANGUAGES CXX)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 构建类型设置
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()

# 输出目录设置
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 编译选项
if (MSVC)
    add_compile_options(/W4 /WX)
else ()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif ()

# 包含子目录
add_subdirectory(src)

# 如果启用测试，包含测试目录
option(BUILD_TESTING "Build tests" ON)
if (BUILD_TESTING)
    enable_testing()
    add_subdirectory(test)
endif ()

# 安装配置
install(TARGETS messaging
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
)

install(DIRECTORY src/public/
        DESTINATION include/messaging
        FILES_MATCHING PATTERN "*.h"
)