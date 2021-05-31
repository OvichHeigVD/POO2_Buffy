/**
 * @authors Dalia Maillefer, Stefan Teofanovic
 * @date 1er juin 2021
 *
 * @file Display.h
 * @brief Classe permettant de gérer l'affichage de Field et de ses Humanoid
 */

#ifndef LABO04_DISPLAY_H
#define LABO04_DISPLAY_H

#include "../Field.h"

class Humanoid;

class Display : public Field {
public:
    /**
     * Constructeur de Display
     * @param width - Une largeur
     * @param height - Une hauteur
     * @param numberOfHumans - Le nombre d'humains
     * @param numberOfVampires - Le nombre de vampires
     */
    Display(int width, int height, int numberOfHumans, int numberOfVampires);

    /**
     * Destructeur de Display
     */
    ~Display() override;

    /**
     * Méthode permettant de lancer la simulation sous forme de display
     */
    void run();

private:
    /**
     * Méthode permettant d'afficher le Field à chaque tour
     * @return un entier, le prochain tour
     */
    size_t nextTurn() override;

    /**
     * Méthode permettant de savoir si le programme est en marche
     * @return vrai si en marche, faux si arrêté
     */
    bool isRunning() const;

    /**
     * Méthode permettant d'arrêter le programme
     */
    void stop();

    /**
     * Méthode pemettant de initialiser les cases du tableau à vide
     */
    void clear();

    /**
     * Méthode se changeant de dessiner les bordures en haut et en bas du tableau
     */
    void drawLine() const;

    Humanoid*** screen; // tableau à deux dimensions de pointeurs sur Humanoid
    bool running;
};

#endif //LABO04_DISPLAY_H