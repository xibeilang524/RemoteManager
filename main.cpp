#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "XVideo.h"
#include "screenvideo.h"
#include "replaytimeline.h"
#include "xvideoreplay.h"

#include <qqmlcontext.h>
#include "warnmodel.h"
#include "devicemodel.h"
#include "application.h"
#include "facedatamodel.h"


#include "warndps.h"
int main(int argc, char *argv[])
{

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    //    if(!app.lock())
    //         return -42;
    QFont font("Microsoft Yahei");
    app.setFont(font);
    app.setOrganizationName("GaoZhi"); //1
    app.setOrganizationDomain("gaozhi.com"); //2
    app.setApplicationName("remotemanager"); //3

    QQmlApplicationEngine engine;
    //    QmlLanguage qmlLanguage(app, engine);
    //    engine.rootContext()->setContextProperty("qmlLanguage", &qmlLanguage);
    //    QTranslator translator;
    //    translator.load("en_US.qm");
    //    app.installTranslator(&translator);

//    WarnDps warndps;
//    warndps.initDps();

    qmlRegisterType<XVideo>("XVideo", 1, 0, "XVideo");
    qmlRegisterType<ScreenVideo>("ScreenVideo", 1, 0, "ScreenVideo");
    qmlRegisterType<ReplayTimeline>("TimeLine", 1, 0, "TimeLine");
    qmlRegisterType<XVideoReplay>("XVideoReplay", 1, 0, "XVideoReplay");


    qmlRegisterType<WarnModel>("WarnModel", 1, 0, "WarnModel");
    qmlRegisterType<DeviceModel>("DeviceModel", 1, 0, "DeviceModel");
    qmlRegisterType<FaceDateModel>("FaceDateModel", 1, 0, "FaceDateModel");

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();
}
