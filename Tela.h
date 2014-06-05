#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QObject>
#include <QList>
<<<<<<< HEAD
#include <QTimer>

=======
>>>>>>> 01105cfe5582c578cf763d9555d103b739c31d21
#include "Serial.h"
class Tela : public QWidget {

    Q_OBJECT

private:
    QComboBox * portasDisponiveis;
    Serial * portas;
    QHBoxLayout * principal;
<<<<<<< HEAD
    QTimer * fechaTela;
=======
>>>>>>> 01105cfe5582c578cf763d9555d103b739c31d21

public:
    Tela();
    ~Tela();

public slots:
    void selecionaPorta(int a);
<<<<<<< HEAD
    void fecharTela();
=======
>>>>>>> 01105cfe5582c578cf763d9555d103b739c31d21
};
