#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <array>
#include "Camera.h"
#include "Player.h"
#include <GL/freeglut.h>

#define BUTTON_DOWN 1
#define BUTTON_UP 0
/**
*Klasa odpowiedzialna za obsluge klawiatury
*/
class Keyboard
{
public:
	Keyboard() : keyState({ { 0 } })
	{

	}
	Keyboard(Camera *camera) : keyState({ { 0 } })
	{
		m_camera = camera;
	}
	Keyboard(Player *player) : keyState({ { 0 } })
	{
		m_player = player;
	}
	void SetCamera(Camera *camera)
	{
		m_camera = camera;
	}
	void KeyDown(unsigned char key);
	void KeyUp(unsigned char key);
	void ProcessKeyboard();
	void ProcessKeyboard(Player *player);

private:
	std::array<unsigned char,255> keyState;
	Camera *m_camera;
	Player *m_player;
};
#endif 