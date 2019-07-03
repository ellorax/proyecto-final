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
private slots:
    void on_loadImageButton_clicked();
    void on_addLabelButton_clicked();
    void on_insertAtFrontButton_clicked();
    void on_insertAtBackButton_clicked();
    void on_BackButton_clicked();
    void on_NextButton_clicked();
    void on_firstNodeButton_clicked();
    void on_lastNodeButton_clicked();

private:
    Ui::MainWindow *ui;
    QStringListModel *model;//esto servira para poder mostrar las etiquetas insertadas
    QStringList labelsList;//lista donde se guardaran las etiquetas
    vector<string> labels;//vector donde se guardaran las etiquetas
    LinkedList<Image> *linkedList;
    Node<Image> *curNode;
};

#endif // MAINWINDOW_H
