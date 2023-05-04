#include "LegalPerson.hpp"

    LegalPerson::LegalPerson()
    {

    }

    LegalPerson::~LegalPerson()
    {

    }

    void LegalPerson::avaliation(float a){
    if(a < 3){
        avaliationName = "Ruim";
    } else if(a < 5){
        avaliationName = "Bom";
    } else if(a == 5){
        avaliationName = "Excelente";
    } else {
        avaliationName = "Avaliação inválida";
    }

}

