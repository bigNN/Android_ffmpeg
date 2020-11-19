
cmake_minimum_required(VERSION 3.10.2)
# 声明并命名项目.
#project("ffmpeg")
#批量add源文件
file(GLOB allcpp *.cpp *.h)

# 创建并命名一个库，将其设置为STATIC或SHARED,并提供其源代码的相对路径
# 您可以定义多个库，CMake会为您构建它们，Gradle会自动将共享库与APK打包在一起
add_library( # 设置库的名称
        bigNN-player
        # 将库设置为共享库
        SHARED
        # 提供源文件的相对路径
        ${allcpp}
        )

# 搜索指定的预构建库并将路径存储为变量。由于默认情况下CMake在搜索路径中包括系统库，因此您只需要指定要添加的公共NDK库的名称即可。在完成构建之前，CMake会验证该库是否存在
find_library( # 设置路径变量的名称
        log-lib
        # 指定您要CMake定位的NDK库的名称
        log)

#ffmpeg头文件倒入
include_directories(${CMAKE_SOURCE_DIR}/ffmpeg/include)

message("fmpeg头文件倒入 :${CMAKE_SOURCE_DIR}/ffmpeg/include")

#ffmpeg库文件导入
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_SOURCE_DIR}/ffmpeg/libs/${CMAKE_ANDROID_ARCH_ABI}")

message("ffmpeg库文件导入 : ${CMAKE_SOURCE_DIR}/ffmpeg/libs/${CMAKE_ANDROID_ARCH_ABI}")


#rtmp库文件导入
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_SOURCE_DIR}/rtmp/libs/${CMAKE_ANDROID_ARCH_ABI}")


# 指定库CMake应该链接到您的目标库。您可以＃链接多个库，例如您在此构建脚本中定义的库，预构建的第三方库或系统库
target_link_libraries(
        # 指定目标库
        bigNN-player
        # 将目标库链接到NDK中包含的日志库
        ${log-lib}
        #忽略顺序
        -Wl,--start-group
        avcodec avfilter avformat avutil swresample swscale
        -Wl,--end-group
        z
)