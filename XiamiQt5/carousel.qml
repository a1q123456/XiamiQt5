import QtQuick 2.4
import QtGraphicalEffects 1.0

Item {
    Rectangle {
        id: root
        width: 800
        height:300
        property int albumSize;
        property int globalWidth;
        property int globalHeight;
        albumSize: 145;
        color: "transparent"
        signal sendClicked(int albumId);
        signal onEntered();
        signal onExited();

        Image {
            id:backgroundImage
            width:root.width
            height: root.height * 0.7
            clip: true
            fillMode: Image.PreserveAspectCrop
            verticalAlignment: Image.AlignVCenter
            source: pathView.currentItem.children[1].source
            anchors.horizontalCenter: parent.horizontalCenter
            onSourceChanged: {

            }

        }
        GaussianBlur {
            anchors.fill: backgroundImage
            source: backgroundImage
            radius: 32
            samples: 16
        }

        Rectangle {
            y: 0
            x: 0
            width: backgroundImage.width
            height: root.height * 0.7
            gradient: Gradient {
                GradientStop { position: 0.0; color: Qt.rgba(0,0,0, 0.0) }
                GradientStop { position: 1; color: Qt.rgba(255,255,255, 1.0) }
            }
        }

//         ListModel {
//             id:albumModel

//             ListElement { albumId: 1; picPath: "pics/340126.jpg" ; albumName: "aaa"     }
//             ListElement { albumId: 2; picPath: "pics/381815.jpg" ; albumName: "aaa"    }
//             ListElement { albumId: 3; picPath: "pics/485180.jpg" ; albumName: "aaa"    }
//             ListElement { albumId: 4; picPath: "pics/1861261471.jpg" ; albumName: "aaa"}
//             ListElement { albumId: 5; picPath: "pics/1669845108.jpg" ; albumName: "aaa"}
//             ListElement { albumId: 6; picPath: "pics/2081821708.jpg" ; albumName: "aaa"}
//             ListElement { albumId: 7; picPath: "pics/507984.jpg"     ; albumName: "aaa"}
//         }


         Component {
             id:albumViewModel
             Item {
                 property real scaleValue: PathView.scale
                 width:root.albumSize
                 height:root.albumSize
                 z:PathView.zIndex
                 Image {
                    id:albumCover
                    width:root.albumSize;
                    height:root.albumSize;
                    source: picPath
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
                                root.sendClicked(albumId)
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
                    Text {
                        text: albumName
                        font.family: "sans-serif"
                        font.pointSize: 8
                        color: "white"
                        wrapMode :Text.WordWrap
                        anchors {
                            bottom:albumCover.bottom;
                            bottomMargin:0
                        }
                        visible:(parent.parent.z==3)?true:false
                        //opacity:2 * (scaleValue-0.5)
                    }
                }
                Image {
                    id:mirror
                    width:root.albumSize
                    height:root.albumSize
                    source: picPath
                    anchors.horizontalCenter: parent.horizontalCenter
                    smooth:true
                    transform: Rotation {
                        origin.x:0
                        origin.y:root.albumSize;
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
            model: albumModel
            delegate: albumViewModel
            anchors.fill: parent

            pathItemCount: albumModel.count
            preferredHighlightBegin: 0.5
            preferredHighlightEnd: 0.5
            onFlickEnded: {
                // backgroundImage.source = pathView.currentItem.children[1].source
            }

            path: albumCaourselPath

            Keys.onLeftPressed:  decrementCurrentIndex()
            Keys.onRightPressed: incrementCurrentIndex()
        }

        Path {
            id: albumCaourselPath

            startX:root.width * 0.05 - root.albumSize / 2
            startY:root.height * 0.3
            PathAttribute {name: "scale"; value: 0.5}
            PathAttribute {name: "zIndex"; value: 1}

            PathLine{x: root.width * 0.5; y: root.height * 0.3}
            PathPercent {value: 0.50}
            PathAttribute {name: "scale"; value: 1}
            PathAttribute {name: "zIndex"; value: 3}

            PathLine{x:root.width * 0.95 + root.albumSize / 2; y:root.height * 0.3}
            PathPercent {value: 1.00}
            PathAttribute {name: "scale"; value: 0.5}
            PathAttribute {name: "zIndex"; value: 1}
        }
    }
}

