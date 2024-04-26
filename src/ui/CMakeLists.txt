set(P2PChatUILibrary_SRS
    p2pchatwindow.cpp
    messenger.cpp
    messagelist.cpp
    pendingtransfers.cpp
    runningtransfers.cpp
    uimanager.cpp
    userlist.cpp
)

set(P2PChatUILibrary_HEADERS
    p2pchatwindow.h
    messenger.h
    messagelist.h
    pendingtransfers.h
    runningtransfers.h
    uimanager.h
    userlist.h
)

set(P2PChatUILibrary_RCC
    window.qrc
)

add_library(P2PChatUI SHARED ${P2PChatUILibrary_SRS} ${P2PChatUILibrary_RCC})
target_link_libraries(P2PChatUI Qt5::Core Qt5::Widgets Qt5::Quick Qt5::QuickControls2 P2PChat)
install(TARGETS P2PChatUI LIBRARY DESTINATION lib)
install(FILES ${P2PChatUILibrary_HEADERS} DESTINATION include/p2pchat/ui)
target_include_directories(P2PChatUI SYSTEM PUBLIC ${CMAKE_SOURCE_DIR}/src/ui)
