#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QStringList>
#include "scopedpointer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void startWorkout();
    void nextExercise();
    void updateTimer();

private:
    ScopedPointer<Ui::MainWindow> ui;
    QStringList exercises;
    int currentExerciseIndex;
    int timeRemaining;
    ScopedPointer<QTimer> timer;
};

#endif // MAINWINDOW_H
