cmake_minimum_required(VERSION 3.19)
project(DSchat LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Network)

qt_standard_project_setup()
set(CMAKE_AUTORCC ON)

qt_add_executable(DSchat
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    logindialog.cpp
    logindialog.h
    logindialog.ui
    app.rc
    rc.qrc
    registerdialog.h registerdialog.cpp registerdialog.ui
    global.h
    global.cpp
    singleton.h
    httpmgr.h httpmgr.cpp
    config.ini
    timerbtn.h timerbtn.cpp
    clickedlabel.h clickedlabel.cpp
    resetdialog.h resetdialog.cpp resetdialog.ui
    tcpmgr.h tcpmgr.cpp
    usermgr.h usermgr.cpp
    chatdialog.h chatdialog.cpp chatdialog.ui
    clickedbtn.h clickedbtn.cpp
    customizeedit.h customizeedit.cpp
    chatuserlist.h chatuserlist.cpp
    chatuserwid.h chatuserwid.cpp chatuserwid.ui
    listitembase.h listitembase.cpp
    loadingdlg.h loadingdlg.cpp loadingdlg.ui
    chatpage.h chatpage.cpp chatpage.ui
    chatview.h chatview.cpp
    chatitembase.h chatitembase.cpp
    bubbleframe.h bubbleframe.cpp
    textbubble.h textbubble.cpp
    picturebubble.h picturebubble.cpp
    messagetextedit.h messagetextedit.cpp
    statewidget.h statewidget.cpp
    searchlist.h searchlist.cpp
    userdata.h userdata.cpp
    adduseritem.h adduseritem.cpp adduseritem.ui
    findsuccessdlg.h findsuccessdlg.cpp findsuccessdlg.ui
    applyfriend.h applyfriend.cpp applyfriend.ui
    clickedoncelabel.h clickedoncelabel.cpp
    friendlabel.h friendlabel.cpp friendlabel.ui
    contactuserlist.h contactuserlist.cpp
    conuseritem.h conuseritem.cpp conuseritem.ui
    grouptipitem.h grouptipitem.cpp grouptipitem.ui
    applyfriendpage.h applyfriendpage.cpp applyfriendpage.ui
    applyfrienditem.h applyfrienditem.cpp applyfrienditem.ui
    applyfriendlist.h applyfriendlist.cpp
    findfaildlg.h findfaildlg.cpp findfaildlg.ui
    authenfriend.h authenfriend.cpp authenfriend.ui
    friendinfopage.cpp friendinfopage.h friendinfopage.ui



)

# 将 config.ini 拷贝到输出目录
add_custom_command(TARGET DSchat POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/config.ini"
        "$<TARGET_FILE_DIR:DSchat>/config.ini"
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/static"
        "$<TARGET_FILE_DIR:DSchat>/static"
)

target_include_directories(DSchat PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(DSchat
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Network
)

include(GNUInstallDirs)

install(TARGETS DSchat
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET DSchat
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})


