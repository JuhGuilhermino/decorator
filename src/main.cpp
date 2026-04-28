#include <iostream>
#include <string>

// COMPONENT: define a interface para o objeto personagem,
// que possui responsabilidades adcionadas dinamicamente.
class Personagem {
    public:
        virtual int ataque() = 0;
        virtual int defesa() = 0;
        virtual std::string descricao() = 0;
        virtual ~Personagem() {}
    };

// CONCRETE COMPONENT: define o objeto para o qual as
// responsabilidade adioncionais podem ser atribuidas.
class Guerreiro : public Personagem {
    public:
        int ataque() override {
            return 10;
        }

        int defesa() override {
            return 5;
        }

        std::string descricao() override {
            return "Guerreiro";
        }
};


// DECORATOR: mantém uma referencia para um objeto Personagem
// e define uma interface que segue a interface de Component.
class PersonagemDecorator : public Personagem {
    protected:
        Personagem* personagem;

    public:
        PersonagemDecorator(Personagem* p) : personagem(p) {}
};

// CONCRETE DECORATOR -> ARMADURA: acrescenta responsabilidade ao Personagem.
class Armadura : public PersonagemDecorator {
public:
    Armadura(Personagem* p) : PersonagemDecorator(p) {}

    int ataque() override {
        return personagem->ataque();
    }

    int defesa() override {
        return personagem->defesa() + 10;
    }

    std::string descricao() override {
        return personagem->descricao() + " + Armadura";
    }
};


// CONCRETE DECORATOR -> ESPADA MÁGICA: acrescenta responsabilidade ao Personagem.
class EspadaMagica : public PersonagemDecorator {
    public:
        EspadaMagica(Personagem* p) : PersonagemDecorator(p) {}

        int ataque() override {
            return personagem->ataque() + 15;
        }

        int defesa() override {
            return personagem->defesa();
        }

        std::string descricao() override {
            return personagem->descricao() + " + Espada Mágica";
        }
};

// CONCRETE DECORATOR -> ESCUDO: acrescenta responsabilidade ao Personagem.
class Escudo : public PersonagemDecorator {
    public:
        Escudo(Personagem* p) : PersonagemDecorator(p) {}

        int ataque() override {
            return personagem->ataque();
        }

        int defesa() override {
            return personagem->defesa() + 5;
        }

        std::string descricao() override {
            return personagem->descricao() + " + Escudo";
        }
};


// ===========================================

int main() {
    // Personagem 1
    Personagem* personagem = new Guerreiro();

    personagem = new Armadura(personagem);
    personagem = new EspadaMagica(personagem);
    personagem = new Escudo(personagem);

    std::cout << "PERSONAGEM 1: " << personagem->descricao() << std::endl;
    std::cout << "Ataque: " << personagem->ataque() << std::endl;
    std::cout << "Defesa: " << personagem->defesa() << std::endl;

    delete personagem;

    // Personagem 2
    Personagem* personagem2 = new Guerreiro();

    personagem2 = new Armadura(personagem);
    personagem2 = new Escudo(personagem);

    std::cout << "PERSONAGEM 2: " << personagem2->descricao() << std::endl;
    std::cout << "Ataque: " << personagem2->ataque() << std::endl;
    std::cout << "Defesa: " << personagem2->defesa() << std::endl;

    delete personagem2;

    return 0;
}