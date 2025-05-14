# Calculator

A modern desktop calculator built in C++/Qt6 with a clean MVC separation, custom styling, and full expression support (`, +, -, *, /, ( ), .`).  
This project demonstrates:

- Qt Widgets for UI (`QMainWindow`, `QPushButton`, `QLineEdit`, `QGridLayout`)  
- CMake-based cross-platform build  
- Shunting-yard algorithm for parsing & evaluating infix expressions  
- Custom styling via Qt Style Sheets (QSS)  
- Parentheses and operator precedence


## Features

- **Full expression support**: parentheses, decimal points, operator precedence  
- **Clear (C)** and **equals (=)** buttons  
- **Resizable** UI with adaptive layouts  
- **Custom theming** via QSS or inline style definitions  
- **Easy to extend**: add scientific functions, memory buttons, history panel, etc.

## Tech Stack

- **C++17**  
- **Qt6 (Widgets)**  
- **CMake** (out-of-source builds)  
- **MSYS2/MinGW** (on Windows) or any C++17 toolchain  
- **Git & GitHub** for version control  

## Prerequisites

- Qt6 (MinGW or MSVC build) installed  
- CMake ≥ 3.16  
- A C++17 compiler (MinGW-g++, MSVC, or Clang)  
- (Optional) Qt Creator for zero-config development  

## Quickstart

### 1. Clone & initialize submodules (if any)


```
git clone "https://github.com/YaSh88991/Calculator_CPP.git" 

cd Calculator
```

## Build with Qt Creator
```
1. Open **CMakeLists.txt** in Qt Creator  
2. Select the **Desktop Qt6 MinGW** (or MSVC) kit  
3. Click **Run** (Ctrl+R)  

```
## Build from the Command Line (MinGW)
```
mkdir build && cd build
cmake -G "MinGW Makefiles" ..
mingw32-make
./calculator.exe

```
## On Linux/macOS, omit the -G flag and use your native build tool

```
mkdir build && cd build
cmake ..
make
./calculator

```

## Usage

- Click digits/operators to build an expression.  
- Press `=` to evaluate, `C` to clear.  
- Parentheses are fully supported:

```text
(1 + 2) * 3 → 9
12.5 / (2.5 + 0.5) → 4
```

## Styling

### Inline QSS in `GuiApp.cpp`
By default, inline QSS in GuiApp.cpp skins the UI. You can tweak colors, fonts, hover/pressed states:

```cpp
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

```
## Roadmap

- Scientific functions (`sin`, `cos`, `log`, …)  
- Calculation history panel  
- Keyboard input support  
- Unit tests for `Calculator` logic (Catch2 or Google Test)  
- CI/CD with GitHub Actions  


