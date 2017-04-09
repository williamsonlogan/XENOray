#include <string>
#include <vector>
#include <iostream>

#include "../Player/Player.h"
#include "../quickcg.h"
using namespace QuickCG;

#define mapWidth 30
#define mapHeight 30

#define screenWidth 800
#define screenHeight 480

#define texWidth 24
#define texHeight 24

#define numTextures 2

#define numSprites 1

class Game
{
public:
	Game(int width = screenWidth, int height = screenHeight);

	int getWidth() const { return mScreenWidth; }
	int getHeight() const { return mScreenHeight; }

	void setWidth(const int width) { mScreenWidth = width; }
	void setHeight(const int height) { mScreenHeight = height; }

	void RunGame();
private:
	Player mPlayer;
	double mFrameTime;
	int mScreenWidth, mScreenHeight;
	std::vector<Uint32> mTextures[numTextures];
	Uint32 mBuffer[screenHeight][screenWidth];
	//1D Zbuffer
	double mZBuffer[screenWidth];
	//arrays used to sort the sprites
	int spriteOrder[numSprites];
	double spriteDistance[numSprites];

	//function used to sort the sprites
	void combSort(int* order, double* dist, int amount);

	void LoadTextures();
	void Render(int worldMap[][mapHeight]);
	void DrawSprites();

	void UpdateMovement(int worldMap[][mapHeight]);
	void UpdateRotation(float deltaMouse);
};
