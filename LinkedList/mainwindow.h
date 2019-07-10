#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "linkedlist.h"
#include "linkedlist.cpp"
#include "image.h"
#include "node.h"
#include <QFileDialog>
#include <QMenu>
#include <QDebug>
#include <QPixmap>
#include <QMainWindow>
#include <QStringListModel>
#include <vector>
#include <iostream>
#include <QFile>
#include <QMessageBox>
#include <QDataStream>
using namespace std;
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void clearAll();
    void showImageAndFeatures();
    friend inline QDataStream & operator<<(QDataStream &ds,const MainWindow &p);
    friend inline QDataStream & operator>>(QDataStream &ds,MainWindow &p);

private slots:
    void on_loadImageButton_clicked();
    void on_addLabelButton_clicked();
    void on_insertAtFrontButton_clicked();
    void on_insertAtBackButton_clicked();
    void on_BackButton_clicked();
    void on_NextButton_clicked();
    void on_firstNodeButton_clicked();
    void on_lastNodeButton_clicked();
    void on_pushButton_clicked();
    void onTabChanged(int tabIndex);
    void on_findButton_clicked();
    void on_deleteButton_clicked();
    void on_saveDataBase_clicked();

    void on_loadDataBase_clicked();

private:
    Ui::MainWindow *ui;
    QStringListModel *model;//esto servira para poder mostrar las etiquetas insertadas en una tabla
    QStringList labelsList;//lista donde se guardaran las etiquetas
    vector<string> labels;//vector donde se guardaran las etiquetas
    LinkedList<Image> *linkedList;
    Node<Image> *curNode;
    QString imageSavePath;
    void showAlertMessage(QString );//funcion para mostrar alertas
};
inline QDataStream & operator<<(QDataStream &ds,const MainWindow &p)
{
    return ds<< p.ui << p.model << p.labelsList  <<p.linkedList <<p.curNode << p.imageSavePath ;
}
#endif // MAINWINDOW_H
