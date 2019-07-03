#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model=new QStringListModel(this);
    linkedList=new LinkedList<Image>();
    curNode=linkedList->getFirstPtr();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clearAll()
{
    ui->addresLabel->setText(" ");
    ui->readName->clear();
    this->model->setStringList(QStringList{});
    this->labelsList.clear();
    this->labels.clear();
    ui->LoadImage->clear();
    ui->showAddres->clear();
}

void MainWindow::showImageAndFeatures()
{
    clearAll();//limpia todo para poder mostrar los parametros del nodo actual
    string imageAddres=curNode->getData().getName();//captura la direccion que guarda el nodo
    ui->showAddres->setText(QString::fromStdString(imageAddres));//establece la direccion el lineedit
    vector<string> labels=curNode->getData().getLabels();//captura el vector de label que guarda el nodo
    for (size_t  i=0;i<labels.size();i++) {//agrega cada label al QstringList para poder vizualisarlo en el menu
        labelsList.append(QString::fromStdString(labels[i]));
    }
    QPixmap * mypix = new QPixmap(QString::fromStdString(imageAddres));//crea un pixmap con la direccion de la imagen obtenida para poder visualizarlo
    int w=ui->label->width();//obtiene las dimenciones del label donde se insertara la imagen
    int h=ui->label->height();
    ui->label->setPixmap(mypix->scaled(w,h,Qt::KeepAspectRatio)); //establece la imagen
    model->setStringList(labelsList);//agrega la liista de etiquetas al modelo
    ui->listView_2->setModel(model);//agrega el modelo al listView para poder mostrarlo

}

void MainWindow::on_loadImageButton_clicked()
{
    QString  filename=QFileDialog::getOpenFileName(this,tr("open file"),"","All files (*.*)");//abre una ventana para cargar una imagen
    ui->addresLabel->setText(filename);//escribe la direccion obtenida en el label  addres label
    QPixmap pix(filename);
    int w=ui->LoadImage->width();//obtiene las dimenciones de label LoadImage para poder ajustar la imagen
    int h=ui->LoadImage->height();
    ui->LoadImage->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));//establece la imagen en LoadImage
}

void MainWindow::on_addLabelButton_clicked()
{
    QString readLabel=ui->readLabel->text();//obtiene el texto que esta en readLabel
    ui->readLabel->clear();//limpia el texto de readLabel
    this->labelsList.append(readLabel);//agrega a la lista de etiquetas
    this->labels.push_back(readLabel.toStdString());//agrega la etiqueta insertada al vector
    model->setStringList(labelsList);//agrega la liista de etiquetas al modelo
    ui->listView->setModel(model);//agrega el modelo al listView para poder mostrarlo
}

void MainWindow::on_insertAtFrontButton_clicked()
{
    Image *image=new Image(ui->addresLabel->text().toStdString());
    image->setLabels(this->labels);
    this->linkedList->insertAtFront(*image);
    clearAll();
}
void MainWindow::on_insertAtBackButton_clicked()
{
    Image *image=new Image((ui->addresLabel->text().toStdString()));
    image->setLabels(this->labels);
    this->linkedList->insertAtBack(*image);
    clearAll();
}

void MainWindow::on_BackButton_clicked()
{
    /*
    QPixmap * mypix = new QPixmap(":/images/2.jpg");
    int w=ui->label->width();
    int h=ui->label->height();
    ui->label->setPixmap(mypix->scaled(w,h,Qt::KeepAspectRatio));
    delete  mypix;*/

}
void MainWindow::on_NextButton_clicked()
{
    showImageAndFeatures();
    if(curNode->getNextPtr())
        curNode=curNode->getNextPtr();//como se dio click en el boton next tenemos que avanzar al siguiente nodo

}

void MainWindow::on_firstNodeButton_clicked()
{
    this->curNode=this->linkedList->getFirstPtr();
    showImageAndFeatures();
}

void MainWindow::on_lastNodeButton_clicked()
{
    this->curNode=this->linkedList->getLastPtr();
    showImageAndFeatures();
}
