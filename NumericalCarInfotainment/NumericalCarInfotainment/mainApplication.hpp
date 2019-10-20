#pragma once

class MainWindow;

class MainApplication
{
public:

    /* @brief création d'un gestionnaire de fichier */
    static MainApplication * init();
    /* création de l'unique instance de la classe */
    static MainApplication * get_instance();


private:
    MainWindow * _mainwindow;

    static MainApplication * _instance;
    MainApplication();
};
