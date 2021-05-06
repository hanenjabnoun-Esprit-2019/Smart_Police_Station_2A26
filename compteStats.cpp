#include <QSqlQueryModel>
#include <QSqlQuery>
#include "personnel.h"


//hommes
int compteJanvier(){
    QSqlQueryModel * janvier = new QSqlQueryModel();
    janvier->setQuery("SELECT * from horaire "
                        "WHERE (debut>='01/01/2021' AND debut<='31/01/2021') "
                        "OR (fin>='01/01/2021' AND fin<='31/01/2021')");
    return janvier->rowCount();
}
int compteFevrier(){
    QSqlQueryModel * fevrier = new QSqlQueryModel();
    fevrier->setQuery("SELECT * from horaire "
                        "WHERE (debut>='01/02/2021' AND debut<='28/02/2021') "
                        "OR (fin>='01/02/2021' AND fin<='28/02/2021')"
                        "OR (debut<='01/02/2021' AND fin>='28/02/2021')");
    return fevrier->rowCount();
}
int compteMars(){
    QString genre  = "homme";
    QSqlQueryModel * mars = new QSqlQueryModel();
    mars->setQuery("SELECT h.*, p.sexe from horaire h"
                        "LEFT JOIN personnel p ON p.id = h.agent "
                        "WHERE ((debut>='01/03/2021' AND debut<='31/03/2021') OR (fin>='01/03/2021' AND fin<='31/03/2021') OR (debut<='01/03/2021' AND fin>='31/03/2021'))");
                 //       "AND p.sexe LIKE '"+genre+"%' ");
    return mars->rowCount();
}
int compteAvril(){
    QSqlQueryModel * avril = new QSqlQueryModel();
    avril->setQuery("SELECT * from horaire "
                        "WHERE (debut>='01/04/2021' AND debut<='30/04/2021') "
                        "OR (fin>='01/04/2021' AND fin<='30/04/2021')"
                        "OR (debut<='01/04/2021' AND fin>='30/04/2021')");
    return avril->rowCount();
}
int compteMai(){
    QSqlQueryModel * mai = new QSqlQueryModel();
    mai->setQuery("SELECT * from horaire "
                        "WHERE (debut>='01/05/2021' AND debut<='31/05/2021') "
                        "OR (fin>='01/05/2021' AND fin<='31/05/2021')"
                        "OR (debut<='01/05/2021' AND fin>='31/05/2021')");
    return mai->rowCount();
}
int compteJuin(){
    QSqlQueryModel * juin = new QSqlQueryModel();
    juin->setQuery("SELECT * from horaire "
                        "WHERE (debut>='01/06/2021' AND debut<='30/06/2021') "
                        "OR (fin>='01/06/2021' AND fin<='30/06/2021')"
                        "OR (debut<='01/06/2021' AND fin>='30/06/2021')");
    return juin->rowCount();
}
int compteJuillet(){
    QSqlQueryModel * juillet = new QSqlQueryModel();
    juillet->setQuery("SELECT * from horaire "
                        "WHERE (debut>='01/07/2021' AND debut<='31/07/2021') "
                        "OR (fin>='01/07/2021' AND fin<='31/07/2021')"
                        "OR (debut<='01/07/2021' AND fin>='31/07/2021')");
    return juillet->rowCount();
}
int compteAout(){
    QSqlQueryModel * aout = new QSqlQueryModel();
    aout->setQuery("SELECT * from horaire "
                        "WHERE (debut>='01/08/2021' AND debut<='31/08/2021') "
                        "OR (fin>='01/08/2021' AND fin<='31/08/2021')"
                        "OR (debut<='01/08/2021' AND fin>='31/08/2021')");
    return aout->rowCount();
}
int compteSeptembre(){
    QSqlQueryModel * septembre = new QSqlQueryModel();
    septembre->setQuery("SELECT * from horaire "
                        "WHERE (debut>='01/09/2021' AND debut<='30/09/2021') "
                        "OR (fin>='01/09/2021' AND fin<='30/09/2021')"
                        "OR (debut<='01/09/2021' AND fin>='30/09/2021')");
    return septembre->rowCount();
}
int compteOctobre(){
    QSqlQueryModel * octobre = new QSqlQueryModel();
    octobre->setQuery("SELECT * from horaire "
                        "WHERE (debut>='01/10/2021' AND debut<='31/10/2021') "
                        "OR (fin>='01/10/2021' AND fin<='31/10/2021')"
                        "OR (debut<='01/10/2021' AND fin>='31/10/2021')");
    return octobre->rowCount();
}
int compteNovembre(){
    QSqlQueryModel * novembre = new QSqlQueryModel();
    novembre->setQuery("SELECT * from horaire "
                        "WHERE (debut>='01/11/2021' AND debut<='30/11/2021') "
                        "OR (fin>='01/11/2021' AND fin<='30/11/2021')"
                        "OR (debut<='01/11/2021' AND fin>='30/11/2021')");
    return novembre->rowCount();
}
int compteDecembre(){
    QSqlQueryModel * decembre = new QSqlQueryModel();
    decembre->setQuery("SELECT * from horaire "
                        "WHERE (debut>='01/12/2021' AND debut<='31/12/2021') "
                        "OR (fin>='01/12/2021' AND fin<='31/12/2021')"
                        "OR (debut<='01/12/2021' AND fin>='31/12/2021')");
    return decembre->rowCount();
}


//femmes
