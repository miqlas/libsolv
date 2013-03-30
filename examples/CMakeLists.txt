SET (solv_SRCS solv.c)

IF (ENABLE_HAIKU)
SET (solv_SRCS ${solv_SRCS} solv_haiku.cpp)
ENDIF (ENABLE_HAIKU)

ADD_EXECUTABLE (solv ${solv_SRCS})
TARGET_LINK_LIBRARIES (solv libsolvext libsolv ${SYSTEM_LIBRARIES})

INSTALL(TARGETS
    solv
    DESTINATION ${BIN_INSTALL_DIR})
