#ifndef MENUXY_H
#define MENUXY_H

#include <QWidget>
#include <QPushButton>
#include <QHideEvent>
#include <QShowEvent>
#include <QList>

class MenuXY : public QWidget
{
    Q_OBJECT
public:
    explicit MenuXY(QWidget *parent = nullptr,MenuXY *prevMenu= nullptr);

public:
    QList <QPushButton*> listBtn;
signals:

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
    // onClose
    void hideEvent(QHideEvent *event) override;

    // onShow
    void showEvent(QShowEvent *event) override;

private:
    MenuXY *prevMenu;
    void focusNext();
    void focusPrev();

};

#endif // MENUXY_H
