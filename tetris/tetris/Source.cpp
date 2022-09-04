#include<iostream>
#include<Windows.h>
using namespace std;
/*#include <stdio.h>

#ifdef _UNICODE
#ifndef UNICODE
#define UNICODE
#endif
#endif*/

wstring tetromino[7];
int nFieldWidth = 12;
int nFieldHeight = 18;


int nScreenWidth = 80;   // Console Screen size X
int nScreenHeight = 30;  // Console Screen size Y

unsigned char* pField = nullptr;

int Rotate(int px, int py, int r) {
	switch (r % 4) {
	case 0: return py * 4 + px;         // 0 degrees
	case 1: return 12 + py - (px * 4);  // 90 degrees
	case 2: return 15 - (py * 4) - px;  // 180 degrees
	case 3: return 3 - py + (px * 4);   // 270 degrees
	}
	return 0;
}

bool DoesPieceFit(int nTetromino, int nRotation, int nPosX, int nPosY) {
	for (int px=0; px<4; px++)
		for (int py = 0; py < 4; py++) {
			// Get index into piece
			int pi = Rotate(px, py, nRotation);
			
			// Get index into field
			int fi = (nPosY + py) * nFieldWidth + (nPosX + px);
			if (nPosX + px >= 0 && nPosX + px < nFieldWidth) {
				if (nPosY + py >= 0 && nPosY + py < nFieldHeight) {
					if (tetromino[nTetromino][pi] == L'X' && pField && pField[fi] != 0)
						return false; // fail on first hit
				}
			}
		}


	return true;
}

int main() {
	//Create tetrominos
	tetromino[0].append(L"..X.");
	tetromino[0].append(L"..X.");
	tetromino[0].append(L"..X.");
	tetromino[0].append(L"..X.");

	tetromino[1].append(L"..X.");
	tetromino[1].append(L".XX.");
	tetromino[1].append(L".X..");
	tetromino[1].append(L"....");

	tetromino[2].append(L".X..");
	tetromino[2].append(L".XX.");
	tetromino[2].append(L"..X.");
	tetromino[2].append(L"....");

	tetromino[3].append(L"....");
	tetromino[3].append(L".XX.");
	tetromino[3].append(L".XX.");
	tetromino[3].append(L"....");

	tetromino[4].append(L"..X.");
	tetromino[4].append(L".XX.");
	tetromino[4].append(L"..X.");
	tetromino[4].append(L"....");

	tetromino[5].append(L"....");
	tetromino[5].append(L".XX.");
	tetromino[5].append(L"..X.");
	tetromino[5].append(L"..X.");

	tetromino[6].append(L"....");
	tetromino[6].append(L".XX.");
	tetromino[6].append(L".X..");
	tetromino[6].append(L".X..");

	pField = new unsigned char[nFieldWidth * nFieldHeight]; // Create play field
	for (int x = 0; x < nFieldWidth; x++) // Board Boundary
		for (int y = 0; y < nFieldHeight; y++)
			pField[y * nFieldWidth + x] = (x == 0 || x == nFieldWidth - 1 || y == nFieldHeight - 1) ? 9 : 0;


	// allow command-line as a screen buffer
	wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];
	for (int i = 0; i < nScreenWidth * nScreenHeight; i++) 
		screen[i] = L' ';
	// access handle to the console buffer and set it as the active screen buffer
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;


	bool bGameOver = false;

	// Game logic parameters
	int nCurrentPiece = 2;
	int nCurrentRotation = 0;
	int nCurrentX = nFieldWidth / 2;
	int nCurrentY = 0;
	
	bool bKey[4];
	bool bRotateHold = false;

	int nSpeed = 50000;
	int nSpeedCounter = 0;
	bool bForceDown = false;

	while (!bGameOver) {
		// Game timing--------------
		//this_thread::sleep_for(50); // Small Step = 1 Game Tick
		nSpeedCounter++;
		bForceDown = (nSpeedCounter == nSpeed);

		// Input--------------------
		for (int k = 0; k < 4; k++)
			bKey[k] = (0X8000 & GetAsyncKeyState((unsigned char)("\x27\x25\x28Z"[k]))) != 0;


		// Game logic---------------
		nCurrentX += (bKey[0] && DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX + 1, nCurrentY)) ? 1 : 0;
		nCurrentX -= (bKey[1] && DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX - 1, nCurrentY)) ? 1 : 0;
		nCurrentY += (bKey[2] && DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX, nCurrentY + 1)) ? 1 : 0;
		if (bKey[3]) {
			nCurrentRotation += (bRotateHold && DoesPieceFit(nCurrentPiece, nCurrentRotation + 1, nCurrentX, nCurrentY)) ? 1 : 0;
			bRotateHold = true;
		}
		else
			bRotateHold = false;

		if (bForceDown) {
			if (DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX, nCurrentY + 1))
				nCurrentY++; // It can, so do it!
			else {
				// Lock current piece in the field
				for (int px = 0; px < 4; px++)
					for (int py = 0; py < 4; py++)
						if (tetromino[nCurrentPiece][Rotate(px, py, nCurrentRotation)] == L'X')
							pField[(nCurrentY + py) * nFieldWidth + (nCurrentX + px)] = nCurrentPiece + 1;
				// Check have we for any lines

				//Choose next piece
				nCurrentX = nFieldWidth / 2;
				nCurrentY = 0;
				nCurrentPiece = rand() % 7;

				// if piece does not fit
				bGameOver = !DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX, nCurrentY);
			}
			nSpeedCounter = 0;
		}
		
		// Render output------------
		
		// Draw field
		for (int x = 0; x < nFieldWidth; x++)
			for (int y = 0; y < nFieldHeight; y++)
				screen[(y + 2) * nScreenWidth + (x + 2)] = L" ABCDEFG=#"[pField[y * nFieldWidth + x]];
		//Draw current piece
		for (int px = 0; px < 4; px++)
			for (int py = 0; py < 4; py++)
				if (tetromino[nCurrentPiece][Rotate(px, py, nCurrentRotation)] == L'X')
					screen[(nCurrentY + py + 2) * nScreenWidth + (nCurrentX + px + 2)] = nCurrentPiece + 65;

		// Display Frame(separate command to draw to the buffer using different dimensions for screen output)
		WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
	}

	

	return 0;
}