#include <iostream>
#include "DataManager.hpp"

using namespace std;

class MainManager
{
public:
    void Main()
    {
        int option;
        do
        {
            cin >> option;
            cin.ignore();

            cout << "------------------------------------------------";

            cout << "Registros            01";
            cout << "Adicionar registro   02";
            cout << "Configurações        03";
            cout << "Sair                 04";

            cout << "------------------------------------------------";

            switch (option)
            {
            case (1):
                // relatorio
                break;
            case (2):
                break;
            case (3):
                cout << "Buscar por resgistro    01";
                cout << "Deletar resgistro       02";
                cout << "Filtrar registro        03";
                cout << "Voltar ao menu inicial  04";

                int option2;
                cin >> option2;
                cin.ignore();

                do
                {
                    switch (option2)
                    {
                    case (1):

                        break;
                    case (2):

                        break;
                    case (3):

                        break;
                    case (4):

                        break;
                    default:
                        cout << "opção invalida \n Por favor digitar outro numero:";
                        break;
                    }

                } while (option2 != 4);

                break;
            case (4):
                break;
            default:
                cout << "opção invalida \n Por favor digitar outro numero: ";
                break;
            }

        } while (option == 4);
        cout << "Obrigado por sua prefêrencia (-; .";
    }
};

main()
{
    DataManager mng = DataManager();
    return 0;
}
