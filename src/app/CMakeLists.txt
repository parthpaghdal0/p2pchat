project(p2pchat)
add_executable(p2pchat main.cpp)
target_link_libraries(p2pchat Qt5::Widgets P2PChat P2PChatUI)
install(TARGETS p2pchat DESTINATION bin)
