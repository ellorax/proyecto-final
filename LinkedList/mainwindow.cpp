#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImageReader>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model=new QStringListModel(this);
    linkedList=new LinkedList<Image>();
    curNode=nullptr;
    connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(onTabChanged(int)));//conectar el signal con el slot para que cuando cambimos al tab showimages se inicialize                                                          //curNode en la cabeza de la lista enlazada
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
    if(curNode){
    clearAll();//limpia todo para poder mostrar los parametros del nodo actual
    string imagepath=curNode->getData().getPath();//captura la direccion que guarda el nodo
    ui->showAddres->setText(QString::fromStdString(imagepath));//establece la direccion el lineedit
    string imageName=curNode->getData().getName();
    ui->showNameLabel->setText("Name :"+QString::fromStdString(imageName));
    vector<string> labels=curNode->getData().getLabels();//captura el vector de label que guarda el nodo
    for (size_t  i=0;i<labels.size();i++) {//agrega cada label al QstringList para poder vizualisarlo en el menu
        labelsList.append(QString::fromStdString(labels[i]));
    }
    QPixmap * mypix = new QPixmap(QString::fromStdString(imagepath));//crea un pixmap con la direccion de la imagen obtenida para poder visualizarlo
    int w=ui->label->width();//obtiene las dimenciones del label donde se insertara la imagen
    int h=ui->label->height();
    ui->label->setPixmap(mypix->scaled(w,h,Qt::KeepAspectRatio)); //establece la imagen
    model->setStringList(labelsList);//agrega la liista de etiquetas al modelo
    ui->listView_2->setModel(model);//agrega el modelo al listView para poder mostrarlo
    ui->showImageSizeLabel->setText("Size : ("+w+','+h);

    }
}
void MainWindow::on_loadImageButton_clicked()
{
    QString  filename=QFileDialog::getOpenFileName(this,tr("open file"),"","All files (*.*)");//abre una ventana para cargar una imagen
    QFile f(filename);//crea un objeto Qfile esto serivira para poder obtener el nombre de la imagen
    QFileInfo fileinfo(f.fileName());
    ui->addresLabel->setText(filename);//escribe la direccion obtenida en el label  addres label
    QFile::copy(filename,this->imageSavePath+"/"+fileinfo.fileName());
    ui->readName->setText(fileinfo.fileName());
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
    Image *image=new Image(ui->readName->text().toStdString(),ui->addresLabel->text().toStdString());
    image->setLabels(this->labels);
    this->linkedList->insertAtFront(*image);
    clearAll();
}
void MainWindow::on_insertAtBackButton_clicked()
{
    Image *image=new Image(ui->readName->text().toStdString(),ui->addresLabel->text().toStdString());
    image->setLabels(this->labels);
    this->linkedList->insertAtBack(*image);
    clearAll();
}

void MainWindow::on_BackButton_clicked()
{
    if(curNode)//si el nodo esta inicializado a algo diferente a nullptr entra
    {
        if(curNode->getBackPtr())//si existe el nodo siguiente avanza y muestra el contenido
        {
            curNode=curNode->getBackPtr();//como se dio click en el boton next tenemos que avanzar al siguiente nodo
            showImageAndFeatures();
        }
        else {
            this->showAlertMessage("Ya no existen mas elementos hacia atras");
        }
    }
    else {
        this->showAlertMessage("Lista Enlzada vacia");
    }
}
void MainWindow::on_NextButton_clicked()
{
    if(curNode)
    {
        if(curNode->getNextPtr()){
            curNode=curNode->getNextPtr();//como se dio click en el boton next tenemos que avanzar al siguiente nodo
            showImageAndFeatures();
        }

        else {
            this->showAlertMessage("Ya no existen mas elementos hacia adelante");
        }
    }
    else {
        this->showAlertMessage("Lista Enlzada vacia");
    }
}

void MainWindow::on_firstNodeButton_clicked()//muestra el contenido del inicio de la lista enlazada
{
    if(!this->linkedList->isEmpty()){//si la lista no esta vacia
        this->curNode=this->linkedList->getFirstPtr();
        showImageAndFeatures();
    }
    else {
        this->showAlertMessage("Lista Enlzada vacia");
    }
}

void MainWindow::on_lastNodeButton_clicked()//muestra el contenido del final de la lista enlazada
{
    if(!this->linkedList->isEmpty())//si la lista no esta vacia
    {
        this->curNode=this->linkedList->getLastPtr();
        showImageAndFeatures();
    }
    else {
        this->showAlertMessage("Lista Enlzada vacia");
    }
}

void MainWindow::on_pushButton_clicked()
{
    this->imageSavePath=QFileDialog::getExistingDirectory(this,"select dic");//abre una ventana para establecer donde se guardaran las imagenes guardadas
    ui->imageSavePath->setText(imageSavePath);//muestra la direccion donde se guardaran las imagenes
}

void MainWindow::onTabChanged(int tabIndex)//cuando se cambia de tab automaticamente muestra el primer elemento de la lista enlazada si existe
{
    if(tabIndex==1)
    {   if(!this->linkedList->isEmpty()){
            this->curNode=this->linkedList->getFirstPtr();
            showImageAndFeatures();
        }
    }
}

void MainWindow::showAlertMessage(QString ms)
{
    QMessageBox *msgBox=new QMessageBox();
    msgBox->setText(ms);
    msgBox->exec();
    msgBox->deleteLater();
}

void MainWindow::on_findButton_clicked()
{
    if(curNode){
    QString name=ui->inputImageName->text();
    if(linkedList->getLastPtr()->getData().getName()==name.toStdString()){
        this->curNode=this->linkedList->getLastPtr();
        showImageAndFeatures();
    }
    else {
        Node<Image> *temPtr=linkedList->getFirstPtr();
        while (temPtr->getData().getName()!=name.toStdString()) {
            if(temPtr->getNextPtr()==linkedList->getLastPtr())
            {
                this->showAlertMessage("No existe la imagen");
                return;
            }
            temPtr=temPtr->getNextPtr();
        }
        curNode=temPtr;
        showImageAndFeatures();
    }
    }
}
void MainWindow::on_deleteButton_clicked()
{
    QString name=ui->inputImageName->text();
    if(this->linkedList->isEmpty())
    {
        this->showAlertMessage("La lista esta vacia");
    }
    else {
        if(linkedList->getFirstPtr()->getData().getName()==name.toStdString())
        {
            clearAll();
            curNode=nullptr;
            linkedList->deleteAtFront();
            curNode=linkedList->getFirstPtr();
        }
        else if (linkedList->getLastPtr()->getData().getName()==name.toStdString()) {
            clearAll();
            curNode=nullptr;
            linkedList->deleteAtBack();
            curNode=linkedList->getLastPtr();
        }
        else {
            Node<Image> *temPtr=linkedList->getFirstPtr();
            Node<Image> *previusPtr=temPtr;
            Node<Image> *util;
            while (temPtr->getData().getName()!=name.toStdString()) {
                if(temPtr->getNextPtr()==linkedList->getLastPtr())
                {
                    this->showAlertMessage("No existe la imagen");
                    return;
                }
                else {
                    previusPtr=temPtr;
                    temPtr=temPtr->getNextPtr();
                }
            }
            previusPtr->setNextPtr(temPtr->getNextPtr());
            util=temPtr->getNextPtr();
            util->setBackPtr(previusPtr);
            ui->label->clear();
            clearAll();
            curNode=nullptr;
            curNode=linkedList->getFirstPtr();
            delete temPtr;

        }
    }
}
void MainWindow::on_saveDataBase_clicked()
{
    QDataStream io;
    QFile arch;
    arch.setFileName("saveDb.txt");
    arch.open(QIODevice::WriteOnly);
    io.setDevice(&arch);
    io <<linkedList;
    arch.flush();
    arch.close();

}

void MainWindow::on_loadDataBase_clicked()
{
}
