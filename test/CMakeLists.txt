# test/CMakeLists.txt
# 只有启用测试时才构建
if(BUILD_TESTING)
    # 创建测试可执行文件
    add_executable(messaging-test
            main.cpp
            # 可以在这里添加更多测试文件
    )

    # 链接主库
    target_link_libraries(messaging-test messaging)

    # 设置包含目录
    target_include_directories(messaging-test PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/../src/public
    )

    # 设置输出目录
    set_target_properties(messaging-test PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test
    )

    # 添加测试
    add_test(NAME messaging-test
            COMMAND messaging-test
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/test
    )

    # 安装测试程序（可选）
    install(TARGETS messaging-test
            RUNTIME DESTINATION test
    )
endif()