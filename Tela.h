#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QObject>
#include <QList>
#include "Serial.h"
class Tela : public QWidget {

    Q_OBJECT

private:
    QComboBox * portasDisponiveis;
    Serial * portas;
    QHBoxLayout * principal;

public:
    Tela();
    ~Tela();

public slots:
    void selecionaPorta(int a);
};
