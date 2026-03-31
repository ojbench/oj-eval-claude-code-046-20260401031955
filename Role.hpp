#include<string>
#include<iostream>
#ifndef ROLE_HPP
#define ROLE_HPP
namespace final{

    class Fighter;
    class Protector;
    class Caster;

    //uncompleted, you should add code into this class
    class Base{
        friend class Fighter;
        friend class Protector;
        friend class Caster;
    private:
        //WARNING: NO OTHER MEMBER VARIABLE IS ALLOWED TO BE ADDED HERE.
        std::string name;
        int health,attack;
        bool alive,defensive;
        static int aliveNumber;
    protected:
        Base(const std::string& name, const int health, const int attack)
            : name(name), health(health), attack(attack), alive(true), defensive(false) {
            ++aliveNumber;
        }

    public:
        //WARNING: NO OTHER PUBLIC FUNCTION IS ALLOWED TO BE ADDED.
        //WARNING: THIS CLASS(Base) CAN NOT BE INSTANTIATED（实例化）.
        //WARNING: THE FUNCTION PROVIDED NEED NO MODIFICATION
        //the function you need to implement or define is as follows.
        //(1) getAliveNumber
        //(2) Constructor
        //(3) launch_attack
        //(4) defend

        virtual ~Base() {
            if (alive) {
                --aliveNumber;
            }
        }

        static int getAliveNumber() {
            return aliveNumber;
        }

        bool isAlive(){
            return alive;
        }

        bool isDefensive(){
            return defensive;
        }

        virtual void launch_attack(Base* target) = 0;
        virtual void defend(bool flag) = 0;
    };

    int Base::aliveNumber = 0;

    class Fighter:public Base{
    public:
        //WARNING: NO OTHER PUBLIC FUNCTION IS ALLOWED TO BE ADDED.
        //WARNING: THE FUNCTION PROVIDED NEED NO MODIFICATION
        Fighter (const std::string& name, const int health,const int attack):Base(name,health,attack){}

        void launch_attack(Base* target);

        void defend(bool flag){
            if (flag) {
                defensive = 1;
                health += 3;
                attack += 2;
            } else {
                defensive = 0;
            }
        }
    };

    class Protector:public Base{
    public:
        //WARNING: NO OTHER PUBLIC FUNCTION IS ALLOWED TO BE ADDED.
        //WARNING: THE FUNCTION PROVIDED NEED NO MODIFICATION
        Protector (const std::string& name, const int health,const int attack):Base(name,health,attack){}

        void launch_attack(Base* target);

        void defend(bool flag){
            if (flag) {
                defensive = 1;
                health += 7;
                attack += 1;
            } else {
                defensive = 0;
            }
        }
    };

    class Caster:public Base{
    public:
        //WARNING: NO OTHER PUBLIC FUNCTION IS ALLOWED TO BE ADDED.
        //WARNING: THE FUNCTION PROVIDED NEED NO MODIFICATION
        Caster (const std::string& name, const int health,const int attack):Base(name,health,attack){}

        void launch_attack(Base* target);

        void defend(bool flag){
            if (flag) {
                defensive = 1;
                health += 5;
            } else {
                defensive = 0;
            }
        }
    };

    void Fighter::launch_attack(Base *target) {
        // Fighter deals double damage to Caster
        int multiplier = (dynamic_cast<Caster*>(target) != nullptr) ? 2 : 1;
        int damage = attack * multiplier;

        if (target->defensive) {
            // Target is defending
            int reducedDamage = damage - target->attack;
            if (reducedDamage > 0) {
                target->health -= reducedDamage;
            }
            // Attacker takes counter damage (not for Caster)
            health -= target->attack;

            // Check if attacker dies
            if (health <= 0) {
                alive = false;
                --aliveNumber;
            }

            // Check if target dies
            if (target->health <= 0) {
                target->alive = false;
                --aliveNumber;
                // Output death message
                if (dynamic_cast<Fighter*>(target) != nullptr) {
                    std::cout << "Fighter " << target->name << " is killed\n";
                } else if (dynamic_cast<Protector*>(target) != nullptr) {
                    std::cout << "Protector " << target->name << " is killed\n";
                } else if (dynamic_cast<Caster*>(target) != nullptr) {
                    std::cout << "Caster " << target->name << " is killed\n";
                }
            }

            // If both die, attacker's death message comes after target's
            if (!alive) {
                std::cout << "Fighter " << name << " is killed\n";
            }
        } else {
            // Target is not defending
            target->health -= damage;

            if (target->health <= 0) {
                target->alive = false;
                --aliveNumber;
                // Output death message
                if (dynamic_cast<Fighter*>(target) != nullptr) {
                    std::cout << "Fighter " << target->name << " is killed\n";
                } else if (dynamic_cast<Protector*>(target) != nullptr) {
                    std::cout << "Protector " << target->name << " is killed\n";
                } else if (dynamic_cast<Caster*>(target) != nullptr) {
                    std::cout << "Caster " << target->name << " is killed\n";
                }
            }
        }
    }

    void Protector::launch_attack(Base *target) {
        // Protector deals double damage to Fighter
        int multiplier = (dynamic_cast<Fighter*>(target) != nullptr) ? 2 : 1;
        int damage = attack * multiplier;

        if (target->defensive) {
            // Target is defending
            int reducedDamage = damage - target->attack;
            if (reducedDamage > 0) {
                target->health -= reducedDamage;
            }
            // Attacker takes counter damage (not for Caster)
            health -= target->attack;

            // Check if attacker dies
            if (health <= 0) {
                alive = false;
                --aliveNumber;
            }

            // Check if target dies
            if (target->health <= 0) {
                target->alive = false;
                --aliveNumber;
                // Output death message
                if (dynamic_cast<Fighter*>(target) != nullptr) {
                    std::cout << "Fighter " << target->name << " is killed\n";
                } else if (dynamic_cast<Protector*>(target) != nullptr) {
                    std::cout << "Protector " << target->name << " is killed\n";
                } else if (dynamic_cast<Caster*>(target) != nullptr) {
                    std::cout << "Caster " << target->name << " is killed\n";
                }
            }

            // If both die, attacker's death message comes after target's
            if (!alive) {
                std::cout << "Protector " << name << " is killed\n";
            }
        } else {
            // Target is not defending
            target->health -= damage;

            if (target->health <= 0) {
                target->alive = false;
                --aliveNumber;
                // Output death message
                if (dynamic_cast<Fighter*>(target) != nullptr) {
                    std::cout << "Fighter " << target->name << " is killed\n";
                } else if (dynamic_cast<Protector*>(target) != nullptr) {
                    std::cout << "Protector " << target->name << " is killed\n";
                } else if (dynamic_cast<Caster*>(target) != nullptr) {
                    std::cout << "Caster " << target->name << " is killed\n";
                }
            }
        }
    }

    void Caster::launch_attack(Base *target) {
        // Caster deals double damage to Protector
        int multiplier = (dynamic_cast<Protector*>(target) != nullptr) ? 2 : 1;
        int damage = attack * multiplier;

        if (target->defensive) {
            // Target is defending
            int reducedDamage = damage - target->attack;
            if (reducedDamage > 0) {
                target->health -= reducedDamage;
            }
            // Caster does not take counter damage

            // Check if target dies
            if (target->health <= 0) {
                target->alive = false;
                --aliveNumber;
                // Output death message
                if (dynamic_cast<Fighter*>(target) != nullptr) {
                    std::cout << "Fighter " << target->name << " is killed\n";
                } else if (dynamic_cast<Protector*>(target) != nullptr) {
                    std::cout << "Protector " << target->name << " is killed\n";
                } else if (dynamic_cast<Caster*>(target) != nullptr) {
                    std::cout << "Caster " << target->name << " is killed\n";
                }
            }
        } else {
            // Target is not defending
            target->health -= damage;

            if (target->health <= 0) {
                target->alive = false;
                --aliveNumber;
                // Output death message
                if (dynamic_cast<Fighter*>(target) != nullptr) {
                    std::cout << "Fighter " << target->name << " is killed\n";
                } else if (dynamic_cast<Protector*>(target) != nullptr) {
                    std::cout << "Protector " << target->name << " is killed\n";
                } else if (dynamic_cast<Caster*>(target) != nullptr) {
                    std::cout << "Caster " << target->name << " is killed\n";
                }
            }
        }
    }
}
#endif //ROLE_HPP
