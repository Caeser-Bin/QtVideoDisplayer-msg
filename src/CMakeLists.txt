# src/CMakeLists.txt
# 查找源文件
file(GLOB_RECURSE SRC_FILES "*.cpp")
file(GLOB_RECURSE HEADER_FILES "public/*.h")

# 创建静态库
add_library(messaging STATIC
        ${SRC_FILES}
)

# 设置包含目录
target_include_directories(messaging PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/public>
        $<INSTALL_INTERFACE:include/messaging>
)

# 设置编译器特性
target_compile_features(messaging PUBLIC cxx_std_17)

# 设置库属性
set_target_properties(messaging PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR}
        OUTPUT_NAME "messaging"
)

# 安装目标
install(TARGETS messaging
        EXPORT messaging-targets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
)

# 安装头文件
install(DIRECTORY public/
        DESTINATION include/messaging
        FILES_MATCHING PATTERN "*.h"
)

# 生成导出头文件（可选）
include(GenerateExportHeader)
generate_export_header(messaging
        BASE_NAME messaging
        EXPORT_FILE_NAME public/messaging_export.h
)