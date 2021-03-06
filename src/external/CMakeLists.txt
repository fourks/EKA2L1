add_library(miniz miniz/miniz.h miniz/miniz.c)
target_include_directories(miniz PUBLIC miniz)

add_subdirectory(freetype)
add_subdirectory(FRSML)
add_subdirectory(spdlog)
add_subdirectory(glfw)
add_subdirectory(glm)

set(YAML_CPP_BUILD_TESTS OFF CACHE BOOL "Enable testing" FORCE)
add_subdirectory(yaml-cpp)

add_subdirectory(googletest)

add_library(imgui imgui/imgui.h imgui/imgui.cpp
    imgui/imgui_demo.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_internal.h
    imgui/imconfig.h
    imgui/stb_rect_pack.h
    imgui/stb_textedit.h
    imgui/stb_truetype.h
)

if (MSVC)
    add_library(libdemangle
		libdemangle/include/cxxabi.h
		libcxxabi/src/cxa_demangle.cpp)

	target_include_directories(libdemangle PUBLIC libdemangle/include)
endif()

target_include_directories(imgui PUBLIC imgui)

add_library(glad glad/include/glad/glad.h glad/src/glad.c)
target_include_directories(glad PUBLIC glad/include)
add_library(unicorn INTERFACE)

#add_library(imgui_igs
#	Imgui-IGS-Snippets/ImguiWindowsFileIO.hpp
#	Imgui-IGS-Snippets/ImguiWindowsFileIO.cpp)

#target_link_libraries(imgui_igs PRIVATE imgui)
#target_include_directories(imgui_igs PUBLIC Imgui-IGS-Snippets)

add_library(simini INTERFACE)
target_include_directories(simini INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/simpleini")

if(APPLE)
	target_include_directories(unicorn INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/unicorn/macos/include")
	target_link_libraries(unicorn INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/unicorn/macos/lib/libunicorn.a")
elseif(WIN32)
	target_include_directories(unicorn INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/unicorn/windows/include")
	target_link_libraries(unicorn INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/unicorn/windows/unicorn.lib")
elseif(UNIX)
        target_include_directories(unicorn INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/unicorn/unix/include")
        target_link_libraries(unicorn INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/unicorn/unix/lib/libunicorn.a")
endif()

if (BUILD_TOOLS)
    find_package(LibClang)

    if (LIBCLANG_FOUND)
        add_library(libclang INTERFACE)
        target_link_libraries(libclang INTERFACE ${libclang_lib})
        target_include_directories(libclang INTERFACE ${libclang_include_dir})
    endif()
endif()

option(CAPSTONE_BUILD_SHARED "Build shared library" OFF)
option(CAPSTONE_BUILD_TESTS "Build tests" OFF)
option(CAPSTONE_ARM_SUPPORT "ARM support" ON)
option(CAPSTONE_ARM64_SUPPORT "ARM64 support" OFF)
option(CAPSTONE_MIPS_SUPPORT "MIPS support" OFF)
option(CAPSTONE_PPC_SUPPORT "PowerPC support" OFF)
option(CAPSTONE_SPARC_SUPPORT "Sparc support" OFF)
option(CAPSTONE_SYSZ_SUPPORT "SystemZ support" OFF)
option(CAPSTONE_XCORE_SUPPORT "XCore support" OFF)
option(CAPSTONE_X86_SUPPORT "x86 support" OFF)

add_subdirectory(capstone EXCLUDE_FROM_ALL)

set (capstone_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/capstone/include" PARENT_SCOPE)
set (GTEST_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/googletest/include" PARENT_SCOPE)
set (YAML_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/yaml-cpp/include" PARENT_SCOPE)
set (LIBCXXABI_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libcxxabi/include" PARENT_SCOPE)
set (FREETYPE_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/freetype/include" PARENT_SCOPE)
set (FRSML_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/FRSML/include" PARENT_SCOPE)
set (GLM_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/glm" PARENT_SCOPE)