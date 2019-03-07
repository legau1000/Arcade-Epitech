Combots de 5 groupes:

Tom:
    NDK++   GTK+    OPENGL

Florian:
    Libcaca SFML    QT

Julien:
    NCurses SDL     OpenGl

Victor Laplagne:
    NCurses Allegro/SFML    /

Julien Jean:
    a-lib   Xlib    OpenGl

Pour notre groupe:
    libcaca: Louis
    SFML:   Prune
    QT:     Florian

[MAIN]
   |
[Loop Menu] -> [Lib Graphique]
   |
[Loop Game]

toute les flêches sont bloqué pour changement lib et jeux

LibPrev: <-
LibNext: ->
GamePrev: Bas
GameNext: Haut

Core:
    void load_graph(char *lib);
    void launcher();
    void game();

Interface:
    IGameModule:
        void game();
        void initGame(char *name, lib);
        void setLib(lib);

    IDisplayModule: //Beaucoup de Override
        <!-- void catchEvent(); -->
        void createAsset(char *path);
        void drawAsset(ASSET);
        void drawWindow();
	void closeWindow();
	void openWindow();
        void destroyAsset(ASSET);
        void getType();


Game core:
    while () {
        <!-- game->game(); -->
        <!-- lib->catchEvent(); -->
        etc...;
    }