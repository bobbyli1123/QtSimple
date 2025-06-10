#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile styleFile(":/style/style.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        QString styleSheet = QString(styleFile.readAll());
        a.setStyleSheet(styleSheet);
    } else {
        qWarning() << "Failed to read style sheet!" << styleFile.errorString();
    }
    MainWindow w;
    w.show();
    return a.exec();
}
