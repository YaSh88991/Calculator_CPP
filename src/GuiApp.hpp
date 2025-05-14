#pragma once

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QStringList>
#include <QVector>
#include "Calculator.hpp"

class GuiApp : public QMainWindow {
    Q_OBJECT

public:
    explicit GuiApp(QWidget *parent = nullptr);

private slots:
    void onButtonClicked();

private:
    QLineEdit* display_;             // the calculator screen
    QVector<QPushButton*> buttons_;  // holds all the buttons
    Calculator   calc_; 
};
