#include "../include/riddle.h"

Riddle::Riddle(QWidget *_parent) : QWidget(_parent)
{
    this->window = new QWidget;
}

void Riddle::display()
{
    this->connectToDatabase();
    Query q = this->getRandomQuery();
    QGridLayout *layout = this->createLayout(q);
    this->database.close();

    this->query = q;

    this->window->setWindowTitle("Énigme");
    this->window->setLayout(layout);
    this->window->show();
}

bool Riddle::waitForAnswer()
{
    QEventLoop loop;

    QButtonGroup *btnGrp = new QButtonGroup;
    btnGrp->addButton(this->optionOne, 1);
    btnGrp->addButton(this->optionTwo, 2);
    btnGrp->addButton(this->optionThree, 3);

    QObject::connect(btnGrp, &QButtonGroup::buttonClicked, &loop, &QEventLoop::quit);
    //QObject::connect(btnGrp, &QButtonGroup::buttonClicked, this, &QApplication::quit);
    QObject::connect(btnGrp, &QButtonGroup::idClicked, this, &Riddle::checkAnswer);

    // Wait for button to be clicked
    loop.exec();

    this->window->close();

    return this->pAnswer;
}

/* * * * * * * * * * * * * * * * *
 * * * * PROTECTED METHODS * * * *
 * * * * * * * * * * * * * * * * */

void Riddle::checkAnswer(int _idButton)
{
    this->pAnswer = _idButton == this->query.answer;
}

void Riddle::connectToDatabase()
{
    this->database = QSqlDatabase::addDatabase("QSQLITE");
    this->database.setDatabaseName("../RPG/settings/database.db");

    if (!this->database.open())
    {
        qDebug() << "[ERROR] Riddle::connectToDatabase : Unable to locate database";
        exit(-1);
    }
}

QGridLayout *Riddle::createLayout(Query _q)
{
    QGridLayout *riddleGrid = new QGridLayout(this->window);

    QLabel *question = new QLabel(_q.question);
    this->optionOne = new QPushButton(_q.optionOne);
    this->optionTwo = new QPushButton(_q.optionTwo);
    this->optionThree = new QPushButton(_q.optionThree);

    riddleGrid->addWidget(question, 0, 0, 1, 3);
    riddleGrid->addWidget(optionOne, 1, 0, 1, 1);
    riddleGrid->addWidget(optionTwo, 1, 1, 1, 1);
    riddleGrid->addWidget(optionThree, 1, 2, 1, 1);

    return riddleGrid;
}

Riddle::Query Riddle::getRandomQuery() const
{
    int nbRows = this->getTableLength();
    qint32 row = QRandomGenerator::global()->bounded(1, nbRows + 1);

    QSqlQuery query;
    query.exec(QString("SELECT * FROM riddle WHERE id=%1").arg(row));
    query.next();

    Query q;
    q.question = query.value("question").toString();
    q.optionOne = query.value("option_1").toString();
    q.optionTwo = query.value("option_2").toString();
    q.optionThree = query.value("option_3").toString();
    q.answer = query.value("answer").toInt();

    return q;
}

int Riddle::getTableLength() const
{
    QSqlQuery query;
    query.exec("SELECT * FROM riddle");

    int nbRows = 0;

    while (query.next())
        nbRows++;

    return nbRows;
}
