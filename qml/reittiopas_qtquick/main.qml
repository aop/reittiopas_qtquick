import QtQuick 1.0
import com.nokia.symbian 1.1

PageStackWindow {
    id: window
    initialPage: MainPageReittiopas {tools: toolBarLayout}
    //initialPage: RouteList { tools: toolBarLayout}
    showStatusBar: true
    showToolBar: true
    platformSoftwareInputPanelEnabled: true

    Connections {
        target: reittiopas
        onQueryingRoutes: window.pageStack.push(Qt.resolvedUrl("RouteList.qml"))
        onQueryingShiftRoutes: window.pageStack.replace(Qt.resolvedUrl("RouteList.qml"))
    }

    ToolBarLayout {
        id: toolBarLayout
        ToolButton {
            flat: true
            iconSource: "toolbar-back"
            onClicked: window.pageStack.depth <= 1 ? Qt.quit() : window.pageStack.pop()
        }
        ToolButton { iconSource: "toolbar-view-menu" ; onClicked: infoView.open(); }
    }
    QueryDialog {
        id: infoView
        message: "Created by Oskari Pétas\n"
        titleText: "Reittiopas for Symbian v 1.3"
        rejectButtonText: "Close"
        icon: "qrc:/launch_icon_reittiopas.svg"
    }

}


