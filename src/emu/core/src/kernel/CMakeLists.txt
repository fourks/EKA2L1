add_library(corekernel
	${CORE_INCLUDE_DIR}/kernel/thread.h
	${CORE_INCLUDE_DIR}/kernel/mutex.h
    ${CORE_INCLUDE_DIR}/kernel/kernel_obj.h
    ${CORE_INCLUDE_DIR}/core_kernel.h
    ${CORE_INCLUDE_DIR}/kernel/scheduler.h
    ${CORE_INCLUDE_DIR}/kernel/wait_obj.h
    ${CORE_INCLUDE_DIR}/kernel/chunk.h
    ${CORE_INCLUDE_DIR}/kernel/sema.h
    ${CORE_INCLUDE_DIR}/kernel/timer.h
    scheduler.cpp
    thread.cpp
    mutex.cpp
    kernel_obj.cpp
	wait_obj.cpp
    chunk.cpp
    sema.cpp
    timer.cpp
    ../core_kernel.cpp)

target_include_directories(corekernel PUBLIC ${CORE_INCLUDE_DIR})

target_link_libraries(corekernel PUBLIC common)
target_link_libraries(corekernel PRIVATE coremem coretiming arm hle coreloader)
