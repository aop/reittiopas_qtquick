function getImageForVehicle(type) {
    var source;
    if (type === "BUS"){
        source = "qrc:/img/bus.png"
    }
    if (type == "walk"){
        source = "qrc:/img/walk.jpg"
    }
    if (type == "TRAIN"){
        source = "qrc:/img/train.png"
    }
    if (type == "TRAM"){
        source = "qrc:/img/tram.png"
    }
    if (type == "METRO"){
        source = "qrc:/img/metro.png"
    }
    if (type == "FERRY"){
        source = "qrc:/img/ferry.png"
    }
    if (type == "NIGHTBUS"){
        source = "qrc:/img/nightbus.png"
    }

    return source;
}

function getColorForVehicle(type){
    var source;
    if (type === "BUS"){
        source = "blue"
    }
    if (type == "walk"){
        source = "black"
    }
    if (type == "TRAIN"){
        source = "green"
    }
    if (type == "TRAM"){
        source = "darkgreen"
    }
    if (type == "METRO"){
        source = "orange"
    }
    if (type == "FERRY"){
        source = "navyblue"
    }
    if (type == "NIGHTBUS"){
        source = "blue"
    }

    return source;
}
