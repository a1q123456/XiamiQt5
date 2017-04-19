import QtQuick 2.4
import QtGraphicalEffects 1.0
import QtMultimedia 5.6
import QtQuick.Layouts 1.3

ColumnLayout {
    spacing: 0
    anchors.fill: parent;
    id: qmlroot
    signal collectionClicked(int collectionId);
    signal albumClicked(int albumId);

    Rectangle {
        id: root
        Layout.alignment: Qt.AlignTop

        Layout.fillWidth: true
        Layout.preferredHeight: parent.height * 0.6
        property int collectionSize;
        property int globalWidth;
        property int globalHeight;
        property int albumSize: 150
        collectionSize: 220;
        color: "transparent"

        Image {
            id:backgroundImage
            anchors.fill: parent
            clip: true
            fillMode: Image.PreserveAspectCrop
            verticalAlignment: Image.AlignVCenter
            source: pathView.currentItem.children[1].source
            anchors.horizontalCenter: parent.horizontalCenter

            onSourceChanged: {

            }

        }
        GaussianBlur {
            id: backgroundBlur
            anchors.fill: backgroundImage
            source: backgroundImage
            radius: 32
            samples: 16
        }


        Rectangle {
            y: 0
            x: 0
            width: backgroundImage.width
            height: root.height
            gradient: Gradient {
                GradientStop { position: 0.0; color: Qt.rgba(0,0,0, 0.0) }
                GradientStop { position: 1; color: Qt.rgba(255,255,255, 1.0) }
            }
        }

         Component {
             id:collectionViewModel
             Item {
                 property real scaleValue: PathView.scale
                 width:root.collectionSize
                 height:root.collectionSize
                 z:PathView.zIndex

                 Image {
                    id:collectionCover
                    width:root.collectionSize;
                    height:root.collectionSize;
                    source: picPath
                    smooth: true
                    anchors.horizontalCenter: parent.horizontalCenter


                    Image {
                        id:playButton
                        width:70
                        height:70
                        source: ""
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter  : parent.verticalCenter
                        smooth:true
                        MouseArea {
                            anchors.fill: parent
                            hoverEnabled: true
                            onClicked: {
                                qmlroot.collectionClicked(collectionId)
                            }

                            onPressed:{
                                parent.source = "img/large_cover_play_down.png"
                            }
                            onEntered:{
                                parent.source = "img/large_cover_play_hover.png"
                            }
                            onReleased:{
                                parent.source = "img/large_cover_play_normal.png"
                            }
                            onExited:{
                                parent.source = ""
                            }
                        }
                        visible:(parent.parent.z==3)?true:false
                    }

                    LinearGradient {
                        anchors.fill: collectionCover
                        start: Qt.point(0, 0)
                        end: Qt.point(0, 300)
                        gradient: Gradient {
                            GradientStop { position: 0.6; color: Qt.rgba(0,0,0, 0.0) }
                            GradientStop { position: 1.0; color: "black" }
                        }
                    }
                    Text {
                        id: collectionNameText
                        text: collectionName
                        font.family: "sans-serif"
                        font.pointSize: 13
                        font.bold: true
                        color: "white"
                        wrapMode :Text.WordWrap
                        anchors {
                            bottom:collectionCover.bottom;
                            bottomMargin:0
                            left: collectionCover.left;
                            right: collectionCover.right;

                        }
                        visible:(parent.parent.z==3)?true:false
                        //opacity:2 * (scaleValue-0.5)
                    }
                }

                Image {
                    id:mirror
                    width:root.collectionSize
                    height:root.collectionSize
                    source: picPath
                    anchors.horizontalCenter: parent.horizontalCenter
                    smooth:true
                    transform: Rotation {
                        origin.x:0
                        origin.y:root.collectionSize;
                        axis{
                            x:1
                            y:0
                            z:0
                        }
                        angle:180
                    }
                }
                Rectangle {
                    y: mirror.height;
                    x: 0;
                    width: mirror.width
                    height: mirror.height
                    gradient: Gradient {
                        GradientStop { position: 0.0; color: Qt.rgba(255,255,255, 0.5) }
                        GradientStop { position: 0.2; color: Qt.rgba(255,255,255, 1.0) }
                    }
                }

                transform: [
                    Scale {
                        xScale:scaleValue
                        yScale:scaleValue
                        origin.x: 340 / 2;
                        origin.y: 260 / 2
                    }
                ]
            }
        }


        PathView {
            id:pathView
            focus:true
            model: collectionModel
            delegate: collectionViewModel
            anchors.fill: parent

            pathItemCount: collectionModel.count
            preferredHighlightBegin: 0.5
            preferredHighlightEnd: 0.5
            onFlickEnded: {
                // backgroundImage.source = pathView.currentItem.children[1].source
            }

            path: collectionCaourselPath

            Keys.onLeftPressed:  decrementCurrentIndex()
            Keys.onRightPressed: incrementCurrentIndex()
        }

        Path {
            id: collectionCaourselPath

            startX:root.width * 0.05 - root.collectionSize / 2
            startY:root.height * 0.5
            PathAttribute {name: "scale"; value: 0.5}
            PathAttribute {name: "zIndex"; value: 1}

            PathLine{x: root.width * 0.5; y: root.height * 0.5}
            PathPercent {value: 0.50}
            PathAttribute {name: "scale"; value: 1}
            PathAttribute {name: "zIndex"; value: 3}

            PathLine{x:root.width * 0.95 + root.collectionSize / 2; y:root.height * 0.5}
            PathPercent {value: 1.00}
            PathAttribute {name: "scale"; value: 0.5}
            PathAttribute {name: "zIndex"; value: 1}
        }
    }

    ListModel {
        id: albumModel
        ListElement {picPath: "https://www.baidu.com/img/bd_logo1.png"; albumId: 0; albumName: "a1aaa"}
        ListElement {picPath: "https://www.baidu.com/img/bd_logo1.png"; albumId: 1; albumName: "ddafdsf"}
        ListElement {picPath: "https://www.baidu.com/img/bd_logo1.png"; albumId: 2; albumName: "adsfad"}
        ListElement {picPath: "https://www.baidu.com/img/bd_logo1.png"; albumId: 3; albumName: "123123"}
        ListElement {picPath: "https://www.baidu.com/img/bd_logo1.png"; albumId: 4; albumName: "aa123123aa"}
        ListElement {picPath: "https://www.baidu.com/img/bd_logo1.png"; albumId: 5; albumName: "aaa123123123123a"}
        ListElement {picPath: "https://www.baidu.com/img/bd_logo1.png"; albumId: 6; albumName: "aaa123123123123a"}
        ListElement {picPath: "https://www.baidu.com/img/bd_logo1.png"; albumId: 7; albumName: "aaa123123123123a"}
    }

    Component {
        id: albumViewModel

        Rectangle {
            id: wrapper
            width: 180
            height: contactInfo.height
            color: "transparent"
            Image {
                id: albumImage
                source: picPath
                width: root.albumSize
                height: root.albumSize
                smooth:true
                Image {
                    source: ""
                    width:70
                    height:70
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter  : parent.verticalCenter
                    MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true
                        onClicked: {
                            qmlroot.albumClicked(albumId)
                        }

                        onPressed:{
                            parent.source = "img/large_cover_play_down.png"
                        }
                        onEntered:{
                            parent.source = "img/large_cover_play_hover.png"
                        }
                        onReleased:{
                            parent.source = "img/large_cover_play_normal.png"
                        }
                        onExited:{
                            parent.source = ""
                        }
                    }
                }


            }
            Text {
                anchors.top: albumImage.bottom
                id: contactInfo
                text: albumName
                color: "black"
            }
        }
    }
    /*
    Rectangle {
        Layout.alignment: Qt.AlignBottom
        Layout.fillHeight: true
        Layout.fillWidth: true
        ListView {
            anchors.fill: parent
            orientation: ListView.Horizontal
            id: albumView
            model: albumModel
            delegate: albumViewModel
            highlightFollowsCurrentItem: false
            focus: true

        }
    }
    */
}

