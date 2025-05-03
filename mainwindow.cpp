#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentExerciseIndex(0),
    timeRemaining(30),
    timer(new QTimer(this)) {

    ui->setupUi(this);

    exercises << "Приседания" << "Отжимания" << "Планка" << "Выпады";

    connect(timer.get(), &QTimer::timeout, this, &MainWindow::updateTimer);
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startWorkout);
    connect(ui->nextButton, &QPushButton::clicked, this, &MainWindow::nextExercise);
}

MainWindow::~MainWindow() = default;

void MainWindow::startWorkout() {
    currentExerciseIndex = 0;
    nextExercise();
}

void MainWindow::nextExercise() {
    if (currentExerciseIndex < exercises.size()) {
        ui->exerciseLabel->setText(exercises[currentExerciseIndex]);
        timeRemaining = 30;
        timer->start(1000);
        currentExerciseIndex++;
    } else {
        ui->exerciseLabel->setText("Тренировка завершена!");
        timer->stop();
    }
}

void MainWindow::updateTimer() {
    timeRemaining--;
    ui->timerLabel->setText(QString::number(timeRemaining));
    if (timeRemaining <= 0) {
        timer->stop();
        ui->timerLabel->setText("Время вышло!");
    }
}
