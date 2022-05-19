void initialisation_allegro()
{
    allegro_init(); // appel obligatoire (var.globales, recup. infos système ...)
    install_keyboard(); //pour utiliser le clavier
    install_mouse(); //pour utiliser la souris
    srand(time(NULL));//pour utiliser de l'aléatoire
    //pour choisir la profondeur de couleurs (8,16,24 ou 32 bits)
    //ici : identique à celle du bureau
    set_color_depth(desktop_color_depth());
    //sélection du mode graphique


    // avec choix d'un driver+mode+résolution de l'écran
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1280,720,0,0)!=0) //Résolution choisie de 1280x720
    {
        // message et sortie de prog. si échec
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
