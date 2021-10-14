#include "../include/Game.h"

Game::Game() :
    m_gameIsRunning{ false },
    gWindow{NULL},
    gScreenSurface{NULL},
    gXOut{NULL},
	m_factoryTest{true},
	factory{new BrickFactory},
	color{255,255,255}
{

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface( gWindow );
			gRenderer = SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED);
		}
		
		//Initialize SDL_TTF
		if ( TTF_Init() < 0 ) {
			std::cout << "Error initializing SDL_ttf: " << TTF_GetError() << std::endl;
		}
		else
		{
			font = TTF_OpenFont("../assets/Akira.otf", 24);
			if ( !font ) {
				std::cout << "Failed to load font: " << TTF_GetError() << std::endl;
			}
			else
			{
				legoText = TTF_RenderText_Solid( font, "Lego", color );
				if(!legoText)
				{
					std::cout << "Failed to render text: " << TTF_GetError() << std::endl;
				}
				else
				{
					legoTexture = SDL_CreateTextureFromSurface(gRenderer, legoText);
					legoSrcRct = {0,0,BUTTON_WIDTH - 20, BUTTON_HEIGHT - 20};
					legoDest = {0,0,BUTTON_WIDTH - 20, BUTTON_HEIGHT - 20};
				}

				clayText = TTF_RenderText_Solid( font, "Clay", color );
				if(!clayText)
				{
					std::cout << "Failed to render text: " << TTF_GetError() << std::endl;
				}
				else
				{
					clayTexture = SDL_CreateTextureFromSurface(gRenderer, clayText);
					claySrcRct = {212,0,BUTTON_WIDTH - 20, BUTTON_HEIGHT - 20};
					clayDest = {212,0,BUTTON_WIDTH - 20, BUTTON_HEIGHT - 20};
				}

				limeText = TTF_RenderText_Solid( font, "Lime", color );
				if(!limeText)
				{
					std::cout << "Failed to render text: " << TTF_GetError() << std::endl;
				}
				else
				{
					limeTexture = SDL_CreateTextureFromSurface(gRenderer, limeText);
					limeSrcRct = {0,240,BUTTON_WIDTH - 20, BUTTON_HEIGHT - 20};
					limeDest = {0,240,BUTTON_WIDTH - 20, BUTTON_HEIGHT - 20};
				}

				ashText = TTF_RenderText_Solid( font, "Ash", color );
				if(!ashText)
				{
					std::cout << "Failed to render text: " << TTF_GetError() << std::endl;
				}
				else
				{
					ashTexture = SDL_CreateTextureFromSurface(gRenderer, ashText);
					ashSrcRct = {212,240,BUTTON_WIDTH - 20, BUTTON_HEIGHT - 20};
					ashDest = {212,240,BUTTON_WIDTH - 20, BUTTON_HEIGHT - 20};
				}

				undoText = TTF_RenderText_Solid( font, "Undo", color );
				if(!undoText)
				{
					std::cout << "Failed to render text: " << TTF_GetError() << std::endl;
				}
				else
				{
					undoTexture = SDL_CreateTextureFromSurface(gRenderer, undoText);
					undoSrcRct = {424,0,BUTTON_WIDTH - 20, BUTTON_HEIGHT - 20};
					undoDest = {424,0,BUTTON_WIDTH - 20, BUTTON_HEIGHT - 20};
				}

				redoText = TTF_RenderText_Solid( font, "Redo", color );
				if(!redoText)
				{
					std::cout << "Failed to render text: " << TTF_GetError() << std::endl;
				}
				else
				{
					redoTexture = SDL_CreateTextureFromSurface(gRenderer, redoText);
					redoSrcRct = {424,240,BUTTON_WIDTH - 20, BUTTON_HEIGHT - 20};
					redoDest = {424,240,BUTTON_WIDTH - 20, BUTTON_HEIGHT - 20};
				}
			}
		}
	}



	
}
    
Game::~Game()
{
}
    
void Game::run()
{
    m_gameIsRunning = true;
    while (m_gameIsRunning)
    {
        update();
    }
}

void Game::endGame()
{
	//Deallocate surface
	SDL_FreeSurface( gXOut );
	gXOut = NULL;

	TTF_CloseFont( font );
	TTF_Quit();

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

void Game::update()
{
   //Main loop flag
	bool quit = false;
	//Event handler
	SDL_Event e;
	//While application is running
	while( !quit )
	{
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
        }
		if(m_factoryTest)
		{
			m_bricks.push_back(factory->CreateLego());
			m_bricks.push_back(factory->CreateClay());
			m_bricks.push_back(factory->CreateLime());
			m_bricks.push_back(factory->CreateAsh());

			for(int i = 0; i < m_bricks.size(); i++)
			{
				m_bricks[i]->draw();
			}
			
			m_factoryTest = false;
		}
		
		//Apply the image
		SDL_BlitSurface( gXOut, NULL, gScreenSurface, NULL );
	
		//Update the surface
		//SDL_UpdateWindowSurface( gWindow );
		SDL_RenderCopy(gRenderer, legoTexture, &legoSrcRct, &legoDest);
		SDL_RenderCopy(gRenderer, clayTexture, &legoSrcRct, &clayDest);
		SDL_RenderCopy(gRenderer, limeTexture, &legoSrcRct, &limeDest);
		SDL_RenderCopy(gRenderer, ashTexture, &legoSrcRct, &ashDest);
		SDL_RenderCopy(gRenderer, undoTexture, &legoSrcRct, &undoDest);
		SDL_RenderCopy(gRenderer, redoTexture, &legoSrcRct, &redoDest);
		SDL_RenderPresent( gRenderer );
		
	}
	endGame();
}

