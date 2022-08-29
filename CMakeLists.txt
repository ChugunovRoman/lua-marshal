project(xrMarshal)

set(SRC_FILES
    "lmarshal.h"
    "lmarshal.c"
)

group_sources(SRC_FILES)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${LUA_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}/Externals
    ${CMAKE_SOURCE_DIR}/Externals/luabind
    ${SDL2_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME} STATIC ${SRC_FILES})

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    xrLuabind
    ${LIBS}
    ${LUA_LIBRARIES}
    ${SDL2_LIBRARIES}
)

target_compile_definitions(${PROJECT_NAME}
    PRIVATE
    -DLUAMARSHAL_EXPORTS
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    PREFIX ""
)

if(NOT STATIC_BUILD)
    install(TARGETS ${PROJECT_NAME} LIBRARY
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
    )
endif()
