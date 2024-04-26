set(P2PChatLibrary_SRS
    interfaces/iclient.cpp
    interfaces/iclientmanager.cpp
    interfaces/iconnection.cpp
    interfaces/icontrolcenter.cpp
    interfaces/icryptengine.cpp
    interfaces/iserver.cpp
    interfaces/itransfer.cpp
    interfaces/itransfermanager.cpp
    interfaces/iusersettings.cpp
    
    client.cpp
    clientinformation.cpp
    clientmanager.cpp
    clientthreadmanager.cpp
    connection.cpp
    controlcenter.cpp
    controlcenter_p.cpp
    crypt.cpp
    cryptengine.cpp
    debug.cpp
    debugtransfer.cpp
    file.cpp
    message.cpp
    messageinformation.cpp
    messageserver.cpp
    rsapair.cpp
    securetunnel.cpp
    transfer.cpp
    transfermanager.cpp
    transferthreadmanager.cpp
    transferserver.cpp
    usersettings.cpp
)

set(P2PChatLibrary_Interfaces_HEADERS
    interfaces/iclient.h
    interfaces/iclientmanager.h
    interfaces/iconnection.h
    interfaces/icontrolcenter.h
    interfaces/icryptengine.h
    interfaces/iserver.h
    interfaces/itransfer.h
    interfaces/itransfermanager.h
    interfaces/iusersettings.h
)

set(P2PChatLibrary_HEADERS
    client.h
    clientinformation.h
    clientmanager.h
    clientthreadmanager.h
    connection.h
    controlcenter.h
    controlcenter_p.h
    crypt.h
    cryptengine.h
    debug.h
    debugtransfer.h
    file.h
    message.h
    messageinformation.h
    messageserver.h
    rsapair.h
    securetunnel.h
    transfer.h
    transfermanager.h
    transferthreadmanager.h
    transferserver.h
    usersettings.h
)

add_library(P2PChat SHARED ${P2PChatLibrary_SRS})
target_link_libraries(P2PChat Qt5::Core Qt5::Network ssl crypto)
install(TARGETS P2PChat LIBRARY DESTINATION lib)
install(FILES ${P2PChatLibrary_Interfaces_HEADERS} DESTINATION include/p2pchat/interfaces)
install(FILES ${P2PChatLibrary_HEADERS} DESTINATION include/p2pchat)
target_include_directories(P2PChat SYSTEM PUBLIC ${CMAKE_SOURCE_DIR}/src/lib)
