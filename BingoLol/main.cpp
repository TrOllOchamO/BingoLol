#include <QApplication>
#include <QPushButton>
#include <QFile>
#include <QIODevice>
#include <QMessageBox>
#include <QResource>

#include "BingoLolWindows.h"
#include "UsefullFunc.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    
    app.setWindowIcon(QIcon(":/resources/images/iconeBingoLol.ico"));

    QResource::registerResource("resources/Resource.qrc");
    UsefullFunc::importUsedFonts();
    UsefullFunc::refreshStyleSheet(app);

    BingoLolWindows w;
    w.show();

    return app.exec();
}