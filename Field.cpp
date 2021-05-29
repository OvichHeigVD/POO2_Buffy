//
// Created by stefa on 22.05.2021.
//

#include "Field.h"
#include "Utils.h"
#include "Humanoid/Buffy.h"

using namespace std;

Field::Field(int width, int height, int numberOfHumans, int numberOfVampires) :
    turn(0),
    width(width), height(height),
    initialNumberOfHumans(numberOfHumans), initialNumberOfVampires(numberOfVampires),
    remainingHumans(numberOfHumans), remainingVampires(numberOfVampires)
    {
        this->humanoids.push_back(new Buffy(this->createPosition()));
        for(int i = 0; i < numberOfHumans; ++i)
            this->humanoids.push_back(new Human(this->createPosition()));
        for(int i = 0; i < numberOfVampires; ++i)
            this->humanoids.push_back(new Vampire(this->createPosition()));
}

int Field::nextTurn()
{
// Déterminer les prochaines actions
    for (Iterator it = humanoids.begin(); it != humanoids.end(); it++)
        (*it)->setAction(*this);
// Executer les actions
    for (Iterator it = humanoids.begin(); it != humanoids.end(); it++)
        (*it)->executeAction(*this);
// Enlever les humanoides tués
    for (Iterator it = humanoids.begin(); it != humanoids.end(); ){
        if (!(*it)->isAlive()) {
            // buffy is never killed anyway, no find Buffy method
            (*it)->isHuman() ? this->remainingHumans-- : this->remainingVampires--;
            Humanoid* toDelete = *it;
            it = humanoids.erase(it); // suppression de l’élément dans la liste
            delete toDelete; // destruction de l’humanoide référencé
        }else{
            ++it;
        }
    }
    return turn++;
}

int Field::getWidth() const {
    return this->width;
}

int Field::getHeight() const {
    return this->height;
}

void Field::addVampire(Vampire* vampire) {
    this->remainingVampires++;
    this->humanoids.push_back(vampire);
}

Position Field::createPosition() const {
   return {
       Utils::randomInt(1, this->getWidth()),
       Utils::randomInt(1, this->getHeight())
   };
}

Field::Iterator Field::begin() {
    return this->humanoids.begin();
}

Field::Iterator Field::end() {
    return this->humanoids.end();
}

Field::ConstIterator Field::begin() const {
    return this->humanoids.begin();
}

Field::ConstIterator Field::end() const {
    return this->humanoids.end();
}

template <typename T>
T Field::findClosestHumanoid(const Position& from, double& minDistance) const {
    ConstIterator closestHumanIt = this->end();
    ConstIterator it             = this->begin();
    for (; it != this->end(); it++){
        T humanoid = dynamic_cast<T>(*it);
        if(humanoid != nullptr){
            double distance = Position::distance(from, humanoid->getPosition());
            if(distance < minDistance){
                minDistance = distance;
                closestHumanIt = it;
            }
        }
    }
    return closestHumanIt != this->end() ? dynamic_cast<T>(*closestHumanIt) : nullptr;
}


Field::~Field() {
    while(!this->humanoids.empty())
        delete this->humanoids.front(), this->humanoids.pop_front();
}

int Field::humansRemaining() const {
    return this->remainingHumans;
}

int Field::vampiresRemaining() const {
    return this->remainingVampires;
}

int Field::initialHumans() const {
    return this->initialNumberOfHumans;
}

int Field::initialVampires() const {
    return this->initialNumberOfVampires;
}

// specialization explicite de la méthode template, accept que Human* et Vampire*
template Human*     Field::findClosestHumanoid<Human*>(const Position& from, double& minDistance) const;
template Vampire*   Field::findClosestHumanoid<Vampire*>(const Position& from, double& minDistance) const;