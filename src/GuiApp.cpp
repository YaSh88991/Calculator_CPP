#include "GuiApp.hpp"
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QWidget>

GuiApp::GuiApp(QWidget *parent)
    : QMainWindow(parent),
      display_(new QLineEdit(this))
{
    setWindowTitle("Calculator");
    resize(360, 480); // ↑ make the window taller/wider

    QWidget *central = new QWidget(this);
    auto *layout = new QGridLayout(central);

    // ─── Display ───────────────────────────────────────────
    display_->setReadOnly(true);
    display_->setAlignment(Qt::AlignRight);
    display_->setFixedHeight(50);
    layout->addWidget(display_, 0, 0, 1, 4);

    // ─── Parentheses & Clear & Divide row (row 1) ─────────
    const QStringList topRow = {"(", ")", "C", "/"};
    for (int col = 0; col < 4; ++col)
    {
        QPushButton *btn = new QPushButton(topRow[col], this);
        btn->setFixedSize(80, 60);

        // ↑↑ Make the text larger ↑↑
        QFont f = btn->font(); // grab its default font
        f.setPointSize(18);    // bump up to ~18pt (tweak as needed)
        btn->setFont(f);

        layout->addWidget(btn, 1, col);
        buttons_.append(btn);
        connect(btn, &QPushButton::clicked, this, &GuiApp::onButtonClicked);
    }

    // ─── Numbers & operators grid (rows 2–5) ─────────────
    const QStringList keys = {
        "7", "8", "9", "*",
        "4", "5", "6", "-",
        "1", "2", "3", "+",
        "0", ".", "=", "/"};
    int idx = 0;
    for (int row = 2; row <= 5; ++row)
    {
        for (int col = 0; col < 4; ++col)
        {
            QPushButton *btn = new QPushButton(keys[idx], this);
            btn->setFixedSize(80, 60);

            // ↑↑ Make the text larger ↑↑
            QFont f = btn->font(); // grab its default font
            f.setPointSize(18);    // bump up to ~18pt (tweak as needed)
            btn->setFont(f);

            layout->addWidget(btn, row, col);
            buttons_.append(btn);
            connect(btn, &QPushButton::clicked, this, &GuiApp::onButtonClicked);
            ++idx;
        }
    }

    setCentralWidget(central);

    // A dark theme for the entire Calculator window
    QString qss = R"(
    /* Main window background */
    QWidget {
        background-color: #2b2b2b;
    }
    /* The display at the top */
    QLineEdit {
        background-color: #3c3f41;
        color: #ffffff;
        border: 2px solid #555555;
        border-radius: 5px;
        padding: 8px;
        font-size: 24pt;
    }
    /* All buttons share this base look */
    QPushButton {
        background-color: #4a4a4a;
        color: #ffffff;
        border: none;
        border-radius: 5px;
        font-size: 18pt;
    }
    /* Hover and pressed states */
    QPushButton:hover {
        background-color: #5c5c5c;
    }
    QPushButton:pressed {
        background-color: #7f7f7f; 
        padding-left:2px; padding-top:2px; 
    }
)";
    central->setStyleSheet(qss);
}

void GuiApp::onButtonClicked()
{
    auto *btn = qobject_cast<QPushButton *>(sender());
    if (!btn)
        return;

    QString txt = btn->text();
    if (txt == "C")
    {
        calc_.clear();
        display_->clear();
    }
    else if (txt == "=")
    {
        try
        {
            double result = calc_.evaluate();
            QString out = QString::number(result);
            display_->setText(out);
            calc_.clear(); // start fresh after showing result
        }
        catch (const std::exception &e)
        {
            display_->setText("Error");
            calc_.clear();
        }
    }
    else
    {
        char c = txt.toStdString()[0];
        calc_.append(c);
        display_->setText(QString::fromStdString(calc_.expression()));
    }
}
