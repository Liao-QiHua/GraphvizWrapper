# 设置源文件
set(SOURCE_FILES
    graphviz_wrapper.cc
)

# 创建主可执行文件
add_executable(GraphvizWrapper ${SOURCE_FILES})

# 添加链接库
# target_link_libraries(GraphvizWrapper SomeLibrary)
