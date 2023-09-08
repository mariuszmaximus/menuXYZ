#include "menuxy.h"

#include <QVBoxLayout>
#include <QDebug>

MenuXY::MenuXY(QWidget *parent,MenuXY *prevMenu)
    : QWidget{parent},prevMenu(prevMenu)
{

    QString str = " QPushButton:focus { background-color: red;}";

    setStyleSheet(str);

    installEventFilter(this);

    auto verticalLayout = new QVBoxLayout(this);
    verticalLayout->setContentsMargins(0,0,0,0);
    verticalLayout->setSpacing(0);


    int SIZE{5};

    for(int i = 0; i < SIZE; ++i)
    {

        auto *obj  = new QPushButton;
        listBtn.append(obj);
        // obj->setFlat(true);

        obj->setMinimumHeight(44);
        obj->setMaximumHeight(44);
        obj->setAutoDefault(true);

        obj->setText("Button " + QString::number(i));
        obj->installEventFilter(this);
        verticalLayout->addWidget( obj);
    }

    setLayout(verticalLayout);
}




void MenuXY::focusPrev()
{
    for(int i = 0; i < listBtn.size(); ++i)
    {
        if(listBtn[i]->hasFocus())
        {
            int nextIndex=listBtn.size()-1;
            if((i)>0) // bez pierwszej pozycji !!!
            {
                nextIndex = i-1;
            }

            listBtn[nextIndex]->setFocus();
            return;
        }
    }

}


void MenuXY::focusNext()
{
    for(int i = 0; i < listBtn.size(); ++i)
    {
        if(listBtn[i]->hasFocus())
        {
            qDebug() << "hasFocus " << i;
            int nextIndex{0};
            if((i+1)<listBtn.size()) // do przedostatniej pozycji !!!
            {
                nextIndex = i+1;
            }

            qDebug() << "nextIndex " << nextIndex;
            listBtn[nextIndex]->setFocus();
            return;
        }
    }

}

bool MenuXY::eventFilter(QObject *obj, QEvent *event)
{

    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);


        if (keyEvent->key() == Qt::Key_Return)
        {
            // close();
            qDebug() << obj;
            qDebug() << event;

            //on_pushButton_clicked();
            return QWidget::eventFilter(obj, event);
            //            return true;
        }


        if (keyEvent->key() == Qt::Key_Escape)
        {
            close();
            return true;
        }
        else
            if (keyEvent->key() == Qt::Key_Left || keyEvent->key() == Qt::Key_Up)
            {
                focusPrev();
                return  true;
            }
            else if (keyEvent->key() == Qt::Key_Right || keyEvent->key() == Qt::Key_Down)
            {
                focusNext();
                return  true;
            }
    }

    // Pozostałe zdarzenia zostawiamy do domyślnego filtrowania
    return QWidget::eventFilter(obj, event);
}


void  MenuXY::hideEvent(QHideEvent *event)
{
    releaseKeyboard();
    if (prevMenu)
    {
        if(prevMenu->listBtn.size()>0)
            prevMenu->listBtn[0]->setFocus();
        event->accept();
    }
    QWidget::hideEvent(event);
}

void  MenuXY::showEvent(QShowEvent *event)
{
    grabKeyboard();

    if(not listBtn.empty()) listBtn[0]->setFocus();
    QWidget::showEvent(event);
}
