# 添加测试源文件
set(TEST_SOURCES
    graphviz_wrapper_test.cpp
)

# 创建测试可执行文件
add_executable(test ${TEST_SOURCES})

# 连接主项目的代码
# target_link_libraries(test GraphvizWrapper)
