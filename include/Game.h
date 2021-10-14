#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include "Factories.h"
#include <vector>

class Game
{
public:

    Game();
    ~Game();
    void run();
    void update();
    void endGame();

private:

    bool m_gameIsRunning;
    SDL_Window* gWindow;
    SDL_Surface* gScreenSurface;
    SDL_Surface* gXOut;
    SDL_Renderer* gRenderer;

    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    const int BUTTON_WIDTH = 212;
    const int BUTTON_HEIGHT = 240;

    bool m_factoryTest;
    Factory* factory;
    std::vector<Brick*> m_bricks;

    TTF_Font* font;
    SDL_Color color;
    SDL_Surface* legoText;
    SDL_Texture* legoTexture;
    SDL_Rect legoDest;
    SDL_Rect legoSrcRct;

    SDL_Surface* clayText;
    SDL_Texture* clayTexture;
    SDL_Rect clayDest;
    SDL_Rect claySrcRct;

    SDL_Surface* limeText;
    SDL_Texture* limeTexture;
    SDL_Rect limeDest;
    SDL_Rect limeSrcRct;

    SDL_Surface* ashText;
    SDL_Texture* ashTexture;
    SDL_Rect ashDest;
    SDL_Rect ashSrcRct;

    SDL_Surface* undoText;
    SDL_Texture* undoTexture;
    SDL_Rect undoDest;
    SDL_Rect undoSrcRct;

    SDL_Surface* redoText;
    SDL_Texture* redoTexture;
    SDL_Rect redoDest;
    SDL_Rect redoSrcRct;

};