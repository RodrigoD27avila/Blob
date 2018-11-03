#include <QtGui>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget *mainWindow = new QWidget();

    QMenuBar *mainBar = new QMenuBar(mainWindow);

    QMenu *mainMenu = new QMenu(QString("Main Menu"));
    QMenu *menu1 = mainMenu->addMenu(QString("Menu1"));
    QMenu *menu2 = mainMenu->addMenu(QString("Menu2"));
    QMenu *menu3 = mainMenu->addMenu(QString("Menu3"));
    QMenu *menu4 = mainMenu->addMenu(QString("Menu4"));


    QMenu *fileMenu = new QMenu(QString("File"));
    fileMenu->addMenu(mainMenu);

    menu1->addMenu(fileMenu);
    menu2->addMenu(fileMenu);
    menu3->addMenu(fileMenu);
    menu4->addMenu(fileMenu);

    mainBar->addMenu(mainMenu);
    mainBar->addMenu(fileMenu);
    mainWindow->show();
    app.exec();

    delete menu1;
    delete menu2;
    delete menu3;
    delete menu4;
    delete mainMenu;
    delete fileMenu;
    delete mainBar;
    delete mainWindow;
    return 0;
}
