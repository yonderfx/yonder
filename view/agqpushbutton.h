#ifndef AGQPUSHBUTTON_H
#define AGQPUSHBUTTON_H

#include <QPushButton>
#include <QString>
#include <QStyleOptionButton>
#include <QPainter>
#include <QPixmap>
#include <QTextDocument>
#include <QIcon>
#include <QSize>
#include <QMenu>
#include <QStylePainter>

#include <QDebug>

class AGQPushButton: public QPushButton
{
    Q_OBJECT
public:
    AGQPushButton(int pos_in_array, QWidget *parent);

    int pos_in_array;
    int oid;

    int getPosInArray();
    void setPosInArray(int pos_in_array);

    int getOID();
    void setOID(int oid);

    // rich text
    void setHtml(const QString &text);
    void setText(const QString &text);
    QString label();
    QString text() const;
    QString htmlText;

    QString standard_style;
    QString highlighted_style;

protected:
    void paintEvent(QPaintEvent *);

public slots:
    void emitToggled(bool checked);
    void setUnChecked();
    void setStandardStyle();
    void setHighlightedStyle();

signals:
    void toggled(int pos_in_array, bool checked);

private:
    bool isRichText;
    QStyleOptionButton getStyleOption() const;

};

#endif // AGQPUSHBUTTON_H
