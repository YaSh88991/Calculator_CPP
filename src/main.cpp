#include <QApplication>
#include "GuiApp.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    GuiApp window;
    window.show();
    return app.exec();
}
